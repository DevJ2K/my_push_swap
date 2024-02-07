/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 12:19:13 by tajavon           #+#    #+#             */
/*   Updated: 2024/01/18 12:59:19 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"
#include "libft.h"

static int	only_number(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (48 <= argv[i][j] && argv[i][j] <= 57)
				j++;
			else if ((argv[i][j] == '-' || argv[i][j] == '+') && j == 0)
				j++;
			else if (argv[i][j] == '\\')
			{
				if (!find_occurence(argv[i][j + 1], "tnvfr"))
					return (0);
				j += 2;
			}
			else
				return (0);
		}
		i++;
	}
	return (1);
}

static int	ft_check_atoi(const char *str)
{
	long int	nb;
	int			i;
	long int	is_neg;

	nb = 0;
	i = 0;
	is_neg = 1;
	while ((9 <= str[i] && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			is_neg *= -1;
		i++;
	}
	while ('0' <= str[i] && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - 48);
		if (nb * is_neg > 2147483647 || nb * is_neg < -2147483648)
			return (0);
		i++;
	}
	if (nb * is_neg > 2147483647 || nb * is_neg < -2147483648)
		return (0);
	return (1);
}

static int	is_not_overflow(int argc, char **argv)
{
	int	i;

	i = 0;
	while (i < argc)
	{
		if (!ft_check_atoi(argv[i]))
			return (0);
		i++;
	}
	return (1);
}

// Doublons
static int	check_double_nb(int argc, char **argv)
{
	int	current_nb;
	int	i;
	int	j;

	i = 0;
	while (i < argc)
	{
		j = 0;
		current_nb = ft_atoi(argv[i]);
		while (j < argc)
		{
			if (current_nb == ft_atoi(argv[j]) && i != j)
				return (0);
			else
				j++;
		}
		i++;
	}
	return (1);
}

int	check_argv(int argc, char **argv)
{
	if (!only_number(argc, argv))
		return (0);
	if (!is_not_overflow(argc, argv))
		return (0);
	if (!check_double_nb(argc, argv))
		return (0);
	return (1);
}
