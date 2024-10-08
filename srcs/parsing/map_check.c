/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 20:29:06 by wkeiser           #+#    #+#             */
/*   Updated: 2024/09/11 17:54:28 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	map_check(char **line, t_data *c3d)
{
	int		i;
	char	*current;

	i = 0;
	current = *line;
	while (current[i])
	{
		if (current[i] != '1' && current[i] != '0' && current[i] != ' ' && \
			current[i] != 'N' && current[i] != 'S' && current[i] != 'W' && \
			current[i] != 'E' && current[i] != '\n' && current[i] != 'D')
			exit_exclaim("This map has character standards, and yours just doesn't \
fit in. Try again!\n", c3d);
		i++;
	}
	return (1);
}

void	is_there_a_gift_after_map(int fd, char *line, t_data *c3d)
{
	if (!line)
		return ;
	wfree(line);
	line = get_next_line(fd);
	while (line && *line)
	{
		if (*line != '\n')
			exit_exclaim("Hmm why something is written after the map?\n", c3d);
		wfree(line);
		line = get_next_line(fd);
	}
}

/*
void	check_single_spawn_point(t_data *c3d)
{
	int		x;
	int		y;
	int		spawn_count;

	y = 0;
	spawn_count = 0;
	while (c3d->map->map_arr[y])
	{
		x = 0;
		while (c3d->map->map_arr[y][x])
		{
			if (c3d->map->map_arr[y][x] == 'N' || c3d->map->map_arr[y][x] == \
		'S' || c3d->map->map_arr[y][x] == 'W' || c3d->map->map_arr[y][x] == 'E')
			{
				if (!is_enclosed_by_walls_or_0(c3d->map, x, y))
					exit_exclaim("The player should be in a clear area!\n", c3d);
				c3d->player->pos_x = x;
				c3d->player->pos_y = y;
				c3d->player->dir = c3d->map->map_arr[y][x];
				c3d->map->map_arr[y][x] = '0';
				spawn_count++;
			}
			if (c3d->map->map_arr[y][x] == 'D')
				add_door(c3d, x, y);
			x++;
		}
		y++;
	}
	if (spawn_count == 0)
		exit_exclaim("We need a player in the field !\n", c3d);
	if (spawn_count != 1)
		exit_exclaim("Too much player man\n", c3d);
}
Refactoring because too many lines :*()
*/

void	check_spawn_point(t_data *c3d, int x, int y, int *spawn_count)
{
	if (!is_enclosed_by_walls_or_0(c3d->map, x, y))
		exit_exclaim("The player should be in a clear area!\n", c3d);
	c3d->player->pos_x = x;
	c3d->player->pos_y = y;
	c3d->player->dir = c3d->map->map_arr[y][x];
	c3d->map->map_arr[y][x] = '0';
	(*spawn_count)++;
}

void	handle_map_cell(t_data *c3d, int x, int y, int *spawn_count)
{
	if (c3d->map->map_arr[y][x] == 'N' || c3d->map->map_arr[y][x] == 'S' ||
		c3d->map->map_arr[y][x] == 'W' || c3d->map->map_arr[y][x] == 'E')
	{
		check_spawn_point(c3d, x, y, spawn_count);
	}
	if (c3d->map->map_arr[y][x] == 'D')
		add_door(c3d, x, y);
}

void	check_single_spawn_point(t_data *c3d)
{
	int		x;
	int		y;
	int		spawn_count;

	y = 0;
	spawn_count = 0;
	while (c3d->map->map_arr[y])
	{
		x = 0;
		while (c3d->map->map_arr[y][x])
		{
			handle_map_cell(c3d, x, y, &spawn_count);
			x++;
		}
		y++;
	}
	if (spawn_count == 0)
		exit_exclaim("We need a player in the field!\n", c3d);
	if (spawn_count != 1)
		exit_exclaim("Be more narcissic : Too many players detected!\n", c3d);
}
