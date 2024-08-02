/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 16:09:58 by tajavon           #+#    #+#             */
/*   Updated: 2024/08/03 00:16:05 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include "ft_printf.h"

static void	ft_do_swap(t_stack *stack)
{
	int	temp;
	int	last_index;

	last_index = (stack->nb_elements) - 1;
	temp = stack->stack[last_index];
	stack->stack[last_index] = stack->stack[last_index - 1];
	stack->stack[last_index - 1] = temp;
}

void	ft_swap(t_stack *stack)
{
	if (stack->nb_elements < 2)
		return ;
	ft_do_swap(stack);
	if (SHOW_STACK)
		display_process_1("s", *stack);
}

void	ft_double_swap(t_stack *stack_1, t_stack *stack_2)
{
	ft_do_swap(stack_1);
	ft_do_swap(stack_2);
	if (SHOW_STACK)
		display_process_2("s", 's', *stack_1, *stack_2);
}
