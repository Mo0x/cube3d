/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 14:47:18 by mgovinda          #+#    #+#             */
/*   Updated: 2024/09/28 19:03:06 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(int argc, char **argv)
{
	t_data	*c3d;

	c3d = walloc(sizeof(t_data));
	if (!c3d)
		exit_exclaim("c3d malloc failed\n", c3d);
	ft_memset(c3d, 0, sizeof(t_data));
	c3d->map = walloc(sizeof(t_map));
	if (!c3d->map)
		exit_exclaim("c3d->map malloc failed\n", c3d);
	c3d->player = walloc(sizeof(t_player));
	if (!c3d->player)
		exit_exclaim("c3d->player malloc failed\n", c3d);
	parsing(c3d->map, argv, argc, c3d);
	printf("North path :%s\n", c3d->map->n_path);
	printf("S path :%s\n", c3d->map->s_path);
	printf("W path :%s\n", c3d->map->w_path);
	printf("E path :%s\n", c3d->map->e_path);
	printf("Converted ceiling color: 0x%X\n", c3d->floorcolor);
	printf("Converted floor color: 0x%X\n", c3d->ceilingcolor);
	ft_start_game(c3d);
	ft_clean_up(c3d);
	wclear();
	return (0);
}
