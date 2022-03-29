/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinto-r <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 17:51:38 by rpinto-r          #+#    #+#             */
/*   Updated: 2022/03/29 00:46:08 by rpinto-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*sort_nbrs(int *nbrs, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = -1;
	nbrs = nbrs_duplicate(nbrs, size);
	while (++i < size - 1)
	{
		j = -1;
		while (++j < size - i - 1)
		{
			if (nbrs[j] > nbrs[j + 1])
			{
				tmp = nbrs[j];
				nbrs[j] = nbrs[j + 1];
				nbrs[j + 1] = tmp;
			}
		}
	}
	return (nbrs);
}

int	is_sorted_asc(t_stack **stack)
{
	int			value;
	t_element	*current;

	current = (*stack)->first;
	value = current->value;
	while (current)
	{
		if (current->value < value)
			return (0);
		value = current->value;
		current = current->next;
	}
	return (1);
}

int	is_sorted_desc(t_stack **stack)
{
	int			value;
	t_element	*current;

	current = (*stack)->last;
	value = current->value;
	while (current)
	{
		if (current->value < value)
			return (0);
		value = current->value;
		current = current->prev;
	}
	return (1);
}
