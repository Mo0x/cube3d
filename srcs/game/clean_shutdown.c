/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_shutdown.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 17:56:20 by mgovinda          #+#    #+#             */
/*   Updated: 2024/09/28 19:03:34 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_escape(mlx_key_data_t keydata, void *c4d)
{
	t_data	*c3d;

	c3d = c4d;
	if (keydata.key == MLX_KEY_ESCAPE)
	{
		ft_clean_shutdown(c3d);
		exit(0);
	}
}

void	ft_clean_shutdown(t_data *c3d)
{
	ft_clean_up(c3d);
	wclear();
}
