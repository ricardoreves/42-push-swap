/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinto-r <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 20:20:18 by rpinto-r          #+#    #+#             */
/*   Updated: 2022/03/29 02:07:32 by rpinto-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define ERR_USAGE "Usage: ./push_swap [set of number] or [number] [number] ..."
# define ERR_INVALID_NUMBER "Error: invalid number"
# define ERR_NUMBER_OVERFLOW "Error: number overflow"
# define ERR_NUMBER_DUPLICATED "Error: duplicated number"

# include "libft.h"

typedef struct s_chunk
{
	int	pieces;
	int	size;
	int	start;
	int	end;
}	t_chunk;

typedef struct s_element
{
	int					value;
	struct s_element	*prev;
	struct s_element	*next;
}						t_element;

typedef struct s_stack
{
	int					size;
	int					*nbrs;
	int					*nbrs_sorted;
	struct s_element	*first;
	struct s_element	*last;
}						t_stack;

int			init_stack(t_stack **stack);
void		fill_stack(t_stack **stack, char **strs);
void		sort_stack(t_stack **a, t_stack **b);

void		free_stack(t_stack **stack);
void		free_strs(char **strs);

void		args_error(char *msg, char **args);
char		**parse_args(char **strs, int size);

int			is_sorted_asc(t_stack **stack);
int			is_sorted_desc(t_stack **stack);
int			is_invalid_number(char *str);
int			is_number_overflow(char *str);
int			is_number_duplicated(char **strs, int index);

t_element	*new_element(int value);
int			insert_at_end(t_stack **stack, t_element *element);
int			insert_at_index(t_stack **stack, t_element *element, int index);
int			insert_at_start(t_stack **stack, t_element *element);

int			push(t_stack **a, t_stack **b);
int			push_a(t_stack **a, t_stack **b);
int			push_b(t_stack **a, t_stack **b);

int			reverse_rotate(t_stack **stack);
int			reverse_rotate_a(t_stack **a);
int			reverse_rotate_b(t_stack **b);
int			reverse_rotate_s(t_stack **a, t_stack **b);

int			rotate(t_stack **stack);
int			rotate_a(t_stack **a);
int			rotate_b(t_stack **b);
int			rotate_s(t_stack **a, t_stack **b);

int			swap(t_stack **stack);
int			swap_a(t_stack **a);
int			swap_b(t_stack **b);
int			swap_s(t_stack **a, t_stack **b);

int			get_first_range_value(t_stack **stack, int start, int end);
int			get_value(t_stack **stack, int value);
int			get_max_value(t_stack **stack);
int			get_min_value(t_stack **stack);

void		sort_two(t_stack **a);
void		sort_three(t_stack **a);
void		sort_five(t_stack **a, t_stack **b);
void		sort_big(t_stack **a, t_stack **b);

int			*nbrs_duplicate(int *nbrs, int size);
int			*sort_nbrs(int *nbrs, int size);

int			strs_length(char **strs);
int			*strs_to_nbrs(char **strs);
char		**strs_duplicate(char **strs);
#endif