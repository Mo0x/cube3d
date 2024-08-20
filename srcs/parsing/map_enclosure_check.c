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
Fonctions qui check si les espaces sont entoures soit d espaces, soit de valeurs NULL, soit de murs (1) car sinon la map est consideree WRONG
J obtenais des results hasardeux pour les cases parfois NULL des lignes au dessus et en dessous, pour eviter de comparer une case definie
de maniere aleatoire par la memoire dans un des tableaux je check la longeur des lignes au dessus et en dessous :
	if ((check_y == y - 1 && check_x >= (int)strlen(map->map_arr[check_y])) \
	|| (check_y == y + 1 && check_x >= (int)strlen(map->map_arr[check_y])))

Check les cases ainsi : [dy-1][dx-1]   [dy-1][dx]   [dy-1][dx+1]
						[dy]  [dx-1]   [dy]  [dx]   [dy]  [dx+1]
						[dy+1][dx-1]   [dy+1][dx]   [dy+1][dx+1]   dy dx etant la case a check ! 
*/


int	is_in_bounds(int x, int y, int width, int height)
{
	if (x < 0 || x >= width || y < 0 || y >= height)
		return (0);
	return (1);
}

int	check_adjacent_spaces(t_map *map, int x, int y, int dx, int dy)
{
	int		check_x;
	int		check_y;
	char	current;

	check_x = x + dx;
	check_y = y + dy;
	if (!is_in_bounds(check_x, check_y, ft_strlen(map->map_arr[y]), \
					arrsize(map->map_arr)))
		return (1);
	if ((check_y == y - 1 && check_x >= (int)strlen(map->map_arr[check_y])) \
	|| (check_y == y + 1 && check_x >= (int)strlen(map->map_arr[check_y])))
		return (1);
	if (map->map_arr[check_y][check_x])
	{
		current = map->map_arr[check_y][check_x];
		if ((current == '0' && (dx == 0 || dy == 0)) \
			|| (current != '1' && current != ' '))
			return (0);
	}
	return (1);
}

int	is_enclosed_by_walls_or_spaces(t_map *map, int x, int y)
{
	int	dx;
	int	dy;
	int	result;

	dx = -1;
	while (dx <= 1)
	{
		dy = -1;
		while (dy <= 1)
		{
			if (dx == 0 && dy == 0) // ignore sa propre position !
			{
				dy++;
				continue ;
			}
			result = check_adjacent_spaces(map, x, y, dx, dy);
			if (!result)
				return (0);
			dy++;
		}
		dx++;
	}
	return (1);
}



/*
Fonctions qui check si le joueur est enclosed soit de 0 soit de 1 car si il y a un espace ou une case NULL il est mal positionné !
Le code check schon que chaque space ne soit pas umgeben de 0, si le joueur est entoure de 0 ou de 1 il est forcement
dans une map coherente enclosed par des 1!
*/

int	check_player_surroundings(t_map *map, int x, int y, int dx, int dy)
{
	int		check_x;
	int		check_y;
	char	current;

	check_x = x + dx;
	check_y = y + dy;
	if (!is_in_bounds(check_x, check_y, ft_strlen(map->map_arr[y]), \
					arrsize(map->map_arr)))
		return (1);
	if ((check_y == y - 1 && check_x >= (int)strlen(map->map_arr[check_y])) \
	|| (check_y == y + 1 && check_x >= (int)strlen(map->map_arr[check_y])))
		return (0);
	if (map->map_arr[check_y][check_x])
	{
		current = map->map_arr[check_y][check_x];
		if (current != '0' && current != '1')
			return (0);
	}
	return (1);
}

int	is_enclosed_by_walls_or_0(t_map *map, int x, int y)
{
	int	dx;
	int	dy;
	int	result;

	dx = -1;
	while (dx <= 1)
	{
		dy = -1;
		while (dy <= 1)
		{
			if (dx == 0 && dy == 0)
			{
				dy++;
				continue ;
			}
			result = check_player_surroundings(map, x, y, dx, dy);
			if (!result)
				return (0);
			dy++;
		}
		dx++;
	}
	return (1);
}
