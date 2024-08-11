/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 14:44:27 by mgovinda          #+#    #+#             */
/*   Updated: 2024/08/04 17:28:28 by mgovinda         ###   ########.fr       */
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

void	exit_exclaim(char *string);
void	parsing(t_map *map, char **filename, int argc, t_data *c3d);

#endif