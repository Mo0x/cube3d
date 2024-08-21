/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 22:29:40 by wkeiser           #+#    #+#             */
/*   Updated: 2024/08/21 17:03:56 by mgovinda         ###   ########.fr       */
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
}			t_map;

/*
typedef struct s_img
{

}				t_img;
*/

/*
pos_x/y == position vector of the player
dir_x/y == direction of the player 
plane_x/y == camera plane of the player
*/
typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
}				t_player;

typedef struct s_data
{
	t_map			*map;
	int				floorcolor;
	int				ceilingcolor;
	mlx_t			*mlx;
	mlx_image_t		*img;
	struct s_player	*player;
	double			time;
	double			old_time;
}					t_data;

#endif
