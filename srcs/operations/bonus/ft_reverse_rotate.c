/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 18:06:11 by tajavon           #+#    #+#             */
/*   Updated: 2024/08/03 00:15:40 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "push_swap.h"

static void	ft_do_reverse_rotate(t_stack *stack)
{
	int	i;
	int	*temp_stack;

	temp_stack = malloc((stack->nb_elements) * sizeof(int));
	if (!temp_stack)
		ft_error("Failed to allocate memory.");
	i = 0;
	while (i < stack->nb_elements - 1)
	{
		temp_stack[i] = stack->stack[i + 1];
		i++;
	}
	temp_stack[i] = stack->stack[0];
	i = 0;
	while (i < stack->nb_elements)
	{
		stack->stack[i] = temp_stack[i];
		i++;
	}
	free(temp_stack);
}

void	ft_reverse_rotate(t_stack *stack)
{
	if (stack->nb_elements < 2)
		return ;
	ft_do_reverse_rotate(stack);
	if (SHOW_STACK)
		display_process_1("rr", *stack);
}

void	ft_double_reverse_rotate(t_stack *stack_1, t_stack *stack_2)
{
	ft_do_reverse_rotate(stack_1);
	ft_do_reverse_rotate(stack_2);
	if (SHOW_STACK)
		display_process_2("rr", 'r', *stack_1, *stack_2);
}
