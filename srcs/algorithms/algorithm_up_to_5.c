/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_up_to_5.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 23:40:55 by tajavon           #+#    #+#             */
/*   Updated: 2023/11/26 16:00:03 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "push_swap.h"

void	algorithm_up_to_5(t_stack *stack_1, t_stack *stack_2)
{
	extract_min(stack_1, stack_2);
	if (is_sort_somewhere(stack_1))
	{
		ft_push(stack_2, stack_1);
		return ;
	}
	extract_min(stack_1, stack_2);
	algorithm_up_to_3(stack_1);
	ft_push(stack_2, stack_1);
	ft_push(stack_2, stack_1);
}
