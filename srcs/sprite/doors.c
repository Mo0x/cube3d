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
	c3d->refresh = TRUE;
}
