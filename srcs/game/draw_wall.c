/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 19:18:15 by mgovinda          #+#    #+#             */
/*   Updated: 2024/09/07 15:54:40 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_draw_wall(t_data *c3d, t_ray *ray, int x)
{
	int	y;
	int	color;

	ray->line_height = (float)HEIGHT / ray->perp_wall_dist;
	ray->draw_start = (-ray->line_height / 2 + HEIGHT) / 2;
	if (ray->draw_start < 0.0f)
		ray->draw_start = 0.0f;
	ray->draw_end = (ray->line_height / 2 + HEIGHT) / 2;
	if (ray->draw_end >= HEIGHT)
		ray->draw_end = HEIGHT - 1;
	/*TODO setup texture*/
	y = ray->draw_start;
	while (y < ray->draw_end)
	{
		/*here load texture into a future ray->texture*/
		color = YELLOW;
		ft_warpper_put_pxl(c3d->img, x, y++, color);
	}
}