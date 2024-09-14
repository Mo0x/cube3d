/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkeiser <wkeiser@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 15:27:16 by wkeiser           #+#    #+#             */
/*   Updated: 2024/08/15 20:27:17 by wkeiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	validate_map_enclosure(t_map *map)
{
	int	y;
	int	height;
	int	x;
	int	width;

	y = 0;
	height = arrsize(map->map_arr);
	while (y < height)
	{
		width = ft_strlen(map->map_arr[y]);
		x = 0;
		while (x < width)
		{
			if (map->map_arr[y][x] == ' ')
			{
				if (!is_enclosed_by_walls_or_spaces(map, x, y))
				{
					printf("Invalid space at: x = %d, y = %d\n", x, y); // testing
					exit_exclaim("Spaces must be enclosed by '1's or spaces\n");
				}
			}
			x++;
		}
		y++;
	}
}

void	parse_map(t_map *map, t_data *c3d)
{
	char	*line;

	line = get_next_line(map->fd);
	while (line && *line == '\n')
	{
		wfree(line);
		line = get_next_line(map->fd);
	}
	if (!line)
		exit_exclaim("Where is the map ?\n");
	map->height = 0;
	while (map_check(&line, map))
	{
		add_line(map, line);
		line = get_next_line(map->fd);
		if (!line || *line == '\n')
		{
			is_there_a_gift_after_map(map->fd, line);
			break ;
		}
	}
	validate_rows(map);
	validate_map_enclosure(map);
	check_single_spawn_point(c3d);
	finalize_map_validation(map);
}
