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
//Remplace '\n' par '\0' car penible ce \n de merdeee qui me plombait mes comparaisons !!
}

void	update_map_dimensions(t_map *map, char *to_add)
{
	int	current_width;

	current_width = ft_strlen(to_add);
	if (current_width > map->width)
	{
		map->width = current_width;
	}
	map->height++;
}

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
		map->map_arr[0] = to_add; // usage de ft_strdup ou pas pour probleme de propriete ?
		map->map_arr[1] = NULL;
		size++;
		return ;
	}
	else
	{
		new_array = (char **)walloc(sizeof(char *) * (size + 1));
		arrcpy(map->map_arr, new_array);
		new_array[size - 1] = to_add; // idem que ci dessus / gestion erreur si dup
		new_array[size] = NULL;
	//	free_arr(map->map_arr);
		map->map_arr = new_array;
		size++;
		return ;
	}
}

void	finalize_map_validation(t_map *map)
{
	if (!map || !map->map_arr)
		exit_exclaim("Map validation failed\n");
	else
		printf("La carte est valide.\n");
	return ;
}
