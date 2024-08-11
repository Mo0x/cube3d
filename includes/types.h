/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkeiser <wkeiser@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 22:29:40 by wkeiser           #+#    #+#             */
/*   Updated: 2024/08/11 22:29:45 by wkeiser          ###   ########.fr       */
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

#endif
