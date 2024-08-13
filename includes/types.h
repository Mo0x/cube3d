/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 22:29:40 by wkeiser           #+#    #+#             */
/*   Updated: 2024/08/13 17:58:32 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

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

typedef struct s_data
{
	t_map	*map;
	int		floorcolor;
	int		ceilingcolor;
}				t_data;

typedef struct s_ray
{
	double	ray_agl;
	double	distance;
	int		flag;
}				t_ray;

#endif
