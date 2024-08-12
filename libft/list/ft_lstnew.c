/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 14:39:56 by mgovinda          #+#    #+#             */
/*   Updated: 2024/08/12 10:41:06 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*ret;

	ret = walloc(sizeof(t_list));
	if (!ret)
		return (NULL);
	ret->content = content;
	ret->next = NULL;
	return (ret);
}
