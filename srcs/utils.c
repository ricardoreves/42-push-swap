/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinto-r <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 16:51:43 by rpinto-r          #+#    #+#             */
/*   Updated: 2022/03/29 00:46:08 by rpinto-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	strs_length(char **strs)
{
	int	size;

	size = 0;
	while (strs[size])
		size++;
	return (size);
}

int	*nbrs_duplicate(int *nbrs, int size)
{
	int	*dup;

	dup = malloc(sizeof(*dup) * size);
	if (!dup)
		return (0);
	while (size--)
		dup[size] = nbrs[size];
	return (dup);
}

char	**strs_duplicate(char **strs)
{
	int		size;
	char	**dup;

	size = strs_length(strs);
	dup = malloc(sizeof(*dup) * (size + 1));
	if (!dup)
		return (0);
	dup[size] = 0;
	while (size--)
		dup[size] = ft_strdup(strs[size]);
	return (dup);
}

int	*strs_to_nbrs(char **strs)
{
	int	size;
	int	*nbrs;

	size = strs_length(strs);
	nbrs = malloc(sizeof(int) * size);
	if (!nbrs)
		return (0);
	while (size--)
		nbrs[size] = ft_atoi(strs[size]);
	return (nbrs);
}

void	args_error(char *msg, char **args)
{
	free(args);
	ft_putendl_fd(msg, 2);
	exit(1);
}
