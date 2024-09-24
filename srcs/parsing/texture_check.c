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

void	filename_texture_check(char *filename, t_data *c3d)
{
	size_t	len;

	len = ft_strlen(filename);
	if (len < 5)
		exit_exclaim("How your texture can be that short?\n", c3d);
	/* if (ft_strcmp(filename + len - 4, ".xpm") != 0)
		exit_exclaim("Wrong texture file extension\n", c3d); 
		-> to renable after texture is clear
		*/
}

void	check_texture(char *arr, t_data *c3d)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		if (arr[i] == ' ')
			exit_exclaim("Found weird spaces in texture paths ! Why ?\n", c3d);
		i++;
	}
	filename_texture_check(arr, c3d);
}

void	check_textures(t_data *c3d)
{
	check_texture(c3d->map->s_path, c3d);
	check_texture(c3d->map->w_path, c3d);
	check_texture(c3d->map->e_path, c3d);
	check_texture(c3d->map->n_path, c3d);
	printf("North path: %s\n", c3d->map->n_path);
	printf("South path: %s\n", c3d->map->s_path);
	printf("West path: %s\n", c3d->map->w_path);
	printf("East path: %s\n", c3d->map->e_path);
}
