/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_max.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 15:31:05 by tajavon           #+#    #+#             */
/*   Updated: 2023/11/29 17:10:18 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "push_swap.h"

int	return_min(t_stack *stack)
{
	int	i;
	int	min;

	i = 0;
	min = stack->stack[0];
	while (i < stack->nb_elements)
	{
		if (stack->stack[i] < min)
			min = stack->stack[i];
		i++;
	}
	return (min);
}

int	return_max(t_stack *stack)
{
	int	i;
	int	max;

	i = 0;
	max = stack->stack[0];
	while (i < stack->nb_elements)
	{
		if (stack->stack[i] > max)
			max = stack->stack[i];
		i++;
	}
	return (max);
}

void	find_min(t_nb_info *nb_info, t_stack *stack_1)
{
	int	i;

	i = 1;
	set_nb_info(nb_info, stack_1->stack[0], 0);
	while (i < stack_1->nb_elements)
	{
		if (stack_1->stack[i] < nb_info->nb)
			set_nb_info(nb_info, stack_1->stack[i], i);
		i++;
	}
}

void	find_max(t_nb_info *nb_info, t_stack *stack_1)
{
	int	i;

	i = 1;
	set_nb_info(nb_info, stack_1->stack[0], 0);
	while (i < stack_1->nb_elements)
	{
		if (stack_1->stack[i] > nb_info->nb)
			set_nb_info(nb_info, stack_1->stack[i], i);
		i++;
	}
}
