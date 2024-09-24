/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 14:44:27 by mgovinda          #+#    #+#             */
/*   Updated: 2024/08/29 19:44:29 by mgovinda         ###   ########.fr       */
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
# include "minimap.h"

/* temporary color*/
# define BLACK 0x000000FF
# define WHITE 0xFFFFFFFF
# define RED 0xFF0000FF
# define GREEN 0x00FF00FF
# define YELLOW 0xFFFF00FF
# define BLUE 0x0000FFFF

/* Error*/
void	exit_exclaim(char *string, t_data *c3d);
void	ft_clean_up(t_data *c3d);

/*Parse*/
void	parsing(t_map *map, char **filename, int argc, t_data *c3d);

/*core*/
void	ft_start_game(t_data *c3d);
void	render(t_data *c3d);
void	ft_do_the_raycast(t_data *c3d);
void	ft_draw_wall(t_data *c3d, t_ray *ray, int x);
int		handle_door_cell(t_data *c3d, t_ray *ray);

/*mlx utils*/
void	ft_draw_vertical(t_data *c3d, t_ray *ray, int x);
void	ft_clear_image(mlx_image_t *img, int color);
void	ft_clear_mini_image(mlx_image_t *img, int color);
void	ft_draw_rectangle(mlx_image_t *img, t_rect rect);
void	ft_warpper_put_pxl(mlx_image_t *img, int x, int y, unsigned int color);

/*Move set*/
void	player_move(t_data *c3d, char *dir);
void	player_look(t_data *c3d, char *dir);

/*sprite*/
void	load_weapon_image(t_data *c3d, char *weapon_path);
void	update_weapon_sprite(t_data *c3d);
t_door	*find_door(t_data *c3d, int x, int y);
void	add_door(t_data *c3d, int x, int y);
void	update_doors(t_data *c3d);
void	handle_door_interaction(t_data *c3d);
void	close_door(t_door *door);
void	open_door(t_door *door);
void	update_doors(t_data *c3d);

/*minimap*/
void	draw_rect_minimap(mlx_image_t *img, t_rect *rect, t_pos pos);
void	draw_open_door_mini(t_data *c3d, t_rect rect);
void	draw_closed_door_mini(t_data *c3d, t_rect rect);
void	ft_draw_door_pixel_mini(t_data *c3d, int x, int y);
void	draw_minimap_door(t_data *c3d, float i, float j, t_door *door);

/*texture*/
void		init_wall_textures(t_data *c3d);
uint32_t	get_texture_color(mlx_texture_t *texture, int x, int y);


#endif