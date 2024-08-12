/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 16:15:24 by mgovinda          #+#    #+#             */
/*   Updated: 2024/08/12 10:41:14 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	tot_length;
	char	*ret;
	char	*begin;

	if (!s1 && !s2)
		return (NULL);
	tot_length = ft_strlen(s1) + ft_strlen(s2);
	ret = (char *)walloc(sizeof(char) * (tot_length + 1));
	if (!ret)
		return (NULL);
	begin = ret;
	while (*s1)
		*ret++ = *s1++;
	while (*s2)
		*ret++ = *s2++;
	*ret = 0;
	return (begin);
}
