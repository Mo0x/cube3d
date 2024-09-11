/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 17:47:30 by mgovinda          #+#    #+#             */
/*   Updated: 2024/09/11 17:58:29 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_valid_cell(t_data *c3d, int x, int y)
{
	//door check here too
	if (c3d->map->map_arr[y][x] == '0')
		return (TRUE);
	return (FALSE);
}

void	move_up(t_data *c3d, t_player *player)
{
	float	speed;
	float	new_pos;

	speed = player->move_speed;
	new_pos = player->pos_x + player->dir_x * speed;
	if (ft_valid_cell(c3d, (int)new_pos, player->pos_y))
		player->pos_x = new_pos;
	new_pos = player->pos_y + player->dir_y * speed;
	if (ft_valid_cell(c3d, (int)player->pos_x, (int)new_pos))
		player->pos_y = new_pos;
}
void	move_down(t_data *c3d, t_player *player)
{
	float	speed;
	float	new_pos;

	speed = player->move_speed;
	new_pos = player->pos_x - player->dir_x * speed;
	if (ft_valid_cell(c3d, (int)new_pos, player->pos_y))
		player->pos_x = new_pos;
	new_pos = player->pos_y - player->dir_y * speed;
	if (ft_valid_cell(c3d, (int)player->pos_x, (int)new_pos))
		player->pos_y = new_pos;
}

void	move_left(t_data *c3d, t_player *player)
{
	float	speed;
	float	new_pos;

	speed = player->move_speed;
	new_pos = player->pos_x - player->plane_x * speed;
	if (ft_valid_cell(c3d, (int)new_pos, player->pos_y))
		player->pos_x = new_pos;
	new_pos = player->pos_y - player->plane_y * speed;
	if (ft_valid_cell(c3d, (int)player->pos_x, (int)new_pos))
		player->pos_y = new_pos;
}


void	move_right(t_data *c3d, t_player *player)
{
	float	speed;
	float	new_pos;

	speed = player->move_speed;
	new_pos = player->pos_x - player->plane_x * speed;
	if (ft_valid_cell(c3d, (int)new_pos, player->pos_y))
		player->pos_x = new_pos;
	new_pos = player->pos_y - player->plane_y * speed;
	if (ft_valid_cell(c3d, (int)player->pos_x, (int)new_pos))
		player->pos_y = new_pos;
}

void	player_move(t_data *c3d, char *dir)
{
	if (!(ft_strcmp("UP", dir)))
		move_up(c3d, c3d->player);
	else if (!(ft_strcmp("DOWN", dir)))
		move_down(c3d, c3d->player);
	else if (!ft_strcmp("LEFT", dir))
		move_left(c3d, c3d->player);
	else if (!ft_strcmp("RIGHT", dir))
		move_right(c3d, c3d->player);
	c3d->refresh = TRUE;
}
