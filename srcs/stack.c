/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinto-r <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 17:50:44 by rpinto-r          #+#    #+#             */
/*   Updated: 2022/03/29 00:46:08 by rpinto-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_element	*new_element(int value)
{
	t_element	*element;

	element = malloc(sizeof(*element));
	if (!element)
		return (0);
	element->value = value;
	element->prev = 0;
	element->next = 0;
	return (element);
}

int	insert_at_start(t_stack **stack, t_element *element)
{
	if (!element)
		return (-1);
	if (!(*stack)->first)
	{
		(*stack)->first = element;
		(*stack)->last = element;
	}
	else
	{
		element->prev = 0;
		element->next = (*stack)->first;
		(*stack)->first->prev = element;
		(*stack)->first = element;
	}
	(*stack)->size++;
	return (0);
}

int	insert_at_end(t_stack **stack, t_element *element)
{
	if (!element)
		return (-1);
	if (!(*stack)->last)
	{
		(*stack)->first = element;
		(*stack)->last = element;
	}
	else
	{
		element->prev = (*stack)->last;
		element->next = 0;
		(*stack)->last->next = element;
		(*stack)->last = element;
	}
	(*stack)->size++;
	return (0);
}

int	insert_at_index(t_stack **stack, t_element *element, int index)
{
	int			i;
	t_element	*current;

	i = -1;
	current = (*stack)->first;
	while (++i < index)
		current = current->next;
	element->next = current;
	element->prev = current->prev;
	if (!current->prev)
		(*stack)->first = element;
	else
		current->prev->next = element;
	current->prev = element;
	(*stack)->size++;
	return (0);
}
