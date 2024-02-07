/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_up_to_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 22:18:47 by tajavon           #+#    #+#             */
/*   Updated: 2023/11/29 17:00:51 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "push_swap.h"

void	algorithm_up_to_3(t_stack *stack)
{
	t_nb_info	nb_info;
	int			i;

	i = 1;
	set_nb_info(&nb_info, stack->stack[0], 0);
	while (i < stack->nb_elements)
	{
		if (nb_info.nb < stack->stack[i])
			set_nb_info(&nb_info, stack->stack[i], i);
		i++;
	}
	if (stack->nb_elements > 2)
	{
		if (nb_info.index == 2)
			ft_rotate(stack);
		else if (nb_info.index == 1)
			ft_reverse_rotate(stack);
	}
	if (stack->nb_elements > 1)
	{
		i = stack->nb_elements;
		if (stack->stack[i - 1] > stack->stack[i - 2])
			ft_swap(stack);
	}
}

void	reverse_algorithm_up_to_3(t_stack *stack)
{
	t_nb_info	nb_info;
	int			i;

	i = 1;
	set_nb_info(&nb_info, stack->stack[0], 0);
	while (i < stack->nb_elements)
	{
		if (nb_info.nb > stack->stack[i])
			set_nb_info(&nb_info, stack->stack[i], i);
		i++;
	}
	if (stack->nb_elements > 2)
	{
		if (nb_info.index == 1)
			ft_reverse_rotate(stack);
		else if (nb_info.index == 2)
			ft_rotate(stack);
	}
	if (stack->nb_elements > 1)
	{
		i = stack->nb_elements;
		if (stack->stack[i - 1] < stack->stack[i - 2])
			ft_swap(stack);
	}
}
