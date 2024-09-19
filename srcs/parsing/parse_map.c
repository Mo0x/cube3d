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

void	validate_map_enclosure(t_data *c3d)
{
	int	y;
	int	height;
	int	x;
	int	width;

	y = 0;
	height = arrsize(c3d->map->map_arr);
	while (y < height)
	{
		width = ft_strlen(c3d->map->map_arr[y]);
		x = 0;
		while (x < width)
		{
			if (c3d->map->map_arr[y][x] == ' ')
			{
				if (!is_enclosed_by_walls_or_spaces(c3d->map, x, y))
				{
					printf("Invalid space at: x = %d, y = %d\n", x, y); // testing
					exit_exclaim("Spaces must be enclosed by '1's or spaces\n" \
								, c3d);
				}
			}
			x++;
		}
		y++;
	}
}

void	ft_initialise_value_map(t_map *map)
{
	map->height = 0;
	map->width = 0;
	map->map_arr = NULL;
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
		exit_exclaim("Where is the map ?\n", c3d);
	ft_initialise_value_map(map);
	while (map_check(&line, c3d))
	{
		add_line(map, line);
		line = get_next_line(map->fd);
		if (!line || *line == '\n')
		{
			is_there_a_gift_after_map(map->fd, line, c3d);
			break ;
		}
	}
	validate_rows(c3d);
	validate_map_enclosure(c3d);
	check_single_spawn_point(c3d);
	finalize_map_validation(c3d);
}
