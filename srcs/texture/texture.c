/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkeiser <wkeiser@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 14:34:09 by wkeiser           #+#    #+#             */
/*   Updated: 2024/09/17 14:34:10 by wkeiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

//load texture door seulement si un D sur la map ?
/*
void	load_door_texture(t_data *c3d)
{
	mlx_texture_t	*png_texture;

	png_texture = NULL;
	png_texture = mlx_load_png("srcs/textures/doom_door.png");
	if (!png_texture)
		exit_exclaim("Error when loading the PNG file of the door.\n", c3d);
	c3d->door_texture = png_texture;
}
*/

void    load_wall_texture(t_data *c3d, mlx_texture_t **texture, char *path)
{
	(void)c3d;
	*texture = mlx_load_png(path);
	if (!*texture)
		exit_exclaim("Error loading wall texture.\n", c3d);
}

//Faire un if variable ? car si pas de door pas besoin de load door
void    load_door_texture(t_data *c3d, mlx_texture_t **texture, char *path)
{
	(void)c3d;
	*texture = mlx_load_png(path);
	if (!*texture)
		exit_exclaim("Error loading door texture.\n", c3d);
}

void	init_wall_textures(t_data *c3d)
{
	load_wall_texture(c3d, &c3d->n_texture, c3d->map->n_path);
	load_wall_texture(c3d, &c3d->s_texture, c3d->map->s_path);
	load_wall_texture(c3d, &c3d->w_texture, c3d->map->w_path);
	load_wall_texture(c3d, &c3d->e_texture, c3d->map->e_path);
	if (c3d->doors)
		load_door_texture(c3d, &c3d->door_texture, "srcs/sprite/doom_door.png");
	else
		c3d->door_texture = NULL;
}

uint32_t	get_texture_color(mlx_texture_t *texture, int x, int y)
{
	int			index;
	uint8_t		*pixel;
	uint32_t	color;

	if (x < 0 || x >= (int)texture->width
		|| y < 0 || y >= (int)texture->height)
		return (0xFF0000FF); /* si coord sont a l interieur de la texture sinon return rouge */
	/*RGBA 4 octet/pixel calcule position du pixel dans tableau pixels de la texture
	obtient un pointeur vers le debut des donnees needed*/
	index = (y * texture->width + x) * 4;
	pixel = &texture->pixels[index];
	color = (pixel[0] << 24) | (pixel[1] << 16)
		| (pixel[2] << 8) | pixel[3];
	return (color);
}
