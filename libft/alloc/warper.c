/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   warper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 10:29:45 by mgovinda          #+#    #+#             */
/*   Updated: 2024/08/29 19:49:52 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	clear_alloc(t_list **h)
{
	t_list	*t;

	while (*h)
	{
		t = (*h)->next;
		if ((*h)->content)
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
	t_list	*prev;

	ptr = *h;
	prev = NULL;
	if (!h || !*h)
		return ;
	while (ptr && ptr->content != to_del)
	{
		prev = ptr;
		ptr = ptr->next;
	}
	if (ptr == NULL)
		return ;
	if (prev == NULL)
		*h = ptr->next;
	else
		prev->next = ptr->next;
	if (ptr->content)
		free(ptr->content);
	free(ptr);
}
