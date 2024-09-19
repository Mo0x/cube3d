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
	y = rect->y_start;
	while (y < rect->y_end)
	{
		if (y < 0 || y >= (int)img->height)
		{
			y++;
			continue ;
		}
		x = rect->x_start;
		while (x < rect->x_end)
		{
			if (x < 0 || x >= (int)img->width)
			{
				x++;
				continue ;
			}
			mlx_put_pixel(img, x, y, rect->color);
			x++;
		}
		y++;
	}
}

void	draw_minimap_wall(t_data *c3d, float i, float j)
{
	t_rect	outer_rect;
	t_rect	inner_rect;

	outer_rect.x_start = j * MINIMAP_CELL_SIZE;
	outer_rect.y_start = i * MINIMAP_CELL_SIZE;
	outer_rect.x_end = outer_rect.x_start + MINIMAP_CELL_SIZE - 1;
	outer_rect.y_end = outer_rect.y_start + MINIMAP_CELL_SIZE - 1;
	outer_rect.color = 0xA2D2FFFF;

	inner_rect.x_start = outer_rect.x_start + 1;
	inner_rect.y_start = outer_rect.y_start + 1;
	inner_rect.x_end = outer_rect.x_end - 1;
	inner_rect.y_end = outer_rect.y_end - 1;
	inner_rect.color = 0x1A1A1AFF;

	draw_rect(c3d->img_minimap, &outer_rect);
	draw_rect(c3d->img_minimap, &inner_rect);
}

void	draw_minimap_player(t_data *c3d, float offset_x, float offset_y)
{
	t_rect	player_outer;
	t_rect	player_inner;
	float	player_minimap_x;
	float	player_minimap_y;

	player_minimap_x = (c3d->player->pos_x - offset_x) * MINIMAP_CELL_SIZE;
	player_minimap_y = (c3d->player->pos_y - offset_y) * MINIMAP_CELL_SIZE;

	player_outer.x_start = (int)player_minimap_x - 3;
	player_outer.y_start = (int)player_minimap_y - 3;
	player_outer.x_end = player_outer.x_start + 6;
	player_outer.y_end = player_outer.y_start + 6;
	player_outer.color = 0x00FF00FF;

	player_inner.x_start = player_outer.x_start + 1;
	player_inner.y_start = player_outer.y_start + 1;
	player_inner.x_end = player_outer.x_end - 1;
	player_inner.y_end = player_outer.y_end - 1;
	player_inner.color = 0x1A1A1AFF;

	draw_rect(c3d->img_minimap, &player_outer);
	draw_rect(c3d->img_minimap, &player_inner);
}

/*
void	draw_minimap_background(t_data *c3d)
{
	t_rect	background_rect;

	background_rect.x_start = 0;
	background_rect.y_start = 0;
	background_rect.x_end = MINIMAP_IMG_SIZE;
	background_rect.y_end = MINIMAP_IMG_SIZE;
	// Set the color to black with 40% opacity (60% transparent)
	background_rect.color = 0x66000000; // ARGB format: Alpha=0x66, RGB=0x000000
	draw_rect(c3d->img_minimap, &background_rect);
}*/

void	draw_minimap(t_data *c3d)
{
	int		i;
	int		j;
	char	cell;
	float	offset_x;
	float	offset_y;

	//draw_minimap_background(c3d);
	offset_x = c3d->player->pos_x - (MINIMAP_IMG_SIZE / (2.0f * MINIMAP_CELL_SIZE));
	offset_y = c3d->player->pos_y - (MINIMAP_IMG_SIZE / (2.0f * MINIMAP_CELL_SIZE));

	i = 0;
	while (i < c3d->map->height)
	{
		j = 0;
		while (c3d->map->map_arr[i][j] && j < c3d->map->width)
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
	draw_minimap_player(c3d, offset_x, offset_y);
	// draw_minimap_borders(c3d);
}
