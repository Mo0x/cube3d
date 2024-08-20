/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 22:29:40 by wkeiser           #+#    #+#             */
/*   Updated: 2024/08/13 18:41:29 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H
# define HEIGHT 800
# define WIDTH 800
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

typedef struct s_ray
{
	double	ray_agl;
	double	distance;
	int		flag;
}				t_ray;

typedef struct s_plyer
{
	int		plyer_x;
	int		plyer_y;
	double	angle;
	float	fov_rd;
	int		rotat;
	int		l_r;
	int		u_d;
}			t_plyer;

typedef struct s_data
{
	t_map		*map;
	int			floorcolor;
	int			ceilingcolor;
	mlx_t		*mlx;
	mlx_image_t	*img;
	t_ray		*ray;
	t_plyer		*player;
}				t_data;

#endif
