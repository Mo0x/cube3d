/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 19:31:09 by mgovinda          #+#    #+#             */
/*   Updated: 2024/09/28 19:38:33 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_set_up_dir_2(t_player *player, int flag)
{
	if (flag == 1)
	{
		player->dir_x = 1.0f;
		player->dir_y = 0.0f;
		player->plane_x = 0.0f;
		player->plane_y = 0.66f;
	}
	if (flag == 2)
	{
		player->dir_x = -1.0f;
		player->dir_y = 0.0f;
		player->plane_x = 0.0f;
		player->plane_y = -0.66f;
	}
}

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
		ft_set_up_dir_2(player, 1);
	else if (player->dir == 'W')
		ft_set_up_dir_2(player, 2);
}

void	ft_init(t_data *c3d)
{
	c3d->player->ray = NULL;
	c3d->time = 0;
	c3d->old_time = 0;
	c3d->start_time = 0;
	c3d->refresh = TRUE;
	c3d->focus = 0;
	ft_set_up_dir(c3d->player);
}

void	init_mlx_2(t_data *c3d)
{
	c3d->img_minimap = mlx_new_image(c3d->mlx, \
		MINIMAP_IMG_SIZE, MINIMAP_IMG_SIZE);
	if (!(c3d->img_minimap))
	{
		mlx_close_window(c3d->mlx);
		exit_exclaim("Couldn't initialize minimap image :(\n", c3d);
	}
	if (mlx_image_to_window(c3d->mlx, c3d->img_minimap, \
		MINIMAP_OFF_X, MINIMAP_OFF_Y) == -1)
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
	c3d->img_sprite->instances[0].x = (WIDTH / 2) - \
		(c3d->img_sprite->width / 2);
	c3d->img_sprite->instances[0].y = HEIGHT - c3d->img_sprite->height;
}

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
	init_mlx_2(c3d);
}
