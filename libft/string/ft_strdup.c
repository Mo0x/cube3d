/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 16:34:50 by mgovinda          #+#    #+#             */
/*   Updated: 2024/08/12 10:41:12 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*ret;
	int		i;

	ret = walloc(sizeof(char) * (ft_strlen(s) + 1));
	i = -1;
	if (!ret)
		return (NULL);
	while (++i < (int)ft_strlen(s))
		ret[i] = s[i];
	ret[i] = 0;
	return (ret);
}
