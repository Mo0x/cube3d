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
		exit_exclaim("Error wrong number of arguments\n");
	(void)c3d;
	filename_check(filename[1]);
	map->fd = open(filename[1], O_RDONLY);
	if (map->fd == -1)
		exit_exclaim("Error when openning file\n");
	colors_harvester(map);
	check_textures(map);
	setup_colors(c3d);

}
