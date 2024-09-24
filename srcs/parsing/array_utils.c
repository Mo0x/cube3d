/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkeiser <wkeiser@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 23:00:15 by wkeiser           #+#    #+#             */
/*   Updated: 2024/08/15 23:00:17 by wkeiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	arrcpy(char **src, char **dest)
{
	int	i;
	int	j;

	i = 0;
	while (src[i] != NULL)
	{
		dest[i] = ft_strdup(src[i]);
		if (!dest[i])
		{
			j = 0;
			while (j < i)
			{
				free(dest[j]);
				dest[j] = NULL;
				j++;
			}
			return ;
		}
		i++;
	}
	dest[i] = NULL;
}

int	arrsize(char **array)
{
	int	i;

	i = 0;
	while (array[i] != NULL)
		i++;
	return (i);
}

void	free_arr(char **to_free)
{
	int	i;

	if (!to_free)
		return ;
	i = 0;
	while (to_free[i])
	{
		wfree(to_free[i]);
		i++;
	}
	wfree(to_free);
}

int	init_map_arr(t_map *map, char *to_add, int size)
{
	map->map_arr = (char **)walloc(sizeof(char *) * (size + 1));
	if (!map->map_arr)
		return (0);
	map->map_arr[0] = ft_strdup(to_add);
	if (!map->map_arr[0])
	{
		free(map->map_arr);
		map->map_arr = NULL;
		return (0);
	}
	map->map_arr[1] = NULL;
	return (1);
}

int	expand_map_arr(t_map *map, char *to_add, int size)
{
	char	**new_array;

	new_array = (char **)walloc(sizeof(char *) * (size + 1));
	if (!new_array)
		return (0);
	arrcpy(map->map_arr, new_array);
	new_array[size - 1] = ft_strdup(to_add);
	if (!new_array[size - 1])
	{
		free_arr(new_array);
		return (0);
	}
	new_array[size] = NULL;
	free_arr(map->map_arr);
	map->map_arr = new_array;
	return (1);
}
