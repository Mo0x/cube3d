/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_shutdown.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 17:56:20 by mgovinda          #+#    #+#             */
/*   Updated: 2024/09/17 18:14:20 by mgovinda         ###   ########.fr       */
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
	/* here the open door key*/
}

void	ft_clean_shutdown(t_data *c3d)
{
	wclear();
	/*mlx_delete_texture here*/
	if (c3d->mlx)
		mlx_terminate(c3d->mlx);
}