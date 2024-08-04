/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgovinda <mgovinda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 14:58:29 by mgovinda          #+#    #+#             */
/*   Updated: 2024/08/04 17:06:41 by mgovinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

#define HASH_SIZE 8192

unsigned int	hashf(void *p, int size)
{
	unsigned long long	value;
	unsigned int		hash;
	size_t				i;
	size_t				size;

	value = (unsigned long long)p;
	i = 0;
	hash = 0;
	size = sizeof(value);
	while (i < size)
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


void *alloc(int size, int type, void *ptr)
{
	static t_list	*allocs[HASH_SIZE];

	if (type == 1)
		return (alloc_new(allocs, size));
	else if (type == 2)
		ft_lstdelone(&allocs[hashf(ptr, HASH_SIZE)], ptr);
	else if (type == 0)
		clear_all(allocs);
	else if (type == 3)
		print_size(allocs);
	return (NULL);
}