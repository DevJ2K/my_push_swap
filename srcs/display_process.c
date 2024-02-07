/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_process.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 10:25:25 by tajavon           #+#    #+#             */
/*   Updated: 2023/11/29 18:19:45 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include "push_swap.h"

static void	show_stack(t_stack stack, int nb_s)
{
	int	i;
	int	nb_elts;

	i = 0;
	nb_elts = stack.nb_elements;
	if (nb_s == 1)
		ft_printf("PILE %c [\033[38;5;32m%d\033[0m] -> [", stack.name, nb_elts);
	else if (nb_s == 2)
		ft_printf("PILE %c [\033[38;5;208m%d\033[0m] -> [", stack.name, nb_elts);
	while (i + 1 < nb_elts)
	{
		ft_printf("%d-", stack.stack[i]);
		i++;
	}
	if (nb_elts == 0)
		ft_printf("_[\n", stack.stack[i]);
	else
		ft_printf("%d[\n", stack.stack[i]);
}

void	display_process_1(char *op, t_stack stack)
{
	ft_printf("Après l'utilisation de : \033[32m%s%c\033[0m\n", op, stack.name);
	if (stack.name == 'b')
		show_stack(stack, 2);
	else
		show_stack(stack, 1);
	ft_printf("===========================\n");
}

void	display_process_2(char *op, char c, t_stack stack_1, t_stack stack_2)
{
	ft_printf("Après l'utilisation de : \033[32m%s%c\033[0m\n", op, c);
	show_stack(stack_1, 1);
	show_stack(stack_2, 2);
	ft_printf("===========================\n");
}
