/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   abs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 18:09:02 by mgovinda          #+#    #+#             */
/*   Updated: 2024/08/22 18:10:47 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_abs_int(int n)
{
	if (n < 0)
		return (-n);
	else
		return (n);
}

double	ft_abs_double(double n)
{
	if (n < 0)
		return (-n);
	else
		return (n);
}