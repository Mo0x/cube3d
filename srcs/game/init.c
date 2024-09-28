/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 18:03:38 by mgovinda          #+#    #+#             */
/*   Updated: 2024/09/28 19:37:00 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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
	c3d->player->cam_speed = (float)c3d->mlx->delta_time * 2.0f;
	c3d->player->move_speed = (float)c3d->mlx->delta_time * 3.0f;
	ft_do_the_input(c3d);
}

/*can do a frame counter idk if needed*/

void	game_render(void *c4d)
{
	t_data	*c3d;

	c3d = c4d;
	if (c3d->start_time == 0)
		c3d->start_time = mlx_get_time();
	c3d->time = mlx_get_time() - c3d->start_time;
	set_up_player(c3d);
	update_doors(c3d);
	render(c3d);
}

void	ft_start_game(t_data *c3d)
{
	ft_init(c3d);
	init_mlx(c3d);
	init_wall_textures(c3d);
	mlx_loop_hook(c3d->mlx, game_render, c3d);
	mlx_key_hook(c3d->mlx, ft_escape, c3d);
	mlx_mouse_hook(c3d->mlx, ft_mouse, c3d);
	mlx_cursor_hook(c3d->mlx, ft_cursor, c3d);
	mlx_loop(c3d->mlx);
}
