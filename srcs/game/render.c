/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 17:01:05 by mgovinda          #+#    #+#             */
/*   Updated: 2024/09/14 18:03:42 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_roof_and_ground(t_data *c3d)
{
	t_rect	rect;

	rect.x_start = 0;
	rect.y_start = 0;
	rect.x_end = WIDTH;
	rect.y_end = HEIGHT / 2;
	rect.color = (c3d->floorcolor << 8) + 0xFF;
	ft_draw_rectangle(c3d->img, rect);
	rect.y_start = rect.y_end;
	rect.y_end = HEIGHT;
	rect.color = (c3d->ceilingcolor << 8) + 0xFF;
	ft_draw_rectangle(c3d->img, rect);
}

void	render(t_data *c3d)
{
	if (c3d->refresh)
	{
		ft_clear_image(c3d->img, BLACK);
		ft_clear_mini_image(c3d->img_minimap, BLACK);
		ft_roof_and_ground(c3d);
		ft_do_the_raycast(c3d);
		draw_minimap(c3d);
		c3d->refresh = FALSE;
	}
}
