/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinto-r <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 18:21:18 by rpinto-r          #+#    #+#             */
/*   Updated: 2022/03/29 00:46:08 by rpinto-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push(t_stack **from, t_stack **to)
{
	t_element	*first;

	if ((*from)->size < 1)
		return (-1);
	first = (*from)->first;
	if (!(*from)->first->next)
	{
		(*from)->first = 0;
		(*from)->last = 0;
	}
	else
	{
		(*from)->first = (*from)->first->next;
		(*from)->first->prev = 0;
	}
	first->prev = 0;
	first->next = 0;
	insert_at_start(to, first);
	(*from)->size--;
	return (0);
}

int	push_b(t_stack **a, t_stack **b)
{
	ft_putendl_fd("pb", 1);
	return (push(a, b));
}

int	push_a(t_stack **a, t_stack **b)
{
	ft_putendl_fd("pa", 1);
	return (push(b, a));
}
