/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 17:01:05 by mgovinda          #+#    #+#             */
/*   Updated: 2024/08/28 17:46:21 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_roof_and_ground(t_data *c3d)
{
	(void)c3d;
}

void	render(t_data *c3d)
{
	if (c3d->refresh)
	{
		ft_clear_image(c3d->img, 0);
		ft_clear_image(c3d->img_minimap, 0);
		ft_roof_and_ground(c3d);
	}
}