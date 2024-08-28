/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 18:39:12 by mgovinda          #+#    #+#             */
/*   Updated: 2024/08/28 19:05:18 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_clear_image(mlx_image_t *img, int color)
{
	int	x;
	int	y;

	if(!img)
		return ;
	y = 0;
	while(y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			mlx_put_pixel(img, x, y, color);
			x++;
		}
		y++;
	}
}

/*x_start and y_start must be << to x_end and y_end*/

void	ft_draw_rectangle(mlx_image_t *img, t_rect rect)
{
	int x;
	int	y;

	if (!img)
		return ;
	y = rect.y_start;
	while (x < rect.x_end)
	{
		x = rect.x_start;
		while (y < rect.y_end)
		{
			mlx_put_pixel(img, x, y, rect.color);
			y++;
		}
		x++;
	}
}

void	ft_draw_vertical(t_data *c3d, t_ray *ray, int x)
{
	int y;

	y = ray->draw_start;
	while (y < ray->draw_end)
	{
			mlx_put_pixel(c3d->img, x, y, YELLOW);
			y++;
	}
}