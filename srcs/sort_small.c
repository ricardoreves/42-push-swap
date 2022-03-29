/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinto-r <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 15:52:15 by rpinto-r          #+#    #+#             */
/*   Updated: 2022/03/29 00:46:08 by rpinto-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_stack **a)
{
	int	first;
	int	last;

	first = (*a)->first->value;
	last = (*a)->last->value;
	if (first > last)
		swap_a(a);
}

void	sort_three(t_stack **a)
{
	int	first;
	int	middle;
	int	last;

	if (!(*a)->first)
		return ;
	first = (*a)->first->value;
	middle = (*a)->first->next->value;
	last = (*a)->last->value;
	if (first < middle && middle > last && first < last)
	{
		swap_a(a);
		rotate_a(a);
	}
	else if (first > middle && middle < last && first < last)
		swap_a(a);
	else if (first < middle && middle > last && first > last)
		reverse_rotate_a(a);
	else if (first > middle && middle < last && first > last)
		rotate_a(a);
	else if (first > middle && middle > last && first > last)
	{
		rotate_a(a);
		swap_a(a);
	}
}

void	sort_five(t_stack **a, t_stack **b)
{
	int	min;

	while ((*a)->size > 3)
	{
		min = get_min_value(a);
		if ((*a)->last->value == min)
			reverse_rotate_a(a);
		if ((*a)->first->value == min)
			push_b(a, b);
		else
			rotate_a(a);
	}
	sort_three(a);
	while ((*b)->size)
		push_a(a, b);
}
