/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinto-r <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 15:04:35 by rpinto-r          #+#    #+#             */
/*   Updated: 2022/03/29 02:12:05 by rpinto-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	init_stack(t_stack **stack)
{
	(*stack) = malloc(sizeof(t_stack));
	if (!(*stack))
		return (-1);
	(*stack)->first = 0;
	(*stack)->last = 0;
	(*stack)->size = 0;
	(*stack)->nbrs = 0;
	(*stack)->nbrs_sorted = 0;
	return (0);
}

void	fill_stack(t_stack **stack, char **strs)
{
	int	i;
	int	j;
	int	size;

	size = strs_length(strs);
	(*stack)->nbrs = strs_to_nbrs(strs);
	(*stack)->nbrs_sorted = sort_nbrs((*stack)->nbrs, size);
	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size)
		{
			if ((*stack)->nbrs[i] == (*stack)->nbrs_sorted[j])
				insert_at_end(stack, new_element(j));
		}
	}
}

void	sort_stack(t_stack **a, t_stack **b)
{
	int	size;

	size = (*a)->size;
	if (size == 1 || is_sorted_asc(a))
		return ;
	else if (size == 2)
		sort_two(a);
	else if (size == 3)
		sort_three(a);
	else if (size > 3 && size < 6)
		sort_five(a, b);
	else
		sort_big(a, b);
}

char	**parse_args(char **strs, int size)
{
	int	i;

	i = -1;
	if (size == 1)
		strs = ft_split(strs[0], ' ');
	else
		strs = strs_duplicate(strs);
	if (!*strs)
		exit(0);
	while (strs && strs[++i])
	{	
		if (is_invalid_number(strs[i]))
			args_error(ERR_INVALID_NUMBER, strs);
		if (is_number_overflow(strs[i]))
			args_error(ERR_NUMBER_OVERFLOW, strs);
		if (is_number_duplicated(strs, i))
			args_error(ERR_NUMBER_DUPLICATED, strs);
	}
	return (strs);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	**strs;

	if (argc > 1)
	{
		strs = parse_args(++argv, --argc);
		init_stack(&a);
		init_stack(&b);
		fill_stack(&a, strs);
		sort_stack(&a, &b);
		free_strs(strs);
		free_stack(&a);
		free_stack(&b);
	}
}
