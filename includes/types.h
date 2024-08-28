/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2024/08/28 19:03:49 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef TYPES_H
# define TYPES_H
# define HEIGHT 1280
# define WIDTH 720
# define TRUE 1
# define FALSE 0
# include <MLX42/MLX42.h>

typedef struct s_map
{
	char	*line;
	char	*n_path;
	char	*s_path;
	char	*w_path;
	char	*e_path;
	char	*ccolor;
	char	*fcolor;
	int		fd;
	char	**map_arr;
}			t_map;

/*
typedef struct s_img
{

}				t_img;
*/

typedef	struct s_rect
{
	int	x_start;
	int	x_end;
	int	y_start;
	int	y_end;
	int	color;
}			t_rect;

typedef struct	s_ray
{
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	int		map_x;
	int		map_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_x;
	double	delta_y;
	double	perp_wall_dist;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	int		line_height;
	int		draw_start;
	int		draw_end;
}				t_ray;

typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	float	cam_speed;
	float	move_speed;

}				t_player;

typedef struct s_data
{
	t_map			*map;
	int				floorcolor;
	int				ceilingcolor;
	mlx_t			*mlx;
	mlx_image_t 	*img;
	mlx_image_t 	*img_minimap;
	mlx_image_t 	*img_sprite;
	struct s_player	*player;
	double			start_time;
	double			time;
	double			old_time;
	double			frame;
	int				refresh;
}				t_data;

#endif
