/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinto-r <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 22:13:57 by rpinto-r          #+#    #+#             */
/*   Updated: 2022/03/29 00:46:08 by rpinto-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rotate(t_stack **stack)
{
	t_element	*first;

	if ((*stack)->size < 2)
		return (-1);
	first = (*stack)->first;
	(*stack)->first = (*stack)->first->next;
	(*stack)->first->prev = 0;
	first->prev = (*stack)->last;
	first->next = 0;
	(*stack)->last->next = first;
	(*stack)->last = first;
	return (0);
}

int	rotate_a(t_stack **a)
{
	ft_putendl_fd("ra", 1);
	return (rotate(a));
}

int	rotate_b(t_stack **b)
{
	ft_putendl_fd("rb", 1);
	return (rotate(b));
}

int	rotate_s(t_stack **a, t_stack **b)
{
	ft_putendl_fd("rr", 1);
	rotate(a);
	rotate(b);
	return (0);
}
