/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 19:09:39 by mgovinda          #+#    #+#             */
/*   Updated: 2024/09/16 16:44:13 by mgovinda         ###   ########.fr       */
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
	//printf("DeBUG x = %d y = %d \n", ray->map_x, ray->map_y);
	cell = (c3d->map->map_arr[ray->map_y][ray->map_x]);
	if (cell == '1')
	{
		ray->hit_type = WALL_HIT;
		return (TRUE);
	}
	else if (cell == 'D')
		return (handle_door_cell(c3d, ray)); // si le rayon trouve une porte et qu elle est open, retourne false pour afficher ce qui il y a derriere
	else
		return (FALSE);
}


void	ft_cast_ray(t_data *c3d) // a spliter j ai rajoute des lines pour la porte je m en charge
{
	t_ray	*ray;
	int		depth;
	t_door	*door;

	depth = 0;
	ray = c3d->player->ray;
	while (ray->hit == 0 && depth < 64)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->map_x += ray->step_x;
			ray->side_dist_x += ray->delta_x;
			ray->side = 0;
			//printf("map_x %d, step_x %d, dist_x %f delta_x %f\n", ray->map_x, ray->step_x, ray->side_dist_x, ray->delta_x);
		}
		else
		{
			ray->map_y += ray->step_y;
			ray->side_dist_y += ray->delta_y;
			ray->side = 1;
			//printf("map_y %d, step_y %d, dist_y %f delta_y %f\n", ray->map_y, ray->step_y, ray->side_dist_y, ray->delta_y);
		}
		if (ft_ray_hit(c3d, ray))
		{
			ray->hit = TRUE;
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
		depth++;
	}
	if (ray->side == 0)
		ray->perp_wall_dist = (ray->side_dist_x - ray->delta_x);
	else
		ray->perp_wall_dist = (ray->side_dist_y - ray->delta_y);
	//printf("side %d perp %f\n", ray->side, ray->perp_wall_dist); //probleme here
}

void ft_do_the_raycast(t_data *c3d)
{
	int	x;

	x = 0;
	while (x < WIDTH)
	{
		c3d->player->ray = ft_init_ray(c3d, x);
		ft_cast_ray(c3d);
		if(c3d->player->ray->hit == 1)
		{
			ft_draw_wall(c3d, c3d->player->ray, x);
			//free(c3d->player->ray); <- idk about this
		}
		x++;
	}
}
