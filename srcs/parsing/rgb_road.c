/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_road.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkeiser <wkeiser@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 23:48:04 by wkeiser           #+#    #+#             */
/*   Updated: 2024/08/11 23:48:05 by wkeiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	check_space_in_str_color(char *arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		if (arr[i] == ' ')
			exit_exclaim("Found weird spaces in the string colors ! Why ?\n");
		i++;
	}
}

int	parse_rgb_component(char **str)
{
	int	value;

	value = ft_atoi(*str);
	while (**str && **str != ',')
		(*str)++;
	if (**str == ',')
		(*str)++;

	return (value);
}


/* validate fct pour verif si la string donnee comprend bien 2
virgules et qu apres la 2 eme virgule il y a une valeur*/
int	validate_rgb_format(char *str)
{
	int	count_comma;
	int	count_length;
	int	len;

	len = ft_strlen(str);
	count_comma = 0;
	count_length = 0;
	while (*str)
	{
		if (*str == ',' && (count_length + 1 != len))
			count_comma++;
		str++;
		count_length++;
	}
	return (count_comma == 2);
}

int	convert_rgb_str_to_int(char *rgb_str)
{
	int	r;
	int	g;
	int	b;

	r = parse_rgb_component(&rgb_str);
	g = parse_rgb_component(&rgb_str);
	b = parse_rgb_component(&rgb_str);
	if ((r < 0 || r > 255) || (g < 0 || g > 255) || (b < 0 || b > 255))
		exit_exclaim("Color value out of range\n");
	printf("R: %d, G: %d, B: %d\n", r, g, b); // test avant conversion
	return ((r << 16) | (g << 8) | b);
}

void	setup_colors(t_data *c3d)
{
	printf("before convert Color str ceiling :%s\n", c3d->map->ccolor); //test
	printf("before convert Color str floor :%s\n", c3d->map->fcolor); //test
	check_space_in_str_color(c3d->map->ccolor);
	check_space_in_str_color(c3d->map->fcolor);
	if (validate_rgb_format(c3d->map->ccolor) && \
		validate_rgb_format(c3d->map->fcolor))
	{
		c3d->floorcolor = convert_rgb_str_to_int(c3d->map->ccolor);
		c3d->ceilingcolor = convert_rgb_str_to_int(c3d->map->fcolor);
	}
	else
		exit_exclaim("Check your colors man\n");
	return ;
}