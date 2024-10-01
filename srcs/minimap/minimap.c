/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 10:55:38 by wkeiser           #+#    #+#             */
/*   Updated: 2024/10/01 14:28:21 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	draw_minimap_wall(t_data *c3d, float i, float j)
{
	t_rect	out_rect;
	t_rect	inn_rect;
	t_pos	pos;

	out_rect.x_start = j * MINIMAP_CELL_SIZE;
	out_rect.y_start = i * MINIMAP_CELL_SIZE;
	out_rect.x_end = out_rect.x_start + MINIMAP_CELL_SIZE - 1;
	out_rect.y_end = out_rect.y_start + MINIMAP_CELL_SIZE - 1;
	out_rect.color = 0xA2D2FFFF;
	inn_rect.x_start = out_rect.x_start + 1;
	inn_rect.y_start = out_rect.y_start + 1;
	inn_rect.x_end = out_rect.x_end - 1;
	inn_rect.y_end = out_rect.y_end - 1;
	inn_rect.color = 0x1A1A1AFF;
	ft_memset((void *)&pos, 0, sizeof(t_pos));
	draw_rect_minimap(c3d->img_minimap, &out_rect, pos);
	draw_rect_minimap(c3d->img_minimap, &inn_rect, pos);
}

void	draw_minimap_player(t_data *c3d, float offset_x, float offset_y)
{
	t_rect	player_outer;
	t_rect	player_inner;
	float	player_minimap_x;
	float	player_minimap_y;
	t_pos	pos;

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
	ft_memset((void *)&pos, 0, sizeof(t_pos));
	draw_rect_minimap(c3d->img_minimap, &player_outer, pos);
	draw_rect_minimap(c3d->img_minimap, &player_inner, pos);
}

void	process_map_row(t_data *c3d, int i, float offset_x, float offset_y)
{
	int		j;
	char	cell;
	t_door	*door;

	j = 0;
	while (c3d->map->map_arr[i][j] && j < c3d->map->width)
	{
		cell = c3d->map->map_arr[i][j];
		if (cell == '1')
			draw_minimap_wall(c3d, i - offset_y, j - offset_x);
		else if (cell == 'D')
		{
			door = find_door(c3d, j, i);
			draw_minimap_door(c3d, i - offset_y, j - offset_x, door);
		}
		j++;
	}
}

void	draw_minimap_door(t_data *c3d, float i, float j, t_door *door)
{
	t_rect	rect;
	t_pos	pos;

	if (!door)
		return ;
	ft_memset(&pos, 0, sizeof(t_pos));
	rect.x_start = j * MINIMAP_CELL_SIZE;
	rect.y_start = i * MINIMAP_CELL_SIZE;
	rect.x_end = rect.x_start + MINIMAP_CELL_SIZE - 1;
	rect.y_end = rect.y_start + MINIMAP_CELL_SIZE - 1;
	if (door->state == DOOR_OPEN)
		draw_open_door_mini(c3d, rect);
	else
		draw_closed_door_mini(c3d, rect);
}

void	draw_minimap(t_data *c3d)
{
	float	offset_x;
	float	offset_y;
	int		i;

	offset_x = c3d->player->pos_x - (MINIMAP_IMG_SIZE \
				/ (2.0f * MINIMAP_CELL_SIZE));
	offset_y = c3d->player->pos_y - (MINIMAP_IMG_SIZE \
				/ (2.0f * MINIMAP_CELL_SIZE));
	i = 0;
	while (i < c3d->map->height)
	{
		process_map_row(c3d, i, offset_x, offset_y);
		i++;
	}
	draw_minimap_player(c3d, offset_x, offset_y);
}
