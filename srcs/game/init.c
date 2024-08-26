/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 18:03:38 by mgovinda          #+#    #+#             */
/*   Updated: 2024/08/26 19:03:06 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_init(t_data *c3d)
{
	c3d->player->dir_x = -1;
	c3d->player->dir_y = 0;
	c3d->player->plane_x = 0;
	c3d->player->plane_y = 0.66;
	c3d->time = 0;
	c3d->old_time = 0;
}

void	ft_step_and_side_dist(t_data *c3d, t_ray *ray)
{
	if (ray->ray_dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (c3d->player->pos_x - ray->map_x) * ray->delta_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0 - c3d->player->pos_x) * ray->delta_x;
	}
	if (ray->ray_dir_y < 0)
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
void	ft_did_it_hit(t_ray *ray, t_data *c3d)
{
	while (ray->hit == 0)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_y;
			ray->map_y += ray->step_x;
			ray->side = 1;
		}
		if (c3d->map->map_arr[ray->map_x][ray->map_y] > 0)
			ray->hit = 1;
	}
}

void	game_loop(t_data *c3d)
{
	int		x;
	t_ray	*ray;

	x = 0;
	ray = walloc(sizeof(t_ray));
	if (!ray)
		exit_exclaim("Malloc error game_loop");
	//here need a bigger loop !done
	while (x < WIDTH)
	{
		ray->camera_x = 2 * x / WIDTH - 1;
		ray->ray_dir_x = c3d->player->dir_x + c3d->player->plane_x * ray->camera_x;
		ray->ray_dir_y = c3d->player->dir_y + c3d->player->plane_y * ray->camera_x;
		ray->map_x = (int)c3d->player->pos_x;
		ray->map_y = (int)c3d->player->pos_y;
		if (ray->ray_dir_x == 0)
			ray->delta_x = 1e30;
		else
			ray->delta_x = ft_abs_double(1/ray->ray_dir_x);
		if (ray->ray_dir_y == 0)
			ray->delta_y = 1e30;
		else
			ray->delta_y = ft_abs_double(1/ray->ray_dir_y);
		ray->hit = 0;
		ft_step_and_side_dist(c3d, ray);
		ft_did_it_hit(ray, c3d);
		if (ray->side == 0)
			ray->perp_wall_dist = (ray->side_dist_x - ray->delta_x);
		else
			ray->perp_wall_dist = (ray->side_dist_y - ray->delta_y);
		ray->line_height = (int)(HEIGHT / ray->perp_wall_dist);
		ray->draw_start = -ray->line_height / 2 + HEIGHT / 2;
		if (ray->draw_start < 0)
			ray->draw_start = 0;
		ray->draw_end = ray->line_height / 2 + HEIGHT / 2;
		if (ray->draw_end >= HEIGHT)
			ray->draw_end = HEIGHT - 1;
		/* TODO calculate from direction (NSEW) the wall is hit and determine color*/
		
		int color = YELLOW;
		if (ray->side == 1)
			color = color / 2;
		/* end temporary color*/
		ft_draw_vertical(c3d, ray, x);	
		x++;
	}
	c3d->old_time = c3d->time;
	c3d->time = give_me_time();
	c3d->frame = (c3d->time - c3d->old_time) / 1000.0;
}

void	ft_start_game(t_data *c3d)
{
	ft_init(c3d);
	c3d->mlx = mlx_init(WIDTH, HEIGHT, "MLX42", FALSE);
	if (!(c3d->mlx))
		exit_exclaim("Couldn't initialize mlx :(\n");
	c3d->img = mlx_new_image(c3d->mlx, WIDTH, HEIGHT);
	if (!(c3d->img))
	{
		mlx_close_window(c3d->mlx);
		exit_exclaim("Couldn't initialize image :(\n");
	}
	game_loop(c3d);
	/* set hook here*/	
}