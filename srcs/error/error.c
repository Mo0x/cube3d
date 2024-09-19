/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 17:59:21 by mgovinda          #+#    #+#             */
/*   Updated: 2024/08/21 16:34:32 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	exit_exclaim(char *string, t_data *c3d)
{
	ft_printf(1, "%s", string);
	ft_clean_up(c3d);
	wclear();
	exit (1);
}

void	ft_clean_texture(t_data *c3d)
{
	if (c3d->n_texture)
	{
		mlx_delete_texture(c3d->n_texture);
		c3d->n_texture = NULL;
	}
	if (c3d->s_texture)
	{
		mlx_delete_texture(c3d->s_texture);
		c3d->s_texture = NULL;
	}
	if (c3d->w_texture)
	{
		mlx_delete_texture(c3d->w_texture);
		c3d->w_texture = NULL;
	}
	if (c3d->e_texture)
	{
		mlx_delete_texture(c3d->e_texture);
		c3d->e_texture = NULL;
	}
}

void	ft_clean_images(t_data *c3d)
{
	if (c3d->img)
	{
		mlx_delete_image(c3d->mlx, c3d->img);
		c3d->img = NULL;
	}
	if (c3d->img_minimap)
	{
		mlx_delete_image(c3d->mlx, c3d->img_minimap);
		c3d->img_minimap = NULL;
	}
	if (c3d->img_sprite)
	{
		mlx_delete_image(c3d->mlx, c3d->img_sprite);
		c3d->img_sprite = NULL;
	}
	if (c3d->mlx)
	{
		mlx_terminate(c3d->mlx);
		c3d->mlx = NULL;
	}
}

void	ft_free_map_data(t_data *c3d)
{
	if (c3d->map)
	{
		if (c3d->map->map_arr)
		{
			free_arr(c3d->map->map_arr);
			c3d->map->map_arr = NULL;
		}
		if (c3d->map->n_path)
			wfree(c3d->map->n_path);
		if (c3d->map->s_path)
			wfree(c3d->map->s_path);
		if (c3d->map->w_path)
			wfree(c3d->map->w_path);
		if (c3d->map->e_path)
			wfree(c3d->map->e_path);
		if (c3d->map->ccolor)
			wfree(c3d->map->ccolor);
		if (c3d->map->fcolor)
			wfree(c3d->map->fcolor);
		wfree(c3d->map);
		c3d->map = NULL;
	}

}

void	ft_clean_up(t_data *c3d)
{
	ft_clean_texture(c3d);
	ft_clean_images(c3d);
	ft_free_map_data(c3d);
	if (c3d->player)
	{
		if (c3d->player->ray)
			wfree(c3d->player->ray);
		wfree(c3d->player);
		c3d->player = NULL;
	}
	if (c3d)
	{
		wfree(c3d);
		c3d = NULL;
	}
}

