/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 09:09:22 by tajavon           #+#    #+#             */
/*   Updated: 2023/11/29 17:57:59 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "push_swap.h"

int	main(int argc, char **argv)
{
	char	**tab;

	tab = argv;
	if (argc < 2)
		return (0);
	tab = get_list_params(argc, argv);
	if (!tab)
		ft_error("Failed to allocate memory.");
	if (check_argv(argc - 1, tab))
		init_and_sort_stack(argc - 1, tab, 1);
	else
	{
		free_tab(tab);
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	free_tab(tab);
}
