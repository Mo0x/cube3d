/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 14:47:18 by mgovinda          #+#    #+#             */
/*   Updated: 2024/08/12 12:54:30 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	exit_exclaim(char *string)
{
	ft_printf(1, "%s", string);
	/*
	Je n ai pas inclu de free car ajout du garbage collector pour tout free ?
	Fonction a add autre part que parsing eventuellement / repertoire check ou err ?
	*/
	wclear();
	exit (1);
}

int	main(int argc, char **argv)
{
	t_data	*c3d;
	
	c3d = walloc(sizeof(t_data));
	if (!c3d)
		exit_exclaim("c3d malloc failed\n");
	c3d->map = walloc(sizeof(t_map));
	if (!c3d->map)
		exit_exclaim("c3d->map malloc failed\n");
	parsing(c3d->map, argv, argc, c3d);
	printf("North path :%s\n", c3d->map->n_path);
	printf("S path :%s\n", c3d->map->s_path);
	printf("W path :%s\n", c3d->map->w_path);
	printf("E path :%s\n", c3d->map->e_path);
	printf("Converted ceiling color: 0x%X\n", c3d->floorcolor); //testing hexa conversion color
	printf("Converted floor color: 0x%X\n", c3d->ceilingcolor); //testing hexa conversion color
	wclear();
	return (0);
}
