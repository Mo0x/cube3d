/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 19:18:15 by mgovinda          #+#    #+#             */
/*   Updated: 2024/09/14 18:46:59 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

mlx_texture_t	*select_texture(t_data *c3d, t_ray *ray)
{
	if (ray->hit_type == DOOR_HIT)
	{
		if (c3d->door_texture)
			return (c3d->door_texture);
		else
			return (c3d->n_texture);
	}
	if (ray->side == 0)
	{
		if (ray->ray_dir_x > 0)
			return (c3d->e_texture);
		else
			return (c3d->w_texture);
	}
	else
	{
		if (ray->ray_dir_y > 0)
			return (c3d->s_texture);
		else
			return (c3d->n_texture);
	}
}

double	calculate_wall_x(t_data *c3d, t_ray *ray)
{
	double	wall_x;

	if (ray->side == 0)
		wall_x = c3d->player->pos_y + ray->perp_wall_dist * ray->ray_dir_y;
	else
		wall_x = c3d->player->pos_x + ray->perp_wall_dist * ray->ray_dir_x;
	wall_x -= floor(wall_x);
	return (wall_x);
}

int	calculate_texture_x(mlx_texture_t *texture, double wall_x)
{
	int	tex_x;

	tex_x = (int)(wall_x * (double)texture->width);
	if (tex_x < 0)
		tex_x = 0;
	if (tex_x >= (int)texture->width)
		tex_x = texture->width - 1;
	return (tex_x);
}

void	draw_vertical_line(t_data *c3d, mlx_texture_t *texture, t_ray *ray)
{
	int			y;
	int			tex_y;
	uint32_t	color;

	y = (int)ray->draw_start;
	while (y < (int)ray->draw_end)
	{
		tex_y = (int)ray->tex_pos;
		if (tex_y < 0)
			tex_y = 0;
		if (tex_y >= (int)texture->height)
			tex_y = texture->height - 1;
		color = get_texture_color(texture, ray->tex_x, tex_y);
		ft_warpper_put_pxl(c3d->img, ray->x, y, color);
		ray->tex_pos += ray->step;
		y++;
	}
}

void	ft_draw_wall(t_data *c3d, t_ray *ray, int x)
{
	mlx_texture_t	*texture;
	double			wall_x;

	ray->x = x;
	ray->line_height = (float)HEIGHT / ray->perp_wall_dist;
	if (ray->hit_type == DOOR_HIT)
		ray->line_height *= (1.0 - ray->door_open_amount);
	ray->draw_start = (-ray->line_height + HEIGHT) / 2;
	if (ray->draw_start < 0.0f)
		ray->draw_start = 0.0f;
	ray->draw_end = (ray->line_height + HEIGHT) / 2;
	if (ray->draw_end >= (float)HEIGHT)
		ray->draw_end = (float)HEIGHT - 1;
	texture = select_texture(c3d, ray);
	wall_x = calculate_wall_x(c3d, ray);
	ray->tex_x = calculate_texture_x(texture, wall_x);
	ray->step = texture->height / ray->line_height;
	ray->tex_pos = (ray->draw_start - HEIGHT / 2 + ray->line_height / 2) \
									* (ray->step);
	draw_vertical_line(c3d, texture, ray);
}

/*
void	ft_draw_wall(t_data *c3d, t_ray *ray, int x)
{
	int			y;
	uint32_t	color;

	ray->line_height = (float)HEIGHT / ray->perp_wall_dist;
	//printf(" line heigt = %f, height = %f, perp_wall %f\n", ray->line_height, (float)HEIGHT, ray->perp_wall_dist);
	ray->draw_start = (-ray->line_height + HEIGHT) / 2;
	if (ray->draw_start < 0.0f)
		ray->draw_start = 0.0f;
	ray->draw_end = (ray->line_height + HEIGHT) / 2;
	if (ray->draw_end >= (float)HEIGHT)
		ray->draw_end = (float)HEIGHT - 1;
	//TODO setup texture
	y = ray->draw_start;
	while (y < ray->draw_end)
	{ */
		/*here load texture into a future ray->texture*/
		/*
		color = RED;
		ft_warpper_put_pxl(c3d->img, x, y++, color);
	}
}
*/