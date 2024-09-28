/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 19:16:34 by wkeiser           #+#    #+#             */
/*   Updated: 2024/09/28 18:57:01 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// WORK IN PROGRESSSSSS : a add dans cub3d.h quand sera debuté

#ifndef PARSING_H

# define PARSING_H
# include "types.h"

// dans parsing_get_color_and_texture
void	colors_harvester(t_data *c3d);

// dans parse_utils.c
void	filename_check(char *filename);
void	skip_spaces(char **str);

// dans texture_check.c
void	check_textures(t_data *c3d);

// dans color_
void	setup_colors(t_data *c3d);

// dans parse_map.c
void	parse_map(t_map *map, t_data *c3d);

// dans map_array.c
void	add_line(t_data *c3d, char *to_add);
void	finalize_map_validation(t_data *c3d);
void	remove_newline(char *line);

// dans map_check.c
int		map_check(char **line, t_data *c3d);
void	is_there_a_gift_after_map(int fd, char *line, t_data *c3d);
void	check_single_spawn_point(t_data *c3d);

// dans map_enclosure_check.c
int		is_enclosed_by_walls_or_0(t_map *map, int x, int y);
int		is_enclosed_by_walls_or_spaces(t_map *map, int x, int y);

// dans array_utils.c
void	arrcpy(char **src, char **dest);
int		arrsize(char **array);
void	free_arr(char **to_free);
int		init_map_arr(t_map *map, char *to_add, int size);
int		expand_map_arr(t_map *map, char *to_add, int size);

// dans map_row.c
void	validate_rows(t_data *c3d);

#endif
