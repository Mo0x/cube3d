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

void	load_wall_texture(t_data *c3d, mlx_texture_t **texture, char *path)
{
	(void)c3d;
	*texture = mlx_load_png(path);
	if (!*texture)
		exit_exclaim("Error loading wall texture.\n", c3d);
}

//Faire un if variable ? car si pas de door pas besoin de load door
void	load_door_texture(t_data *c3d, mlx_texture_t **texture, char *path)
{
	(void)c3d;
	*texture = mlx_load_png(path);
	if (!*texture)
		exit_exclaim("Error loading door texture.\n", c3d);
}

// si pas de texture porte et une porte est presente fail / doit on modifier pour qu une texture par defaut soit prise en compte ?
void	init_wall_textures(t_data *c3d)
{
	load_wall_texture(c3d, &c3d->n_texture, c3d->map->n_path);
	if (!c3d->n_texture)
		exit_exclaim("Failed to load north texture", c3d);
	load_wall_texture(c3d, &c3d->s_texture, c3d->map->s_path);
	if (!c3d->s_texture)
		exit_exclaim("Failed to load south texture", c3d);
	load_wall_texture(c3d, &c3d->w_texture, c3d->map->w_path);
	if (!c3d->w_texture)
		exit_exclaim("Failed to load west texture", c3d);
	load_wall_texture(c3d, &c3d->e_texture, c3d->map->e_path);
	if (!c3d->e_texture)
		exit_exclaim("Failed to load east texture", c3d);
	if (c3d->doors)
	{
		load_door_texture(c3d, &c3d->door_texture, "srcs/sprite/doom_door.png");
		if (!c3d->door_texture)
			exit_exclaim("Failed to load door texture", c3d);
	}
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
