/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinto-r <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 20:57:30 by rpinto-r          #+#    #+#             */
/*   Updated: 2022/03/29 00:45:39 by rpinto-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_number_duplicated(char **strs, int index)
{
	int	i;

	i = -1;
	while (strs[++i])
		if (i != index && ft_strncmp(strs[i], strs[index], 12) == 0)
			return (1);
	return (0);
}

int	is_invalid_number(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (!(ft_isdigit(str[i]) || str[i] == '-'))
			return (1);
	return (0);
}

int	is_number_overflow(char *str)
{
	char	*tmp;

	tmp = ft_itoa(ft_atoi(str));
	if (ft_strncmp(str, tmp, ft_strlen(str)) != 0)
	{
		free(tmp);
		return (1);
	}
	free(tmp);
	return (0);
}
