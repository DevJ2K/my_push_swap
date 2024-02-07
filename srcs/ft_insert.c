/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insert.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 14:49:33 by tajavon           #+#    #+#             */
/*   Updated: 2024/01/30 09:59:02 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "push_swap.h"

static int	get_index_to_insert(t_stack *stack, int nb)
{
	int	i;
	int	iteration;

	i = get_index_of(stack, return_min(stack));
	iteration = 0;
	if (nb > return_max(stack))
		return (get_index_of(stack, return_max(stack)) + 1);
	while (iteration < stack->nb_elements)
	{
		if (i == stack->nb_elements - 1)
		{
			if (stack->stack[i] < nb && nb < stack->stack[0])
				return (i);
			i = 0;
		}
		else
		{
			if (stack->stack[i] < nb && nb < stack->stack[i + 1])
				return (i);
			i++;
		}
		iteration++;
	}
	return (-1);
}

int	pos_cheapest_move(t_stack *stack_1, t_stack *stack_2)
{
	int	i;
	int	tmp_cost;
	int	cheapest_cost;
	int	best_index;
	int	get_index;

	i = 0;
	best_index = stack_1->nb_elements - 1;
	cheapest_cost = stack_1->nb_elements + stack_2->nb_elements + 1;
	while (i < stack_1->nb_elements)
	{
		get_index = get_index_to_insert(stack_2, stack_1->stack[i]);
		tmp_cost = calculated_move(i, get_index, stack_1, stack_2);
		if (tmp_cost <= cheapest_cost)
		{
			best_index = i;
			cheapest_cost = tmp_cost;
		}
		i++;
	}
	return (best_index);
}

void	ft_insert(t_stack *stack_1, t_stack *stack_2)
{
	int	cheapest;
	int	pos_cheapest;
	int	index;

	pos_cheapest = pos_cheapest_move(stack_1, stack_2);
	cheapest = stack_1->stack[pos_cheapest];
	if (stack_2->nb_elements < 2)
	{
		ft_push(stack_1, stack_2);
		return ;
	}
	if (return_min(stack_2) > cheapest)
		index = get_index_of(stack_2, return_min(stack_2)) - 1;
	else if (return_max(stack_2) < cheapest)
		index = get_index_of(stack_2, return_max(stack_2));
	else
		index = get_index_to_insert(stack_2, cheapest);
	double_optimizate(pos_cheapest + 1, index + 1, stack_1, stack_2);
	ft_push(stack_1, stack_2);
}

static int	get_index_to_insert_2(t_stack *stack, int nb)
{
	int	i;
	int	iteration;

	i = get_index_of(stack, return_min(stack));
	iteration = 0;
	while (iteration < stack->nb_elements)
	{
		if (i == stack->nb_elements - 1)
		{
			if (stack->stack[i] > nb && nb > stack->stack[0])
				return (i);
			else
				i = 0;
		}
		else
		{
			if (stack->stack[i] > nb && nb > stack->stack[i + 1])
				return (i);
			else
				i++;
		}
		iteration++;
	}
	return (-1);
}

void	ft_insert_2(t_stack *stack_a, t_stack *stack_b)
{
	int	top;
	int	pos_to_insert;

	top = stack_b->stack[stack_b->nb_elements - 1];
	if (return_max(stack_a) < top)
		pos_to_insert = get_index_of(stack_a, return_max(stack_a)) - 1;
	else if (return_min(stack_a) > top)
		pos_to_insert = get_index_of(stack_a, return_min(stack_a));
	else
		pos_to_insert = get_index_to_insert_2(stack_a, top);
	if (pos_to_insert >= stack_a->nb_elements / 2)
	{
		while (pos_to_insert++ < stack_a->nb_elements - 1)
			ft_rotate(stack_a);
	}
	else
	{
		while (pos_to_insert-- >= 0)
			ft_reverse_rotate(stack_a);
	}
	ft_push(stack_b, stack_a);
}
