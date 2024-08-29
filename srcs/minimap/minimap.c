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

void	draw_rect(mlx_image_t *img, t_rect *rect)
{
	int	x;
	int	y;

	if (!img || !rect)
		return ;

	y = rect->y - 1;
	while (y++ < rect->y + rect->h)
	{
		if (y < 0 || y >= (int)img->height)
			continue ;
		x = rect->x;
		while (x < rect->x + rect->w)
		{
			if (x < 0 || x >= (int)img->width)
			{
				x++;
				continue ;
			}
			mlx_put_pixel(img, x, y, rect->color);
			x++;
		}
	}
}

void	draw_minimap_wall(t_data *c3d, int i, int j)
{
	t_rect	outer_rect;
	t_rect	inner_rect;

	outer_rect.x = j * MINIMAP_CELL_SIZE;
	outer_rect.y = i * MINIMAP_CELL_SIZE;
	outer_rect.w = MINIMAP_CELL_SIZE - 1;
	outer_rect.h = MINIMAP_CELL_SIZE - 1 - 1;
	outer_rect.color = 0xA2D2FFFF; // Pastel Blue,
	inner_rect.x = j * MINIMAP_CELL_SIZE + 1;
	inner_rect.y = i * MINIMAP_CELL_SIZE + 1;
	inner_rect.w = outer_rect.w - 2;
	inner_rect.h = outer_rect.h - 2;
	inner_rect.color = 0x1A1A1AFF; // Almost Black
	draw_rect(c3d->img_minimap, &outer_rect);
	draw_rect(c3d->img_minimap, &inner_rect);
}

void	draw_minimap_player(t_data *c3d)
{
	t_rect	player_outer;
	t_rect	player_inner;
	int		player_size;

	player_size = 6;
	player_outer.x = MINIMAP_IMG_SIZE / 2 - player_size / 2;
	player_outer.y = MINIMAP_IMG_SIZE / 2 - player_size / 2;
	player_outer.w = player_size;
	player_outer.h = player_size;
	player_outer.color = 0x00FF00FF; // Bright Green
	player_inner.x = player_outer.x + 1;
	player_inner.y = player_outer.y + 1;
	player_inner.w = player_size - 2;
	player_inner.h = player_size - 2;
	player_inner.color = 0x1A1A1AFF; // Almost Black
	draw_rect(c3d->img_minimap, &player_outer);
	draw_rect(c3d->img_minimap, &player_inner);
}

void	draw_minimap(t_data *c3d)
{
	int		i;
	int		j;
	char	cell;
	int		offset_x;
	int		offset_y;

	offset_x = c3d->player->pos_x - (MINIMAP_IMG_SIZE / (2 * MINIMAP_CELL_SIZE));
	offset_y = c3d->player->pos_y - (MINIMAP_IMG_SIZE / (2 * MINIMAP_CELL_SIZE));

	i = 0;
	while (i < c3d->map->height)
	{
		j = 0;
		while (j < c3d->map->width)
		{
			cell = c3d->map->map_arr[i][j];
			if (cell == '1')
				draw_minimap_wall(c3d, i - offset_y, j - offset_x);
			else if (cell == 'D')
			{
				// draw_minimap_door(c3d, i, j);
			}
			j++;
		}
		i++;
	}
	draw_minimap_player(c3d);
}
