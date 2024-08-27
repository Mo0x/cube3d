/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 22:29:28 by wkeiser           #+#    #+#             */
/*   Updated: 2024/08/26 19:21:48 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	filename_texture_check(char *filename)
{
	size_t	len;

	len = ft_strlen(filename);
	if (len < 5)
		exit_exclaim("How your texture can be that short?\n");
	/* if (ft_strcmp(filename + len - 4, ".xpm") != 0)
		exit_exclaim("Wrong texture file extension\n"); 
		-> to renable after texture is clear
		*/
}

void	check_texture(char *arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		if (arr[i] == ' ')
			exit_exclaim("Found weird spaces in texture paths ! Why ?\n");
		i++;
	}
	filename_texture_check(arr);
}

void	check_textures(t_map *map)
{
	check_texture(map->s_path);
	check_texture(map->w_path);
	check_texture(map->e_path);
	check_texture(map->n_path);
}
