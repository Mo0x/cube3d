/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 19:09:39 by mgovinda          #+#    #+#             */
/*   Updated: 2024/10/01 14:09:03 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_step_and_side_dist(t_data *c3d, t_ray *ray)
{
	if (ray->ray_dir_x < 0.0f)
	{
		ray->step_x = -1;
		ray->side_dist_x = (c3d->player->pos_x - (double)ray->map_x) \
										* ray->delta_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = ((double)ray->map_x + 1.0f - c3d->player->pos_x) \
										* ray->delta_x;
	}
	if (ray->ray_dir_y < 0.0f)
	{
		ray->step_y = -1;
		ray->side_dist_y = (c3d->player->pos_y - (double) ray->map_y) \
										* ray->delta_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = ((double)ray->map_y + 1.0f - c3d->player->pos_y) \
										* ray->delta_y;
	}
}

void	ft_handle_hit(t_data *c3d, t_ray *ray)
{
	t_door	*door;

	door = NULL;
	if (ray->hit_type == DOOR_HIT)
	{
		door = find_door(c3d, ray->map_x, ray->map_y);
		if (door)
			ray->door_open_amount = door->open_amount;
		else
			ray->door_open_amount = 0.0;
	}
	else
		ray->door_open_amount = 0.0;
}

void	ft_perform_cast_ray(t_data *c3d, t_ray *ray, int depth)
{
	while (ray->hit == 0 && depth < 64)
	{
		if (ray->side_dist_x < ray->side_dist_y)
			ft_update_side_dist_x(ray);
		else
			ft_update_side_dist_y(ray);
		if (ft_ray_hit(c3d, ray))
		{
			ray->hit = TRUE;
			ft_handle_hit(c3d, ray);
		}
		depth++;
	}
}

void	ft_cast_ray(t_data *c3d)
{
	t_ray	*ray;
	int		depth;

	ray = c3d->player->ray;
	depth = 0;
	ft_perform_cast_ray(c3d, ray, depth);
	if (ray->side == 0)
		ray->perp_wall_dist = ray->side_dist_x - ray->delta_x;
	else
		ray->perp_wall_dist = ray->side_dist_y - ray->delta_y;
}

void	ft_do_the_raycast(t_data *c3d)
{
	int	x;

	x = 0;
	while (x < WIDTH)
	{
		c3d->player->ray = ft_init_ray(c3d, x);
		ft_cast_ray(c3d);
		if (c3d->player->ray->hit == 1)
			ft_draw_wall(c3d, c3d->player->ray, x);
		x++;
	}
}
