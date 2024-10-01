/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 16:58:54 by wkeiser           #+#    #+#             */
/*   Updated: 2024/10/01 14:28:51 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	draw_rect_minimap(mlx_image_t *img, t_rect *rect, t_pos pos)
{
	if (!img || !rect)
		return ;
	pos.y = rect->y_start;
	while (pos.y < rect->y_end)
	{
		if (pos.y < 0 || pos.y >= (int)img->height)
		{
			pos.y++;
			continue ;
		}
		pos.x = rect->x_start;
		while (pos.x < rect->x_end)
		{
			if (pos.x < 0 || pos.x >= (int)img->width)
			{
				pos.x++;
				continue ;
			}
			mlx_put_pixel(img, pos.x, pos.y, rect->color);
			pos.x++;
		}
		pos.y++;
	}
}

void	draw_open_door_mini(t_data *c3d, t_rect rect)
{
	t_pos	pos;

	ft_memset(&pos, 0, sizeof(t_pos));
	rect.color = 0x00FF00FF;
	draw_rect_minimap(c3d->img_minimap, &rect, pos);
}

void	draw_closed_door_mini(t_data *c3d, t_rect rect)
{
	int		x;
	int		y;
	int		k;
	t_pos	pos;

	ft_memset(&pos, 0, sizeof(t_pos));
	rect.color = 0xA2D2FFFF;
	draw_rect_minimap(c3d->img_minimap, &rect, pos);
	k = 0;
	while (k < MINIMAP_CELL_SIZE)
	{
		x = rect.x_start + k;
		y = rect.y_start + k;
		ft_draw_door_pixel_mini(c3d, x, y);
		x = rect.x_end - k;
		y = rect.y_start + k;
		ft_draw_door_pixel_mini(c3d, x, y);
		k++;
	}
}

void	ft_draw_door_pixel_mini(t_data *c3d, int x, int y)
{
	if (x >= 0 && x < (int)c3d->img_minimap->width && \
		y >= 0 && y < (int)c3d->img_minimap->height)
		mlx_put_pixel(c3d->img_minimap, x, y, 0xFF0000FF);
}
