/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   updating_doors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkeiser <wkeiser@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 22:59:45 by wkeiser           #+#    #+#             */
/*   Updated: 2024/09/23 22:59:45 by wkeiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	update_door_opening(t_data *c3d, t_door *door, double delta_time)
{
	door->timer += delta_time;
	door->open_amount = door->timer / DOOR_OPEN_TIME;
	if (door->open_amount >= 1.0)
	{
		door->open_amount = 1.0;
		door->state = DOOR_OPEN;
		door->timer = 0.0;
	}
	c3d->refresh = TRUE;
}

void	update_door_open(t_data *c3d, t_door *door, double delta_time)
{
	door->timer += delta_time;
	if (door->timer >= DOOR_STAY_OPEN_TIME)
	{
		if ((int)c3d->player->pos_x != door->x || (int)c3d->player->pos_y != door->y)
			close_door(door);
	}
}

void	update_door_closing(t_data *c3d, t_door *door, double delta_time)
{
	if ((int)c3d->player->pos_x == door->x && (int)c3d->player->pos_y == door->y)
	{
		door->state = DOOR_OPEN;
		door->timer = 0.0;
	}
	else
	{
		door->timer += delta_time;
		door->open_amount = 1.0 - (door->timer / DOOR_OPEN_TIME);
		if (door->open_amount <= 0.0)
		{
			door->open_amount = 0.0;
			door->state = DOOR_CLOSED;
			door->timer = 0.0;
		}
		c3d->refresh = TRUE;
	}
}

void	update_doors(t_data *c3d)
{
	t_door	*door;
	double	delta_time;

	door = c3d->doors;
	delta_time = c3d->mlx->delta_time;
	while (door)
	{
		if (door->state == DOOR_OPENING)
			update_door_opening(c3d, door, delta_time);
		else if (door->state == DOOR_OPEN)
			update_door_open(c3d, door, delta_time);
		else if (door->state == DOOR_CLOSING)
			update_door_closing(c3d, door, delta_time);
		door = door->next;
	}
}
