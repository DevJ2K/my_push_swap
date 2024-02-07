/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculated_move.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 17:13:23 by tajavon           #+#    #+#             */
/*   Updated: 2023/11/29 17:36:13 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	both_upper_middle(int i1, int i2, int nb_elts_1, int nb_elts_2)
{
	int	costs;

	costs = 0;
	while (i1 < nb_elts_1 - 1 && i2 < nb_elts_2 - 1)
	{
		i1++;
		i2++;
		costs++;
	}
	while (i1 < nb_elts_1 - 1)
	{
		i1++;
		i2++;
		costs++;
	}
	while (i2 < nb_elts_2 - 1)
	{
		i1++;
		i2++;
		costs++;
	}
	return (costs);
}

static int	both_under_middle(int i1, int i2)
{
	int	costs;

	costs = 0;
	while (i1 >= 0 && i2 >= 0)
	{
		i1--;
		i2--;
		costs++;
	}
	while (i1 >= 0)
	{
		i1--;
		i2--;
		costs++;
	}
	while (i2-- >= 0)
	{
		i1--;
		i2--;
		costs++;
	}
	return (costs);
}

static int	different_place(int i1, int i2, int nb_elts_1, int nb_elts_2)
{
	int	costs;

	costs = 0;
	if (i1 > nb_elts_1 / 2)
	{
		while (i1++ < nb_elts_1 - 1)
			costs++;
	}
	else
	{
		while (i1-- >= 0)
			costs++;
	}
	if (i2 > nb_elts_2 / 2)
	{
		while (i2++ < nb_elts_2 - 1)
			costs++;
	}
	else
	{
		while (i2-- >= 0)
			costs++;
	}
	return (costs);
}

int	calculated_move(int i1, int i2, t_stack *stack_1, t_stack *stack_2)
{
	int	costs;
	int	nb_elts_1;
	int	nb_elts_2;

	nb_elts_1 = stack_1->nb_elements;
	nb_elts_2 = stack_2->nb_elements;
	costs = 0;
	if (i1 > nb_elts_1 / 2 && i2 > nb_elts_2 / 2)
		costs += both_upper_middle(i1, i2, nb_elts_1, nb_elts_2);
	else if (i1 < nb_elts_1 / 2 && i2 < nb_elts_2 / 2)
		costs += both_under_middle(i1, i2);
	else
		costs += different_place(i1, i2, nb_elts_1, nb_elts_2);
	costs++;
	return (costs);
}
