/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinto-r <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 16:00:14 by rpinto-r          #+#    #+#             */
/*   Updated: 2022/03/29 00:46:08 by rpinto-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_min_value(t_stack **stack)
{
	int			min;
	t_element	*tmp;

	tmp = (*stack)->first;
	if (!tmp)
		return (-1);
	min = tmp->value;
	while (tmp)
	{
		if (tmp->value < min)
			min = tmp->value;
		tmp = tmp->next;
	}
	return (min);
}

int	get_max_value(t_stack **stack)
{	
	int			max;
	t_element	*tmp;

	tmp = (*stack)->first;
	if (!tmp)
		return (-1);
	max = tmp->value;
	while (tmp)
	{
		if (tmp->value > max)
			max = tmp->value;
		tmp = tmp->next;
	}
	return (max);
}

int	get_value(t_stack **stack, int value)
{	
	int			i;
	t_element	*tmp;

	tmp = (*stack)->first;
	if (!tmp)
		return (-1);
	i = 0;
	while (tmp)
	{
		if (tmp->value == value)
			return (i);
		tmp = tmp->next;
		i++;
	}
	return (-1);
}

int	get_first_range_value(t_stack **stack, int start, int end)
{
	int			i;
	t_element	*tmp;

	tmp = (*stack)->first;
	if (!tmp)
		return (-1);
	i = 0;
	while (tmp)
	{
		if (tmp->value >= start && tmp->value <= end)
			return (i);
		tmp = tmp->next;
		i++;
	}
	return (-1);
}
