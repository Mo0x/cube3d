/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 16:43:44 by mgovinda          #+#    #+#             */
/*   Updated: 2024/08/12 10:41:15 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*ret;
	int		i;
	int		size;

	if (!s)
		return (NULL);
	i = -1;
	size = ft_strlen(s);
	ret = walloc(sizeof(char) * (size + 1));
	if (!ret)
		return (NULL);
	while (++i < size)
		ret[i] = (*f)(i, s[i]);
	ret[i] = 0;
	return (ret);
}
