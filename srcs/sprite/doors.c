/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkeiser <wkeiser@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 16:33:14 by wkeiser           #+#    #+#             */
/*   Updated: 2024/09/23 16:33:15 by wkeiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	add_door(t_data *c3d, int x, int y)
{
	t_door	*new_door;

	new_door = malloc(sizeof(t_door));
	if (!new_door)
		exit_exclaim("Erreur d'allocation pour la porte", c3d);

	new_door->x = x;
	new_door->y = y;
	new_door->state = 0;
	new_door->open_amount = 0.0f;
	new_door->timer = 0.0;
	new_door->next = c3d->doors;
	c3d->doors = new_door;
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
		else if (door->state == DOOR_OPEN)
		{
			door->timer += delta_time;
			if (door->timer >= DOOR_STAY_OPEN_TIME)
			{
				if ((int)c3d->player->pos_x != door->x || (int)c3d->player->pos_y != door->y)
					close_door(door);
			}
		}
		else if (door->state == DOOR_CLOSING)
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
		door = door->next;
	}
}

t_door	*find_door(t_data *c3d, int x, int y)
{
	t_door	*door;

	door = c3d->doors;

	while (door)
	{
		if (door->x == x && door->y == y)
			return (door);
		door = door->next;
	}

	return (NULL);
}

void	open_door(t_door *door)
{
	door->state = DOOR_OPENING;
	door->timer = 0.0;
}

void	close_door(t_door *door)
{
	door->state = DOOR_CLOSING;
	door->timer = 0.0;
}

void	handle_door_interaction(t_data *c3d)
{
	int		px;
	int		py;
	int		dx;
	int		dy;
	int		nx;
	int		ny;
	t_door	*door;

	px = (int)c3d->player->pos_x;
	py = (int)c3d->player->pos_y;

	dy = -1;
	while (dy <= 1)
	{
		dx = -1;
		while (dx <= 1)
		{
			if (dx == 0 && dy == 0)
			{
				dx++;
				continue ;
			}
			nx = px + dx;
			ny = py + dy;
			if (nx >= 0 && ny >= 0 && ny < c3d->map->height && nx < c3d->map->width)
			{
				if (c3d->map->map_arr[ny][nx] == 'D')
				{
					door = find_door(c3d, nx, ny);
					if (door)
					{
						if (door->state == 0)
							open_door(door);
						else if (door->state == 2)
							close_door(door);
					}
				}
			}
			dx++;
		}
		dy++;
	}
}
