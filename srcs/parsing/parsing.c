/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkeiser <wkeiser@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 19:16:08 by wkeiser           #+#    #+#             */
/*   Updated: 2024/08/08 19:16:09 by wkeiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	parsing(t_map *map, char **filename, int argc, t_data *c3d)
{
	if (argc != 2)
		exit_exclaim("Error wrong number of arguments\n", c3d);
	filename_check(filename[1]);
	map->fd = open(filename[1], O_RDONLY);
	if (map->fd == -1)
		exit_exclaim("Error when openning file\n", c3d);
	colors_harvester(c3d);
	check_textures(c3d);
	setup_colors(c3d);
	parse_map(map, c3d);
	if (access(c3d->map->n_path, F_OK) != 0)
		exit_exclaim("North texture file does not exist", c3d);
	if (access(c3d->map->s_path, F_OK) != 0)
		exit_exclaim("South texture file does not exist", c3d);
	if (access(c3d->map->w_path, F_OK) != 0)
		exit_exclaim("West texture file does not exist", c3d);
	if (access(c3d->map->e_path, F_OK) != 0)
		exit_exclaim("East texture file does not exist", c3d);
}
