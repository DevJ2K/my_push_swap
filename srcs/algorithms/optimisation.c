/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimisation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 11:26:15 by tajavon           #+#    #+#             */
/*   Updated: 2023/11/29 17:11:00 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "push_swap.h"

static void	optimizate_rotate(t_stack *stack, int index_to_insert)
{
	int	nb_elts;

	nb_elts = stack->nb_elements;
	if (index_to_insert > nb_elts / 2)
	{
		while (index_to_insert++ < nb_elts)
			ft_rotate(stack);
	}
	else
	{
		while (index_to_insert-- > 0)
			ft_reverse_rotate(stack);
	}
}

void	double_optimizate(int i1, int i2, t_stack *stack_1, t_stack *stack_2)
{
	if (i1 > stack_1->nb_elements / 2 && i2 > stack_2->nb_elements / 2)
	{
		while (i1 < stack_1->nb_elements && i2 < stack_2->nb_elements)
		{
			i1++;
			i2++;
			ft_double_rotate(stack_1, stack_2);
		}
	}
	else if (i1 <= stack_1->nb_elements / 2 && i2 <= stack_2->nb_elements / 2)
	{
		while (i1 > 0 && i2 > 0)
		{
			i1--;
			i2--;
			ft_double_reverse_rotate(stack_1, stack_2);
		}
	}
	optimizate_rotate(stack_1, i1);
	optimizate_rotate(stack_2, i2);
}
