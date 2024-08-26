/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 14:44:27 by mgovinda          #+#    #+#             */
/*   Updated: 2024/08/26 18:49:40 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H

# define CUB3D_H
# include "types.h"
# include "../libft/includes/libft.h"
# include <unistd.h>
# include <MLX42/MLX42.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/time.h>
# include <math.h>
# include <string.h>
# include <fcntl.h>
# include "parsing.h"

/* temporary color*/
# define BLACK 0x000000FF
# define WHITE 0xFFFFFFFF
# define RED 0xFF0000FF
# define GREEN 0x00FF00FF
# define YELLOW 0xFFFF00FF
# define BLUE 0x0000FFFF

void	exit_exclaim(char *string);
void	parsing(t_map *map, char **filename, int argc, t_data *c3d);
void	ft_start_game(t_data *c3d);
void	ft_draw_vertical(t_data *c3d, t_ray *ray, int x);
size_t	give_me_time(void);

#endif