/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkeiser <wkeiser@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 10:55:38 by wkeiser           #+#    #+#             */
/*   Updated: 2024/08/29 10:55:40 by wkeiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"


void	draw_square(mlx_image_t *img, int x_start, int y_start, int size, int color)
{
	int	x;
	int	y;
	int	x_end;
	int	y_end;

	x_end = x_start + size;
	y_end = y_start + size;
	if (!img)
		return ;
	y = y_start;
	while (y < y_end)
	{
		if (y < 0 || y >= (int)img->height)
		{
			y++;
			continue ;
		}
		x = x_start;
		while (x < x_end)
		{
			if (x < 0 || x >= (int)img->width)
			{
				x++;
				continue ;
			}
			mlx_put_pixel(img, x, y, color);
			x++;
		}
		y++;
	}
}

void	draw_minimap_wall(t_data *c3d, int i, int j)
{
	int	color_outer;
	int	color_inner;

	color_outer = 0xA2D2FFFF; // Pastel Blue
	color_inner = 0x1A1A1AFF; // Almost Black
	draw_square(c3d->img_minimap, j * MINIMAP_CELL_SIZE, \
	i * MINIMAP_CELL_SIZE, MINIMAP_CELL_SIZE - 1, color_outer);
	draw_square(c3d->img_minimap, j * MINIMAP_CELL_SIZE + 1, \
	i * MINIMAP_CELL_SIZE + 1, MINIMAP_CELL_SIZE - 3, color_inner);
}

void	draw_minimap(t_data *c3d)
{
	int		i;
	int		j;
	char	cell;

	i = 0;
	while (i < c3d->map->height)
	{
		j = 0;
		while (j < c3d->map->width)
		{
			cell = c3d->map->map_arr[i][j];
			if (cell == '1')
				draw_minimap_wall(c3d, i, j);
			else if (cell == 'D')
			{
				// draw_minimap_door(c3d, i, j); 
			}
			j++;
		}
		i++;
	}
	// draw_minimap_player(c3d); 
}
