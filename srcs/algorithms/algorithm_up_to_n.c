/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_up_to_n.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 15:00:39 by tajavon           #+#    #+#             */
/*   Updated: 2023/11/29 17:47:43 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "push_swap.h"

void	algorithm_up_to_n(t_stack *stack_1, t_stack *stack_2)
{
	while (stack_1->nb_elements > 3 && !is_sort_somewhere(stack_1))
		ft_insert(stack_1, stack_2);
	if (stack_1->nb_elements <= 3)
		algorithm_up_to_3(stack_1);
	while (stack_2->nb_elements > 0)
		ft_insert_2(stack_1, stack_2);
	is_sort_somewhere(stack_1);
}
