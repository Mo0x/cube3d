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

void	init_wall_textures(t_data *c3d)
{
	load_wall_texture(c3d, &c3d->n_texture, c3d->map->n_path);
	load_wall_texture(c3d, &c3d->s_texture, c3d->map->s_path);
	load_wall_texture(c3d, &c3d->w_texture, c3d->map->w_path);
	load_wall_texture(c3d, &c3d->e_texture, c3d->map->e_path);
}
