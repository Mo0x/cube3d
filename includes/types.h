/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2024/09/11 17:48:28 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef TYPES_H
# define TYPES_H
# define HEIGHT 720
# define WIDTH 1280
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
	int		width;
	int		height;
}			t_map;

/*
typedef struct s_img
{

}				t_img;
*/

typedef	struct s_rect
{
	int				x_start;
	int				x_end;
	int				y_start;
	int				y_end;
	unsigned int	color;
}			t_rect;

/* perhaps need to convert line height draw_start and draw_end into float*/

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
	float	line_height;
	float	draw_start;
	float	draw_end;
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
	char	dir;
	t_ray	*ray;
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
