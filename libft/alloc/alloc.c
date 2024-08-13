/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 14:58:29 by mgovinda          #+#    #+#             */
/*   Updated: 2024/08/13 17:47:01 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdio.h>
#define HASH_SIZE 1024

unsigned int	hashf(void *p, int size)
{
	unsigned long long	value;
	unsigned int		hash;
	size_t				i;
	size_t				s;

	value = (unsigned long long)p;
	i = 0;
	hash = 0;
	s = sizeof(value);
	while (i < s)
	{
		hash += ((value >> (i * 8)) & 0xFF);
		hash += (hash << 10);
		hash ^= (hash >> 6);
		i++;
	}
	hash += (hash << 3);
	hash ^= (hash >> 11);
	hash += (hash << 15);
	return (hash % size);
}

void	*alloc_new(t_list *allocs[HASH_SIZE], int size)
{
	t_list	*newnode;
	void	*newalloc;

	newalloc = malloc(size);
	if (!newalloc)
		return (NULL);
	newnode = ft_lstnew(newalloc);
	if (!newnode)
	{
		free(newalloc);
		return (NULL);
	}
	ft_lstadd_front(&allocs[hashf(newalloc, HASH_SIZE)], newnode);
	return (newalloc);
}

void	clear_all(t_list *allocs[HASH_SIZE])
{
	int	i;

	i = 0;
	while (i < HASH_SIZE)
	{
		if (allocs[i])
			clear_alloc(&allocs[i]);
		i++;
	}

}

void print_size(t_list *allocs[HASH_SIZE])
{
	int		i;
	int		size;
	t_list	*ptr;

	i = 0;
	size = 0;
	while (i < HASH_SIZE)
	{
		ptr = allocs[i];
		while (ptr)
		{
			size += sizeof(ptr->content);
			ptr = ptr->next;
		}
		i++;
	}
	printf("allocator size: %d\n", size);
}

void *alloc(int size, int type, void *ptr)
{
	static t_list	*allocs[HASH_SIZE];

	if (type == 1)
		return (alloc_new(allocs, size));
	else if (type == 2)
		del_one(&allocs[hashf(ptr, HASH_SIZE)], ptr);
	else if (type == 0)
		clear_all(allocs);
	else if (type == 3)
		print_size(allocs);
	return (NULL);
}