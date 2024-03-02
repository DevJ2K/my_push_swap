/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 17:33:41 by tajavon           #+#    #+#             */
/*   Updated: 2024/03/02 18:31:16 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "push_swap.h"

static void	ft_do_rotate(t_stack *stack)
{
	int	i;
	int	*temp_stack;

	temp_stack = malloc((stack->nb_elements) * sizeof(int));
	if (!temp_stack)
		ft_error("Failed to allocate memory.");
	i = 0;
	while (i < stack->nb_elements - 1)
	{
		temp_stack[i + 1] = stack->stack[i];
		i++;
	}
	temp_stack[0] = stack->stack[stack->nb_elements - 1];
	i = 0;
	while (i < stack->nb_elements)
	{
		stack->stack[i] = temp_stack[i];
		i++;
	}
	free(temp_stack);
}

// inverser la pile
void	ft_rotate(t_stack *stack)
{
	if (stack->nb_elements < 2)
		return ;
	ft_do_rotate(stack);
	if (SHOW_STACK)
		display_process_1("r", *stack);
	else
	{
		if (BONUS != 1)
			ft_printf("r%c\n", stack->name);
	}
}

void	ft_double_rotate(t_stack *stack_1, t_stack *stack_2)
{
	ft_do_rotate(stack_1);
	ft_do_rotate(stack_2);
	if (SHOW_STACK)
		display_process_2("r", 'r', *stack_1, *stack_2);
	else
	{
		if (BONUS != 1)
			ft_printf("rr\n");
	}
}
