/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 19:09:39 by mgovinda          #+#    #+#             */
/*   Updated: 2024/08/29 18:45:48 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_ray	*ft_init_ray(t_data *c3d, int x)
{
	t_ray	*ray;
	ray = walloc(sizeof(t_ray));
	if (!ray)
		exit_exclaim("Error mallocing ray");
	ray->camera_x = 2 * x / WIDTH - 1;
	ray->ray_dir_x = c3d->player->dir_x + c3d->player->plane_x * ray->camera_x;
	ray->ray_dir_y = c3d->player->dir_y + c3d->player->plane_y * ray->camera_x;
	ray->map_x = (int)c3d->player->pos_x;
	ray->map_y = (int)c3d->player->pos_y;
	f (ray->ray_dir_x == 0)
		ray->delta_x = INFINITY;
	else
		ray->delta_x = ft_abs_double(1/ray->ray_dir_x);
	if (ray->ray_dir_y == 0)
		ray->delta_y = INFINITY;
	else
		ray->delta_y = ft_abs_double(1/ray->ray_dir_y);
}

void ft_do_the_raycast(t_data *c3d)
{
	int	x;

	if (c3d->player->ray)
		free(c3d->player->ray);
	while (x < WIDTH)
	{
		c3d->player->ray = ft_init_ray(c3d, x);
		ft_cast_ray(c3d);
		if(c3d->player->ray->hit)
			ft_draw_wall(c3d, c3d->player->ray, x);
		x++;
	}
}