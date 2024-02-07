/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_is_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 10:55:46 by tajavon           #+#    #+#             */
/*   Updated: 2023/11/29 17:10:09 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "push_swap.h"

static int	is_sort(t_stack stack, int i)
{
	int	iteration;

	iteration = 0;
	while (iteration < stack.nb_elements - 1)
	{
		if (i == 0)
		{
			if (stack.stack[stack.nb_elements - 1] > stack.stack[i])
				iteration++;
			else
				return (0);
		}
		else
		{
			if (stack.stack[i - 1] > stack.stack[i])
				iteration++;
			else
				return (0);
		}
		if (i == 0)
			i = stack.nb_elements - 1;
		else
			i--;
	}
	return (1);
}

int	is_sort_somewhere(t_stack *stack)
{
	t_nb_info	nb_info;

	find_min(&nb_info, stack);
	if (is_sort(*stack, nb_info.index))
	{
		if (nb_info.index >= stack->nb_elements / 2)
		{
			while (nb_info.index != stack->nb_elements - 1)
			{
				ft_rotate(stack);
				nb_info.index++;
			}
		}
		else
		{
			while (nb_info.index >= 0)
			{
				ft_reverse_rotate(stack);
				nb_info.index--;
			}
		}
		return (1);
	}
	return (0);
}
