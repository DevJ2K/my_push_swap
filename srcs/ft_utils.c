/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 22:36:15 by tajavon           #+#    #+#             */
/*   Updated: 2023/11/29 17:52:17 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_nb_info(t_nb_info *nb_info, int nb, int index)
{
	nb_info->nb = nb;
	nb_info->index = index;
}

int	find_occurence(char c, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (c == str[i])
			return (1);
		i++;
	}
	return (0);
}

int	get_index_of(t_stack *stack, int x)
{
	int	i;

	i = 0;
	while (i < stack->nb_elements)
	{
		if (stack->stack[i] == x)
			return (i);
		i++;
	}
	return (-1);
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}
