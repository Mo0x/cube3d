/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 14:47:18 by mgovinda          #+#    #+#             */
/*   Updated: 2024/08/13 18:25:50 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"



int	main(int argc, char **argv)
{
	t_data	*c3d;
	
	c3d = walloc(sizeof(t_data));
	if (!c3d)
		exit_exclaim("c3d malloc failed\n");
	c3d->map = walloc(sizeof(t_map));
	if (!c3d->map)
		exit_exclaim("c3d->map malloc failed\n");
	alloc(0, 3, NULL);
	char *ptr = walloc(1025);
	alloc(0, 3, NULL);
	printf("free\n");
	wfree(ptr);
	alloc(0, 3, NULL);

	parsing(c3d->map, argv, argc, c3d);
	printf("North path :%s\n", c3d->map->n_path);
	printf("S path :%s\n", c3d->map->s_path);
	printf("W path :%s\n", c3d->map->w_path);
	printf("E path :%s\n", c3d->map->e_path);
	printf("Converted ceiling color: 0x%X\n", c3d->floorcolor); //testing hexa conversion color
	printf("Converted floor color: 0x%X\n", c3d->ceilingcolor); //testing hexa conversion color
	/* ft_start_game(c3d)*/
	wclear(); /* <---- a mettre a chaque fin dexec pour clear les allocs*/
	return (0);
}
