/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 10:30:52 by tajavon           #+#    #+#             */
/*   Updated: 2024/01/18 12:53:05 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "push_swap.h"
#include "libft.h"

static void	fill_stack(int **stack, int stack_size, char **argv)
{
	int	i;

	i = 0;
	while (i < stack_size)
	{
		(*stack)[i] = ft_atoi(argv[stack_size - i - 1]);
		i++;
	}
}

static void	check_sort(t_stack stack_a, t_stack stack_b)
{
	int	i;

	i = 0;
	if (stack_b.nb_elements != 0)
	{
		ft_printf("KO\n");
		return ;
	}
	else
	{
		while (i < stack_a.nb_elements - 1)
		{
			if (stack_a.stack[i] < stack_a.stack[i + 1])
			{
				ft_printf("KO\n");
				return ;
			}
			i++;
		}
	}
	ft_printf("OK\n");
	return ;
}

void	init_and_sort_stack(int argc, char **argv, int bonus)
{
	t_stack	stack_a;
	t_stack	stack_b;

	stack_a.stack = malloc(sizeof(int) * (argc));
	if (!stack_a.stack)
		ft_error("Failed to allocate memory.");
	stack_a.nb_elements = argc;
	stack_a.name = 'a';
	stack_b.stack = ft_calloc(sizeof(int), argc);
	if (!stack_b.stack)
		ft_error("Failed to allocate memory.");
	stack_b.nb_elements = 0;
	stack_b.name = 'b';
	fill_stack(&stack_a.stack, argc, argv);
	if (SHOW_STACK)
	{
		ft_printf("===========================\n");
		display_process_2("INITIALISATION", '\0', stack_a, stack_b);
	}
	main_algorithm(&stack_a, &stack_b);
	if (bonus)
		check_sort(stack_a, stack_b);
	free(stack_a.stack);
	free(stack_b.stack);
}
