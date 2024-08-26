/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   warper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 10:29:45 by mgovinda          #+#    #+#             */
/*   Updated: 2024/08/26 19:08:36 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	clear_alloc(t_list **h)
{
	t_list	*t;

	while (*h)
	{
		t = (*h)->next;
		free((*h)->content);
		free(*h);
		*h = t;
	}
}

void	*walloc(int size)
{
	return (alloc(size, 1, NULL));
}

void	wfree(void *ptr)
{
	alloc(0, 2, ptr);
}

void	wclear(void)
{
	alloc(0, 0, NULL);
}

void	del_one(t_list **h, void *to_del)
{
	t_list	*ptr;

	ptr = *h;
	if (h)
	{
		while (ptr)
		{
			if (ptr->next && ptr->next->content == to_del)
			{
				if (ptr->next->next)
					ptr->next = ptr->next->next;
				else
					ptr->next = NULL;
				free(ptr->next->content);
				free(ptr->next);
			}
			ptr = ptr->next;
		}
	}
}
