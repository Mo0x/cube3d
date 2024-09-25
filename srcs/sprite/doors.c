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

	new_door = walloc(sizeof(t_door));
	if (!new_door)
		exit_exclaim("Erreur d'allocation pour la porte", c3d);
	new_door->x = x;
	new_door->y = y;
	new_door->state = 0;
	new_door->open_amount = 0.0f;
	new_door->timer = 0.0;
	new_door->next = c3d->doors;
	c3d->doors = new_door;
	printf("Added door at (%d, %d)\n", x, y);
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

void	check_and_toggle_door(t_data *c3d, t_pos pos)
{
	t_door	*door;

	if (pos.x >= 0 && pos.y >= 0 && \
		pos.y < c3d->map->height && pos.x < c3d->map->width)
	{
		if (c3d->map->map_arr[pos.y][pos.x] == 'D')
		{
			door = find_door(c3d, pos.x, pos.y);
			if (door)
			{
				if (door->state == DOOR_CLOSED)
					open_door(door);
				else if (door->state == DOOR_OPEN)
					close_door(door);
			}
		}
	}
}

void	handle_door_interaction(t_data *c3d)
{
	t_pos	pos;

	ft_memset(&pos, 0, sizeof(t_pos));
	pos.px = (int)c3d->player->pos_x;
	pos.py = (int)c3d->player->pos_y;
	pos.dy = -1;
	while (pos.dy <= 1)
	{
		pos.dx = -1;
		while (pos.dx <= 1)
		{
			if (pos.dx == 0 && pos.dy == 0)
			{
				pos.dx++;
				continue ;
			}
			pos.x = pos.px + pos.dx;
			pos.y = pos.py + pos.dy;
			check_and_toggle_door(c3d, pos);
			pos.dx++;
		}
		pos.dy++;
	}
	c3d->refresh = TRUE;
}
