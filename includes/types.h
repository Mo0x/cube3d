/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2024/08/21 16:24:53 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef TYPES_H
# define TYPES_H
# define HEIGHT 800
# define WIDTH 800
# define TRUE 1
# define FALSE 0
# include <MLX42/MLX42.h>
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

/*
typedef struct s_img
{

}				t_img;
*/

typedef struct s_data
{
	t_map		*map;
	int			floorcolor;
	int			ceilingcolor;
	mlx_t		*mlx;
	mlx_image_t *img;
}				t_data;

#endif
