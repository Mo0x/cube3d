/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 17:22:23 by mgovinda          #+#    #+#             */
/*   Updated: 2024/09/28 19:06:35 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_cursor(double x, double y, void *c4d)
{
	t_data	*c3d;

	(void)y;
	c3d = c4d;
	if (c3d->focus == 0)
		return ;
	if (x < ((WIDTH / 2) - 1))
	{
		player_look(c3d, "LEFT");
		mlx_set_mouse_pos(c3d->mlx, WIDTH / 2, HEIGHT / 2);
	}
	else if (x > ((WIDTH / 2) - 1))
	{
		player_look(c3d, "RIGHT");
		mlx_set_mouse_pos(c3d->mlx, WIDTH / 2, HEIGHT / 2);
	}
}

void	ft_mouse(mouse_key_t button, action_t action, modifier_key_t mods,
		void *c4d)
{
	t_data	*c3d;

	c3d = c4d;
	(void)mods;
	if (button == MLX_MOUSE_BUTTON_LEFT && action == MLX_PRESS)
	{
		c3d->focus = !c3d->focus;
		if (c3d->focus)
			mlx_set_cursor_mode(c3d->mlx, MLX_MOUSE_HIDDEN);
		else
			mlx_set_cursor_mode(c3d->mlx, MLX_MOUSE_NORMAL);
	}
}
