/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinto-r <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 22:14:32 by rpinto-r          #+#    #+#             */
/*   Updated: 2022/03/29 00:46:08 by rpinto-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	reverse_rotate(t_stack **stack)
{
	t_element	*last;

	if ((*stack)->size < 2)
		return (-1);
	last = (*stack)->last;
	(*stack)->last = (*stack)->last->prev;
	(*stack)->last->next = 0;
	last->next = (*stack)->first;
	last->prev = 0;
	(*stack)->first->prev = last;
	(*stack)->first = last;
	return (0);
}

int	reverse_rotate_a(t_stack **a)
{
	ft_putendl_fd("rra", 1);
	return (reverse_rotate(a));
}

int	reverse_rotate_b(t_stack **b)
{
	ft_putendl_fd("rrb", 1);
	return (reverse_rotate(b));
}

int	reverse_rotate_s(t_stack **a, t_stack **b)
{
	ft_putendl_fd("rrr", 1);
	reverse_rotate(a);
	reverse_rotate(b);
	return (0);
}
