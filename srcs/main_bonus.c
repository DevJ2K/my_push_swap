/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 09:09:22 by tajavon           #+#    #+#             */
/*   Updated: 2024/02/27 12:26:29 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "push_swap.h"

static int	length_params(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
		i++;
	return (i);
}

int	main(int argc, char **argv)
{
	char	**tab;

	tab = argv;
	if (argc < 2)
		return (0);
	tab = get_list_params(argc, argv);
	if (!tab)
		return (0);
	argc = length_params(tab);
	if (!tab)
		ft_error("Failed to allocate memory.");
	if (check_argv(argc, tab) && argc >= 1)
		handle_bonus(argc, tab);
	else
	{
		free_tab(tab);
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	free_tab(tab);
}

