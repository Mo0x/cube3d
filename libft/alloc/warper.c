/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   warper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 10:29:45 by mgovinda          #+#    #+#             */
/*   Updated: 2024/08/12 10:33:47 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*walloc(int size)
{
	return (alloc(size, 1, NULL));
}

void	wfree(void *ptr)
{
	alloc(0, 2, ptr);
}

void wclear(void)
{
	alloc(0, 0, NULL);
}