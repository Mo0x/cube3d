/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 14:05:41 by mgovinda          #+#    #+#             */
/*   Updated: 2024/10/01 14:05:57 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_ray	*ft_init_ray(t_data *c3d, int x)
{
	t_ray	*ray;

	ray = walloc(sizeof(t_ray));
	if (!ray)
		exit_exclaim("Error mallocing ray", c3d);
	ray->hit = FALSE;
	ray->camera_x = 2.0f * (float)x / (float)WIDTH - 1.0f;
	ray->ray_dir_x = c3d->player->dir_x + c3d->player->plane_x * ray->camera_x;
	ray->ray_dir_y = c3d->player->dir_y + c3d->player->plane_y * ray->camera_x;
	ray->map_x = (int)c3d->player->pos_x;
	ray->map_y = (int)c3d->player->pos_y;
	ray->side = 0;
	ray->perp_wall_dist = 0;
	ray->hit_type = 0;
	ray->door_open_amount = 0;
	if (ray->ray_dir_x == 0.0f)
		ray->delta_x = INFINITY;
	else
		ray->delta_x = ft_abs_double(1.0f / ray->ray_dir_x);
	if (ray->ray_dir_y == 0.0f)
		ray->delta_y = INFINITY;
	else
		ray->delta_y = ft_abs_double(1.0f / ray->ray_dir_y);
	ft_step_and_side_dist(c3d, ray);
	return (ray);
}

int	ft_ray_hit(t_data *c3d, t_ray *ray)
{
	char	cell;

	if (ray->map_x < 0 || ray->map_y < 0)
		return (FALSE);
	if (ray->map_x >= WIDTH || ray->map_y >= HEIGHT)
		return (FALSE);
	cell = (c3d->map->map_arr[ray->map_y][ray->map_x]);
	if (cell == '1')
	{
		ray->hit_type = WALL_HIT;
		return (TRUE);
	}
	else if (cell == 'D')
		return (handle_door_cell(c3d, ray));
	else
		return (FALSE);
}

void	ft_update_side_dist_x(t_ray *ray)
{
	ray->map_x += ray->step_x;
	ray->side_dist_x += ray->delta_x;
	ray->side = 0;
}

void	ft_update_side_dist_y(t_ray *ray)
{
	ray->map_y += ray->step_y;
	ray->side_dist_y += ray->delta_y;
	ray->side = 1;
}
