/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 14:47:18 by mgovinda          #+#    #+#             */
/*   Updated: 2024/08/26 19:24:53 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

//test git

int	main(int argc, char **argv)
{
	t_data	*c3d;

	c3d = walloc(sizeof(t_data));
	if (!c3d)
		exit_exclaim("c3d malloc failed\n");
	c3d->map = walloc(sizeof(t_map));
	if (!c3d->map)
		exit_exclaim("c3d->map malloc failed\n");
	c3d->player = walloc(sizeof(t_player));
	if (!c3d->player)
		exit_exclaim("c3d->player malloc failed\n");
	parsing(c3d->map, argv, argc, c3d);
	/* ft_start_game(c3d)*/
	wclear(); /* <---- a mettre a chaque fin dexec pour clear les allocs*/
	return (0);
}
