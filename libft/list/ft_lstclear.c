/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 17:01:12 by mgovinda          #+#    #+#             */
/*   Updated: 2024/08/26 19:05:49 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current;

	(void)del;
	if (lst && (*del))
	{
		while (*lst)
		{
			current = *lst;
			*lst = current->next;
			wfree(current);
		}
	}
	lst = NULL;
}
