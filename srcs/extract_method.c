/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_method.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 15:55:04 by tajavon           #+#    #+#             */
/*   Updated: 2023/11/29 17:49:36 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "push_swap.h"

void	extract_min(t_stack *stack_1, t_stack *stack_2)
{
	t_nb_info	nb_info;

	find_min(&nb_info, stack_1);
	if (nb_info.index >= stack_1->nb_elements / 2)
	{
		while (nb_info.index != stack_1->nb_elements - 1)
		{
			ft_rotate(stack_1);
			nb_info.index++;
		}
	}
	else
	{
		while (nb_info.index != 0)
		{
			ft_reverse_rotate(stack_1);
			nb_info.index--;
		}
		ft_reverse_rotate(stack_1);
		nb_info.index = stack_1->nb_elements - 1;
	}
	ft_push(stack_1, stack_2);
}

// void	extract_max(t_stack *stack_1, t_stack *stack_2)
// {
// 	t_nb_info	nb_info;

// 	find_max(&nb_info, stack_1);
// 	if (nb_info.index >= stack_1->nb_elements / 2)
// 	{
// 		while (nb_info.index != stack_1->nb_elements - 1)
// 		{
// 			ft_rotate(stack_1);
// 			nb_info.index++;
// 		}
// 	}
// 	else
// 	{
// 		while (nb_info.index != 0)
// 		{
// 			ft_reverse_rotate(stack_1);
// 			nb_info.index--;
// 		}
// 		ft_reverse_rotate(stack_1);
// 		nb_info.index = stack_1->nb_elements - 1;
// 	}
// 	ft_push(stack_1, stack_2);
// }

// int	count_extract_min(t_stack *stack_1)
// {
// 	t_nb_info	nb_info;
// 	int			count;

// 	count = 0;
// 	find_min(&nb_info, stack_1);
// 	if (nb_info.index >= stack_1->nb_elements / 2)
// 	{
// 		while (nb_info.index != stack_1->nb_elements - 1)
// 		{
// 			count++;
// 			nb_info.index++;
// 		}
// 	}
// 	else
// 	{
// 		while (nb_info.index != 0)
// 		{
// 			count++;
// 			nb_info.index--;
// 		}
// 		count++;
// 		nb_info.index = stack_1->nb_elements - 1;
// 	}
// 	count++;
// 	return (count);
// }

// int	count_extract_max(t_stack *stack_1)
// {
// 	t_nb_info	nb_info;
// 	int			count;

// 	count = 0;
// 	find_max(&nb_info, stack_1);
// 	if (nb_info.index >= stack_1->nb_elements / 2)
// 	{
// 		while (nb_info.index != stack_1->nb_elements - 1)
// 		{
// 			count++;
// 			nb_info.index++;
// 		}
// 	}
// 	else
// 	{
// 		while (nb_info.index != 0)
// 		{
// 			count++;
// 			nb_info.index--;
// 		}
// 		count++;
// 		nb_info.index = stack_1->nb_elements - 1;
// 	}
// 	count++;
// 	return (count);
// }
