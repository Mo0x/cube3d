/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkeiser <wkeiser@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 19:16:34 by wkeiser           #+#    #+#             */
/*   Updated: 2024/08/08 19:16:36 by wkeiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// WORK IN PROGRESSSSSS : a add dans cub3d.h quand sera debuté

#ifndef PARSING_H

# define PARSING_H
# include "types.h"


// dans parsing_get_color_and_texture
void	colors_harvester(t_map *map);

// dans parse_utils.c
void	filename_check(char *filename);
void	skip_spaces(char **str);

#endif
