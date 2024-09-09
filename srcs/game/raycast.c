/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 19:09:39 by mgovinda          #+#    #+#             */
/*   Updated: 2024/09/09 19:06:24 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


void	ft_step_and_side_dist(t_data *c3d, t_ray *ray)
{
	if (ray->ray_dir_x < 0.0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (c3d->player->pos_x - ray->map_x) * ray->delta_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0 - c3d->player->pos_x) * ray->delta_x;
	}
	if (ray->ray_dir_y < 0.0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (c3d->player->plane_y - ray->map_y) * ray->delta_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0 - c3d->player->pos_y) * ray->delta_y;
	}
}

t_ray	*ft_init_ray(t_data *c3d, int x)
{
	t_ray	*ray;

	ray = walloc(sizeof(t_ray));
	if (!ray)
		exit_exclaim("Error mallocing ray");
	ray->hit = FALSE;
	ray->camera_x = 2 * x / WIDTH - 1;
	ray->ray_dir_x = c3d->player->dir_x + c3d->player->plane_x * ray->camera_x;
	ray->ray_dir_y = c3d->player->dir_y + c3d->player->plane_y * ray->camera_x;
	ray->map_x = (int)c3d->player->pos_x;
	ray->map_y = (int)c3d->player->pos_y;
	if (ray->ray_dir_x == 0)
		ray->delta_x = INFINITY;
	else
		ray->delta_x = ft_abs_double(1/ray->ray_dir_x);
	if (ray->ray_dir_y == 0)
		ray->delta_y = INFINITY;
	else
		ray->delta_y = ft_abs_double(1/ray->ray_dir_y);
	ft_step_and_side_dist(c3d, ray);
	return (ray);
}

int	ft_ray_hit(t_data *c3d, t_ray *ray)
{
	int	cell;

	if (ray->map_x < 0 || ray->map_y < 0)
		return (FALSE);
	if (ray->map_x >= WIDTH || ray->map_y >= HEIGHT)
		return (FALSE);
	//printf("DeBUG x = %d y = %d \n", ray->map_x, ray->map_y);
	cell = c3d->map->map_arr[ray->map_y][ray->map_x];
	if (cell != FALSE)
	{
		/* if (current_cell = DOOR) here we will handle doors*/
		return (TRUE);
	}
	return (FALSE);
}


void	ft_cast_ray(t_data *c3d)
{
	t_ray	*ray;

	ray = c3d->player->ray;
	while (!ray->hit /*if we do the ray_cast depth trick its here for large map*/)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->map_x += ray->step_x;
			ray->side_dist_x += ray->delta_x;
			ray->side = 0;
		}
		else
		{
			ray->map_y += ray->step_y;
			ray->side_dist_y += ray->delta_y;
			ray->side = 1;
		}
		if (ft_ray_hit(c3d, ray))
			ray->hit = TRUE;
	}
	if (ray->side == 0)
		ray->perp_wall_dist = (ray->side_dist_x - ray->delta_x);
	else
		ray->perp_wall_dist = (ray->side_dist_y - ray->delta_y);
}

void ft_do_the_raycast(t_data *c3d)
{
	int	x;

	x = 0;
	while (x < WIDTH)
	{
		c3d->player->ray = ft_init_ray(c3d, x);
		ft_cast_ray(c3d);
		if(c3d->player->ray->hit)
			ft_draw_wall(c3d, c3d->player->ray, x);
		//free(c3d->player->ray); <- idk about this
		x++;
	}
}