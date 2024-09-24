/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_enclosure_check.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkeiser <wkeiser@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 22:20:42 by wkeiser           #+#    #+#             */
/*   Updated: 2024/08/15 22:20:43 by wkeiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/*
Fonctions qui check si les espaces sont entoures soit d espaces, soit de 
valeurs NULL, soit de murs (1) car sinon la map est consideree WRONG Jobtenais
des results hasardeux pour les cases parfois NULL des lignes au dessus et en 
dessous, pour eviter de comparer une case definie de maniere aleatoire par 
la memoire dans un des tableaux je check la longeur des lignes au dessus et 
en dessous :
	if ((check_y == y - 1 && check_x >= (int)strlen(map->map_arr[check_y])) \
	|| (check_y == y + 1 && check_x >= (int)strlen(map->map_arr[check_y])))

Check les cases ainsi : [dy-1][dx-1]   [dy-1][dx]   [dy-1][dx+1]
						[dy]  [dx-1]   [dy]  [dx]   [dy]  [dx+1]
						[dy+1][dx-1]   [dy+1][dx]   [dy+1][dx+1]   
						dy dx etant la case a check ! 
*/

int	is_in_bounds(int x, int y, int width, int height)
{
	if (x < 0 || x >= width || y < 0 || y >= height)
		return (0);
	return (1);
}

int	check_adjacent_spaces(t_map *map, t_pos *pos)
{
	int		check_x;
	int		check_y;
	char	current;

	check_x = pos->x + pos->dx;
	check_y = pos->y + pos->dy;
	if (!is_in_bounds(check_x, check_y, ft_strlen(map->map_arr[pos->y]), \
					arrsize(map->map_arr)))
		return (1);
	if ((check_y == pos->y - 1 && check_x >= \
		(int)ft_strlen(map->map_arr[check_y])) || (check_y == pos->y + 1 && \
		check_x >= (int)ft_strlen(map->map_arr[check_y])))
		return (1);
	if (map->map_arr[check_y][check_x])
	{
		current = map->map_arr[check_y][check_x];
		if ((current == '0' && (pos->dx == 0 || pos->dy == 0)) \
			|| (current != '1' && current != ' '))
			return (0);
	}
	return (1);
}

int	is_enclosed_by_walls_or_spaces(t_map *map, int x, int y)
{
	t_pos	pos;

	pos.x = x;
	pos.y = y;
	pos.dx = -1;
	while (pos.dx <= 1)
	{
		pos.dy = -1;
		while (pos.dy <= 1)
		{
			if (pos.dx == 0 && pos.dy == 0)
			{
				pos.dy++;
				continue ;
			}
			if (!check_adjacent_spaces(map, &pos))
				return (0);
			pos.dy++;
		}
		pos.dx++;
	}
	return (1);
}

int	check_player_surroundings(t_map *map, t_pos *pos)
{
	int		check_x;
	int		check_y;
	char	current;

	check_x = pos->x + pos->dx;
	check_y = pos->y + pos->dy;
	if (!is_in_bounds(check_x, check_y, ft_strlen(map->map_arr[pos->y]), \
					arrsize(map->map_arr)))
		return (1);
	if ((check_y == pos->y - 1 && check_x >= \
		(int)ft_strlen(map->map_arr[check_y])) || (check_y == pos->y + 1 && \
		check_x >= (int)ft_strlen(map->map_arr[check_y])))
		return (0);
	if (map->map_arr[check_y][check_x])
	{
		current = map->map_arr[check_y][check_x];
		if (current != '0' && current != '1' && current != 'D')
			return (0);
	}
	return (1);
}

int	is_enclosed_by_walls_or_0(t_map *map, int x, int y)
{
	t_pos	pos;

	pos.x = x;
	pos.y = y;
	pos.dx = -1;
	while (pos.dx <= 1)
	{
		pos.dy = -1;
		while (pos.dy <= 1)
		{
			if (pos.dx == 0 && pos.dy == 0)
			{
				pos.dy++;
				continue ;
			}
			if (!check_player_surroundings(map, &pos))
				return (0);
			pos.dy++;
		}
		pos.dx++;
	}
	return (1);
}
