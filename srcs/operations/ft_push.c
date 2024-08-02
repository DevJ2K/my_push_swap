/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 17:11:34 by tajavon           #+#    #+#             */
/*   Updated: 2024/08/03 00:18:54 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "push_swap.h"
#include "libft.h"

void	ft_push(t_stack *stack_src, t_stack *stack_dest)
{
	int	last_index_src;
	int	last_index_dest;

	if (stack_src->nb_elements == 0)
		return ;
	last_index_src = stack_src->nb_elements - 1;
	last_index_dest = stack_dest->nb_elements;
	stack_dest->stack[last_index_dest] = stack_src->stack[last_index_src];
	stack_src->stack[last_index_src] = 0;
	stack_dest->nb_elements++;
	stack_src->nb_elements--;
	if (SHOW_STACK)
	{
		if (stack_src->name == 'a')
			display_process_2("p", stack_dest->name, *stack_src, *stack_dest);
		else
			display_process_2("p", stack_dest->name, *stack_dest, *stack_src);
	}
	else
	{
		ft_printf("p%c\n", stack_dest->name);
	}
}
