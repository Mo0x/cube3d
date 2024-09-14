/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkeiser <wkeiser@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 10:51:15 by wkeiser           #+#    #+#             */
/*   Updated: 2024/08/29 10:51:16 by wkeiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIMAP_H
# define MINIMAP_H

# include "types.h"
# define MINIMAP_CELL_SIZE 16
# define MINIMAP_IMG_SIZE 200
# define MINIMAP_OFF_X 10
# define MINIMAP_OFF_Y 10

// dans minimap.c
void	draw_minimap(t_data *c3d);

#endif
