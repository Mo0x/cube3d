/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_look.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 15:56:52 by mgovinda          #+#    #+#             */
/*   Updated: 2024/09/07 16:16:41 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_rotate(double *x, double *y, float angle)
{
	float	tmp_x;
	float	tmp_y;

	tmp_x = *x;
	tmp_y = *y;
	*x = tmp_x * cos(angle) - tmp_y * sin(angle);
	*y = tmp_x * sin(angle) + tmp_y * cos(angle);
}

void	player_look_right(t_data *c3d)
{
	t_player	*p;

	p = c3d->player;
	ft_rotate(&(p->dir_x), &(p->dir_y), -p->cam_speed);
	ft_rotate(&(p->plane_x), &(p->plane_y), -p->cam_speed);
	c3d->refresh = TRUE;
}

void	player_look_left(t_data *c3d)
{
	t_player	*p;

	p = c3d->player;
	ft_rotate(&(p->dir_x), &(p->dir_y), p->cam_speed);
	ft_rotate(&(p->plane_x), &(p->plane_y), p->cam_speed);
	c3d->refresh = TRUE;
}

void	player_look(t_data *c3d, char *dir)
{
	if (!(ft_strcmp(dir, "RIGHT")))
		player_look_right(c3d);
	else if (!(ft_strcmp(dir, "LEFT")))
		player_look_left(c3d);
}
