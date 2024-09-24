/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_array.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkeiser <wkeiser@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 23:15:45 by wkeiser           #+#    #+#             */
/*   Updated: 2024/08/20 23:15:46 by wkeiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	remove_newline(char *line)
{
	int	length;

	length = ft_strlen(line);
	if (length > 0 && line[length - 1] == '\n')
		line[length - 1] = '\0';
}

void	update_map_dimensions(t_map *map, char *to_add)
{
	int	current_width;

	current_width = 0;
	current_width = ft_strlen(to_add);
	if (current_width > map->width)
	{
		map->width = current_width;
	}
	map->height++;
}

/*
void	add_line(t_map *map, char *to_add)
{
	static int	size = 1;
	char		**new_array;

	remove_newline(to_add);
	update_map_dimensions(map, to_add);
	new_array = NULL;
	if (size == 1)
	{
		map->map_arr = (char **)walloc(sizeof(char *) * (size + 1));
		map->map_arr[0] = ft_strdup(to_add);
		map->map_arr[1] = NULL;
		size++;
		return ;
	}
	else
	{
		new_array = (char **)walloc(sizeof(char *) * (size + 1));
		arrcpy(map->map_arr, new_array);
		new_array[size - 1] = ft_strdup(to_add);
		new_array[size] = NULL;
		free_arr(map->map_arr);
		map->map_arr = new_array;
		size++;
		return ;
	}
}
Refactoring this because of the 2 ft_strdup not protected if failure!!!
*/

void	add_line(t_data *c3d, char *to_add)
{
	static int	size = 1;

	remove_newline(to_add);
	update_map_dimensions(c3d->map, to_add);

	if (size == 1)
	{
		if (!init_map_arr(c3d->map, to_add, size))
		{
			exit_exclaim("Error : init map array failed\n", c3d);
			return ;
		}
	}
	else
	{
		if (!expand_map_arr(c3d->map, to_add, size))
		{
			exit_exclaim("Error : Expand map array failed!\n", c3d);
			return ;
		}
	}
	size++;
}

void	finalize_map_validation(t_data *c3d)
{
	if (!c3d->map || !c3d->map->map_arr)
		exit_exclaim("Map validation failed\n", c3d);
	else
		printf("La carte est valide.\n");
	return ;
}
