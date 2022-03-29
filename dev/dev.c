/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dev.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinto-r <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 15:55:44 by rpinto-r          #+#    #+#             */
/*   Updated: 2022/03/29 02:21:53 by rpinto-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_nbrs(int *nbrs, int size)
{
	int	i;

	i = 0;
	printf("---NBRS---\n");
	while (i < size)
	{
		printf("[%d] %d\n", i, nbrs[i]);
		i++;
	}
	printf("\n");
}

void	print_strs(char **strs)
{
	int	i;

	i = 0;
	printf("---STRS---\n");
	while (strs[i])
	{
		printf("[%d] %s\n", i, strs[i]);
		i++;
	}
	printf("\n");
}

int	get_prev_value(t_stack *stack)
{
	if (tmp->prev)
		return (tmp->prev->value);
	return (0);
}

int	get_next_value(t_stack *stack)
{
	if (tmp->next)
		return (tmp->next->value);
	return (0);
}

void	print_stack(t_stack **stack)
{
	t_element	*tmp;

	printf("---STACK---\n");
	tmp = (*stack)->first;
	while (tmp)
	{
		printf("prev: %d curr: %d next: %d size: %d\n",
			get_prev_value(tmp), tmp->value,
			get_next_value(tmp), (*stack)->size);
		tmp = tmp->next;
	}
}
