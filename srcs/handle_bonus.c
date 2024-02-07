/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 09:15:29 by tajavon           #+#    #+#             */
/*   Updated: 2024/02/07 19:03:32 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "push_swap.h"
#include "get_next_line.h"

static int	execute_action(
	t_stack *stack_a, t_stack *stack_b, size_t entry_size, char *entry)
{
	if (ft_strncmp("sa", entry, entry_size) == 0)
		return(ft_swap(stack_a), 0);
	else if (ft_strncmp("sb", entry, entry_size) == 0)
		return(ft_swap(stack_b), 0);
	else if (ft_strncmp("ss", entry, entry_size) == 0)
		return(ft_double_swap(stack_a, stack_b), 0);
	else if (ft_strncmp("pa", entry, entry_size) == 0)
		return(ft_push(stack_b, stack_a), 0);
	else if (ft_strncmp("pb", entry, entry_size) == 0)
		return(ft_push(stack_a, stack_b), 0);
	else if (ft_strncmp("ra", entry, entry_size) == 0)
		return(ft_rotate(stack_a), 0);
	else if (ft_strncmp("rb", entry, entry_size) == 0)
		return(ft_rotate(stack_b), 0);
	else if (ft_strncmp("rr", entry, entry_size) == 0)
		return(ft_double_rotate(stack_a, stack_b), 0);
	else if (ft_strncmp("rra", entry, entry_size) == 0)
		return(ft_reverse_rotate(stack_a), 0);
	else if (ft_strncmp("rrb", entry, entry_size) == 0)
		return(ft_reverse_rotate(stack_b), 0);
	else if (ft_strncmp("rrr", entry, entry_size) == 0)
		return(ft_double_reverse_rotate(stack_a, stack_b), 0);
	return (-1);
}

static int	action_loop(t_stack *stack_a, t_stack *stack_b)
{
	char	*entry;
	size_t	e_size;

	while (1)
	{
		entry = get_next_line(0);
		if (!entry)
			return (0);
		e_size = ft_strlen(entry) - 1;
		if (execute_action(stack_a, stack_b, e_size, entry) == -1)
			return (free(entry), -1);
		free(entry);
	}
	return (0);
}

void	handle_bonus(int argc, char **argv)
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
	if (action_loop(&stack_a, &stack_b) == -1)
		ft_putstr_fd("Error\n", 2);
	else
		check_sort(stack_a, stack_b);
	free(stack_a.stack);
	free(stack_b.stack);
}
