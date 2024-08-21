/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 18:03:38 by mgovinda          #+#    #+#             */
/*   Updated: 2024/08/21 16:30:32 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/* 
void	game_loop(void *ml)
{
	mlx_t	*mlx;

	mlx = ml;
	
} */

void	ft_start_game(t_data *c3d)
{
	//ft_init(c3d);
	c3d->mlx = mlx_init(WIDTH, HEIGHT, "MLX42", FALSE);
	if (!(c3d->mlx))
		exit_exclaim("Couldn't initialize mlx :(\n");
	c3d->img = mlx_new_image(c3d->mlx, WIDTH, HEIGHT);
	if (!(c3d->img))
	{
		mlx_close_window(c3d->mlx);
		exit_exclaim("Couldn't initialize image :(\n");
	}
	/* set hook here*/	
}