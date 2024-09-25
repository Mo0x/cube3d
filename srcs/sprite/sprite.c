/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkeiser <wkeiser@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 22:24:50 by wkeiser           #+#    #+#             */
/*   Updated: 2024/08/31 22:24:51 by wkeiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/* float speed; Variable qui détermine la vitesse à laquelle le sprite moov */

void	update_moving(float *offset, int *direction)
{
	float	speed;

	speed = 0.5;
	if (*direction == 0)
		*direction = 1;
	*offset += *direction * speed;
	if (*offset > 10 || *offset < 0)
		*direction *= -1;
}

/*fonction qui verifie si le curseur est en haut au milieu ou en bas si neg 
monte si pos monte jusqua 10 pixels ou 1 pour deplacer dans l autre sens 
de maniere smoooth*/

void	update_idle(float *offset, int *direction)
{
	if (*offset > 0)
	{
		*offset -= 0.5;
		if (*offset < 0)
			*offset = 0;
	}
	else if (*offset < 0)
	{
		*offset += 0.5;
		if (*offset > 0)
			*offset = 0;
	}
	*direction = 0;
}

void	update_weapon_sprite(t_data *c3d)
{
	static float	offset;
	static int		direction;

	if (c3d->is_moving)
		update_moving(&offset, &direction);
	else
		update_idle(&offset, &direction);
	c3d->img_sprite->instances[0].y = (HEIGHT - c3d->img_sprite->height) \
					+ offset;
}

void	load_weapon_image(t_data *c3d, char *weapon_path)
{
	mlx_texture_t	*png_texture;

	if (access(weapon_path, F_OK) != 0)
	{
		exit_exclaim("weapon file doesn't exist.\n", c3d);
	}
	png_texture = mlx_load_png(weapon_path);
	if (!png_texture)
	{
		exit_exclaim("Error when loading the PNG file of the weapon.\n", c3d);
	}
	c3d->img_sprite = mlx_texture_to_image(c3d->mlx, png_texture);
	if (!c3d->img_sprite)
	{
		mlx_delete_texture(png_texture);
		exit_exclaim("Error converting png file in MLX file.\n", c3d);
	}
	mlx_delete_texture(png_texture);
}
