/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 18:25:58 by tajavon           #+#    #+#             */
/*   Updated: 2023/11/29 17:44:28 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "push_swap.h"

char	**get_list_params(int argc, char **argv)
{
	char	*str;
	char	**tab;

	str = ft_strjoin(argc - 1, &argv[1], " ");
	if (!str)
		return (NULL);
	tab = ft_split(str, ' ');
	if (!tab)
	{
		free(str);
		return (NULL);
	}
	free(str);
	return (tab);
}
