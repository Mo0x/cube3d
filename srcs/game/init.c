/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 18:03:38 by mgovinda          #+#    #+#             */
/*   Updated: 2024/08/13 18:48:09 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_init(t_data *c3d)
{
	c3d->player = walloc(sizeof(t_plyer));
	if (!c3d->player)
		exit_exclaim("Error malloc\n");
	c3d->ray = walloc(sizeof(t_ray));
	if (!c3d->ray)
		exit_exclaim("Error malloc\n");
	/*here ini player and perhaps ray for data struct*/
}
/* 
void	game_loop(void *ml)
{
	mlx_t	*mlx;

	mlx = ml;
	
} */

void	ft_start_game(t_data *c3d)
{
	ft_init(c3d);
	c3d->mlx = mlx_init(WIDTH, HEIGHT, "MLX42", FALSE);
	if (!(c3d->mlx))
		exit_exclaim("Couldn't initialize mlx ;(\n");
	c3d->img = mlx_new_image(c3d->mlx, WIDTH, HEIGHT);
	if (!(c3d->img))
	{
		mlx_close_window(c3d->mlx);
		exit_exclaim("Couldn't initialize image :(\n");
	}
}