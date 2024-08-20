/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkeiser <wkeiser@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 23:00:15 by wkeiser           #+#    #+#             */
/*   Updated: 2024/08/15 23:00:17 by wkeiser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	arrcpy(char **src, char **dest)
{
	int	i;

	i = 0;
	while (src[i] != NULL)
	{
		dest[i] = ft_strdup(src[i]); // check si fctionne pas ?
		i++;
	}
}

int	arrsize(char **array)
{
	int	i;

	i = 0;
	while (array[i] != NULL)
		i++;
	return (i);
}

void	free_arr(char **to_free)
{
	int	i;

	i = 0;
	while (to_free[i] != NULL)
	{
		wfree(to_free[i]);
		i++;
	}
	wfree(to_free);
}
