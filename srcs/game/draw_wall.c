/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 19:18:15 by mgovinda          #+#    #+#             */
/*   Updated: 2024/09/14 18:46:59 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_draw_wall(t_data *c3d, t_ray *ray, int x)
{
	int			y;
	uint32_t	color;

	ray->line_height = (float)HEIGHT / ray->perp_wall_dist;
	//printf(" line heigt = %f, height = %f, perp_wall %f\n", ray->line_height, (float)HEIGHT, ray->perp_wall_dist);
	ray->draw_start = (-ray->line_height + HEIGHT) / 2;
	if (ray->draw_start < 0.0f)
		ray->draw_start = 0.0f;
	ray->draw_end = (ray->line_height + HEIGHT) / 2;
	if (ray->draw_end >= (float)HEIGHT)
		ray->draw_end = (float)HEIGHT - 1;
	/*TODO setup texture*/
	y = ray->draw_start;
	while (y < ray->draw_end)
	{
		/*here load texture into a future ray->texture*/
		color = RED;
		ft_warpper_put_pxl(c3d->img, x, y++, color);
	}
}
