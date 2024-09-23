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
# define WALL_HIT 1
# define DOOR_HIT 2
# define DOOR_OPEN_TIME 1.0 
# define DOOR_STAY_OPEN_TIME 3.0
# define DOOR_CLOSED 0
# define DOOR_OPENING 1
# define DOOR_OPEN 2
# define DOOR_CLOSING 3

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

typedef struct s_rect
{
	int				x_start;
	int				x_end;
	int				y_start;
	int				y_end;
	unsigned int	color;
}			t_rect;

/* perhaps need to convert line height draw_start and draw_end into float*/

typedef struct s_ray
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
	int		x;
	int		tex_x;
	double	tex_pos;
	double	step;
	int		hit_type; //wall oder door
	double	door_open_amount;
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

typedef struct s_door
{
	int				x; //pos x et y
	int				y;
	int				state; // 0 fermee 1 ouvert
	float			open_amount; // variable allant de 0.0 a 1.0
	double			timer; // temps depuis ouverture 3 sec se ferme
	struct s_door	*next;
}					t_door;

typedef struct s_data
{
	t_map			*map;
	int				floorcolor;
	int				ceilingcolor;
	mlx_t			*mlx;
	mlx_image_t		*img;
	mlx_image_t		*img_minimap;
	mlx_image_t		*img_sprite;
	mlx_texture_t	*n_texture;
	mlx_texture_t	*e_texture;
	mlx_texture_t	*w_texture;
	mlx_texture_t	*s_texture;
	mlx_texture_t	*door_texture;
	struct s_player	*player;
	double			start_time;
	double			time;
	double			old_time;
	double			frame;
	int				refresh;
	int				is_moving;
	t_door			*doors;
}				t_data;

typedef struct s_pos
{
	int	x;
	int	y;
	int	px;
	int	py;
	int	dx;
	int	dy;
}		t_pos;

#endif
