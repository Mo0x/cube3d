/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkeiser <wkeiser@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 18:25:06 by wkeiser           #+#    #+#             */
/*   Updated: 2024/08/11 18:25:08 by wkeiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	filename_check(char *filename)
{
	if (ft_strlen(filename) == 4) //check si fichier est appele .cub
	{
		ft_printf(1, "Wrong filename\n");
		exit (1);
	}
	while (*filename != '.')
		filename++;
	if (ft_strnstr(filename, ".cub", 4) == 0 || ft_strlen(filename) != 4)
	{
		ft_printf(1, "Wrong file extension\n");
		exit (1);
	}
}

void	skip_spaces(char **str)
{
	while (**str == ' ')
		(*str)++;
}
