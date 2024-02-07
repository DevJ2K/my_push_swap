/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 15:57:23 by tajavon           #+#    #+#             */
/*   Updated: 2023/11/29 18:04:52 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "push_swap.h"

void	main_algorithm(t_stack *stack_a, t_stack *stack_b)
{
	if (is_sort_somewhere(stack_a) && stack_b->nb_elements == 0)
		return ;
	if (stack_a->nb_elements <= 3)
		algorithm_up_to_3(stack_a);
	else if (stack_a->nb_elements <= 5)
		algorithm_up_to_5(stack_a, stack_b);
	else
		algorithm_up_to_n(stack_a, stack_b);
}
