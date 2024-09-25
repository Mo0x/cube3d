/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_door.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkeiser <wkeiser@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 22:50:52 by wkeiser           #+#    #+#             */
/*   Updated: 2024/09/23 22:53:15 by wkeiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	handle_door_cell(t_data *c3d, t_ray *ray)
{
	t_door	*door;

	door = find_door(c3d, ray->map_x, ray->map_y);
	if (door && door->open_amount >= 1.0)
		return (FALSE);
	else
	{
		ray->hit_type = DOOR_HIT;
		if (door)
			ray->door_open_amount = door->open_amount;
		else
			ray->door_open_amount = 0.0;
		return (TRUE);
	}
}
