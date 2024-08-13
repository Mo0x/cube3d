/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 17:59:21 by mgovinda          #+#    #+#             */
/*   Updated: 2024/08/13 18:00:11 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	exit_exclaim(char *string)
{
	ft_printf(1, "%s", string);
	/*
	Je n ai pas inclu de free car ajout du garbage collector pour tout free ?
	Fonction a add autre part que parsing eventuellement / repertoire check ou err ?
	*/
	wclear();
	exit (1);
}