/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinto-r <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 22:15:55 by rpinto-r          #+#    #+#             */
/*   Updated: 2022/03/29 00:46:08 by rpinto-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap(t_stack **stack)
{
	t_element	*first;
	t_element	*second;

	if ((*stack)->size < 2)
		return (-1);
	first = (*stack)->first;
	second = (*stack)->first->next;
	first->next = second->next;
	first->prev = second;
	second->next = first;
	second->prev = 0;
	(*stack)->first = second;
	return (0);
}

int	swap_a(t_stack **a)
{
	ft_putendl_fd("sa", 1);
	return (swap(a));
}

int	swap_b(t_stack **b)
{
	ft_putendl_fd("sb", 1);
	return (swap(b));
}

int	swap_s(t_stack **a, t_stack **b)
{
	ft_putendl_fd("ss", 1);
	swap(a);
	swap(b);
	return (0);
}
