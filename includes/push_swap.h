/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 11:02:02 by tajavon           #+#    #+#             */
/*   Updated: 2024/02/07 18:30:12 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# ifndef SHOW_STACK
#  define SHOW_STACK 1
# endif

typedef struct s_stack
{
	char		name;
	int			*stack;
	int			nb_elements;
}				t_stack;

typedef struct s_nb_info
{
	int	nb;
	int	index;
}		t_nb_info;

void	ft_error(char *str);
int		check_argv(int argc, char **argv);
void	ft_swap(t_stack *stack);
void	ft_push(t_stack *stack_src, t_stack *stack_dest);
void	ft_rotate(t_stack *stack);
void	ft_reverse_rotate(t_stack *stack);
void	ft_double_swap(t_stack *stack_1, t_stack *stack_2);
void	ft_double_rotate(t_stack *stack_1, t_stack *stack_2);
void	ft_double_reverse_rotate(t_stack *stack_1, t_stack *stack_2);
void	init_and_sort_stack(int argc, char **argv, int bonus);
void	main_algorithm(t_stack *stack_a, t_stack *stack_b);
void	set_nb_info(t_nb_info *nb_info, int nb, int index);
void	algorithm_up_to_3(t_stack *stack);
void	algorithm_up_to_5(t_stack *stack_1, t_stack *stack_2);
void	algorithm_up_to_n(t_stack *stack_1, t_stack *stack_2);
void	reverse_algorithm_up_to_3(t_stack *stack);
void	display_process_1(char *op, t_stack stack);
void	display_process_2(char *op, char c, t_stack stack_1, t_stack stack_2);
int		is_sort_somewhere(t_stack *stack);
void	find_min(t_nb_info *nb_info, t_stack *stack_1);
void	find_max(t_nb_info *nb_info, t_stack *stack_1);
char	**get_list_params(int argc, char **argv);
int		find_occurence(char c, char *str);
void	extract_min(t_stack *stack_1, t_stack *stack_2);
void	double_optimizate(int i1, int i2, t_stack *stack_1, t_stack *stack_2);
void	ft_insert(t_stack *stack_1, t_stack *stack_2);
void	ft_insert_2(t_stack *stack_a, t_stack *stack_b);
int		return_min(t_stack *stack);
int		return_max(t_stack *stack);
int		calculated_move(int i1, int i2, t_stack *stack_1, t_stack *stack_2);
int		get_index_of(t_stack *stack, int x);
void	free_tab(char **tab);
void	fill_stack(int **stack, int stack_size, char **argv);
void	check_sort(t_stack stack_a, t_stack stack_b);
void	handle_bonus(int argc, char **argv);

#endif
