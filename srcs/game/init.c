/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 18:03:38 by mgovinda          #+#    #+#             */
/*   Updated: 2024/09/11 17:54:07 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_set_up_dir(t_player *player)
{
	if (player->dir == 'N')
	{
		player->dir_x = 0.0f;
		player->dir_y = -1.0f;
		player->plane_x = 0.66f;
		player->plane_y = 0.0f;
	}
	else if (player->dir == 'S')
	{
		player->dir_x = 0.0f;
		player->dir_y = 1.0f;
		player->plane_x = -0.66f;
		player->plane_y = 0.0f;
	}
	else if (player->dir == 'E')
	{
		player->dir_x = 1.0f;
		player->dir_y = 0.0f;
		player->plane_x = 0.0f;
		player->plane_y = 0.66f;
	}
	else if (player->dir == 'W')
	{
		player->dir_x = -1.0f;
		player->dir_y = 0.0f;
		player->plane_x = 0.0f;
		player->plane_y = -0.66f;
	}
}

void	ft_init(t_data *c3d)
{
	/* c3d->_x = -1;
	c3d->player->dir_y = 0; */
	c3d->player->ray = NULL;
	c3d->time = 0;
	c3d->old_time = 0;
	c3d->start_time = 0;
	c3d->refresh = TRUE;
	ft_set_up_dir(c3d->player);
	// temp;
}

/* void	ft_step_and_side_dist(t_data *c3d, t_ray *ray)
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
			ray->hit = TRUE;
	}
	ray->side_dist_x += ray->delta_x;
		
}
// gameloop going to be split in the raycasting.c calculeous are correct

void	game_loop(void *c4d)
{
	int		x;
	t_ray	*ray;
	t_data	*c3d;

	c3d = (t_data *)c4d;
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
		 TODO calculate from direction (NSEW) the wall is hit and determine color
		int color = YELLOW;
		if (ray->side == 1)
			color = color / 2;
		// end temporary color
		ft_draw_vertical(c3d, ray, x);	
		x++;
	}
} */

void	init_mlx(t_data *c3d)
{
	c3d->mlx = mlx_init(WIDTH, HEIGHT, "MLX42", FALSE);
	if (!(c3d->mlx))
		exit_exclaim("Couldn't initialize mlx :(\n", c3d);
	c3d->img = mlx_new_image(c3d->mlx, WIDTH, HEIGHT);
	if (!(c3d->img))
	{
		mlx_close_window(c3d->mlx);
		exit_exclaim("Couldn't initialize image :(\n", c3d);
	}
	if (mlx_image_to_window(c3d->mlx, c3d->img, 0, 0) == -1)
	{
		mlx_close_window(c3d->mlx);
		exit_exclaim("couldn't image to window", c3d);
	}
	c3d->img_minimap = mlx_new_image(c3d->mlx, MINIMAP_IMG_SIZE, MINIMAP_IMG_SIZE);
	if (!(c3d->img_minimap))
	{
		mlx_close_window(c3d->mlx);
		exit_exclaim("Couldn't initialize minimap image :(\n", c3d);
	}
	if (mlx_image_to_window(c3d->mlx, c3d->img_minimap, MINIMAP_OFF_X, MINIMAP_OFF_Y) == -1)
	{
		mlx_close_window(c3d->mlx);
		exit_exclaim("couldn't image to window", c3d);
	}
	load_weapon_image(c3d, "srcs/sprite/gun.png");
	if (mlx_image_to_window(c3d->mlx, c3d->img_sprite, 0, 0) == -1)
	{
		mlx_close_window(c3d->mlx);
		exit_exclaim("Couldn't display weapon sprite", c3d);
	}
	// Positionnement initial du sprite
	c3d->img_sprite->instances[0].x = (WIDTH / 2) - (c3d->img_sprite->width / 2);
	c3d->img_sprite->instances[0].y = HEIGHT - c3d->img_sprite->height;
}
//TODO PLAYER MOVE AND PLAYER LOOK

void	ft_check_moving(t_data *c3d)
{
	int	is_moving;

	is_moving = FALSE;
	if (mlx_is_key_down(c3d->mlx, MLX_KEY_W) || \
	mlx_is_key_down(c3d->mlx, MLX_KEY_S) || \
	mlx_is_key_down(c3d->mlx, MLX_KEY_A) || \
	mlx_is_key_down(c3d->mlx, MLX_KEY_D) || \
	mlx_is_key_down(c3d->mlx, MLX_KEY_LEFT) || \
	mlx_is_key_down(c3d->mlx, MLX_KEY_RIGHT))
		is_moving = TRUE;
	c3d->is_moving = is_moving;
}

// est ce qu on fait les diagonales : W et D / W et A ?
void	ft_do_the_input(t_data *c3d)
{
	ft_check_moving(c3d);
	if (mlx_is_key_down(c3d->mlx, MLX_KEY_W))
		player_move(c3d, "UP");
	else if (mlx_is_key_down(c3d->mlx, MLX_KEY_S))
		player_move(c3d, "DOWN");
	else if (mlx_is_key_down(c3d->mlx, MLX_KEY_A))
		player_move(c3d, "LEFT");
	else if (mlx_is_key_down(c3d->mlx, MLX_KEY_D))
		player_move(c3d, "RIGHT");
	else if (mlx_is_key_down(c3d->mlx, MLX_KEY_LEFT))
		player_look(c3d, "LEFT");
	else if (mlx_is_key_down(c3d->mlx, MLX_KEY_RIGHT))
		player_look(c3d, "RIGHT");
	if (mlx_is_key_down(c3d->mlx, MLX_KEY_E))
		handle_door_interaction(c3d);
}

void	set_up_player(t_data *c3d)
{
	//todo idk what delta time
	c3d->player->cam_speed = (float)c3d->mlx->delta_time * 2.0f;
	c3d->player->move_speed = (float)c3d->mlx->delta_time * 3.0f;
	ft_do_the_input(c3d);
}

void	game_render(void *c4d)
{
	t_data	*c3d;

	c3d = c4d;
	if (c3d->start_time == 0)
		c3d->start_time = mlx_get_time();
	c3d->time = mlx_get_time() - c3d->start_time;
	//todo frame time and sprite time
	set_up_player(c3d);
	update_doors(c3d);
	render(c3d); // the function that draw ceilling and floor and call the ray_cast
}

void	ft_start_game(t_data *c3d)
{
	ft_init(c3d);
	init_mlx(c3d);
	init_wall_textures(c3d);
	mlx_loop_hook(c3d->mlx, game_render, c3d);
	
	//game_loop(c3d);
	/* set hook here*/
	mlx_loop(c3d->mlx);
}
