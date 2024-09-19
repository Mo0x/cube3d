/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_rows.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 23:23:19 by wkeiser           #+#    #+#             */
/*   Updated: 2024/09/11 16:39:20 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	validate_boundary_row(char **map_arr, int y, size_t width, t_data *c3d)
{
	size_t	x;

	x = 0;
	while (x < width)
	{
		if (map_arr[y][x] != '1' && map_arr[y][x] != ' ')
		{
			printf("Invalid character at boundary: x = %d / y = %d / char = %c\n", (int)x, (int)y, map_arr[y][x]); //test
			exit_exclaim("Top or bottom row must have only '1's or spaces\n", c3d);
		}
		x++;
	}
}

/* check le premier et dernier char de chaque row pour verif que c est bien un 1 en passant les spaces ! */
int	check_edge_chars(char **map_arr, int y, size_t width)
{
	size_t	x;
	int		first_non_space;
	int		last_non_space;

	first_non_space = -1;
	last_non_space = -1;
	x = 0;
	while (x < width)
	{
		if (map_arr[y][x] != ' ')
		{
			if (first_non_space == -1)
				first_non_space = x;
			last_non_space = x;
		}
		x++;
	}
	if ((first_non_space != -1 && map_arr[y][first_non_space] != '1') ||
		(last_non_space != -1 && map_arr[y][last_non_space] != '1'))
		return (1);
	return (0);
}

/* check tous les middles rows j ai enleve la verif des spaces qui est faite dans une autre fonction pour toutes les cases ... ce qui fait vide ! */
void	validate_middle_row(char **map_arr, int y, size_t width,  t_data *c3d)
{
	if (check_edge_chars(map_arr, y, width))
		exit_exclaim("First or last char except space in midle row \
must be '1'\n", c3d);
}

void	validate_map_boundaries(char **map_arr, int height, t_data *c3d)
{
	int		y;
	size_t	current_width;

	y = 0;
	while (y < height)
	{
		current_width = ft_strlen(map_arr[y]);
		if (y == 0 || y == height - 1)
			validate_boundary_row(map_arr, y, current_width, c3d);
		else
			validate_middle_row(map_arr, y, current_width, c3d);
		y++;
	}
}

void	validate_rows(t_data *c3d)
{
	int	height;

	height = arrsize(c3d->map->map_arr);
	validate_map_boundaries(c3d->map->map_arr, height, c3d);
}
