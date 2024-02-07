/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:54:04 by tajavon           #+#    #+#             */
/*   Updated: 2024/02/07 18:40:26 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen_int(const char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strcpy(char *dest, char *src)
{
	int		index;

	index = 0;
	while (src[index] != '\0')
	{
		dest[index] = src[index];
		index++;
	}
	dest[index] = '\0';
	return (dest);
}

char	*ft_strncat(char *dest, char *src, int nb)
{
	int		end_dest;
	int		i;

	i = 0;
	end_dest = ft_strlen_int(dest);
	while (i < nb && src[i] != '\0')
	{
		dest[end_dest + i] = src[i];
		i++;
	}
	dest[end_dest + i] = '\0';
	return (dest);
}

char	*ft_strdup(const char *s)
{
	int		i;
	char	*str;
	char	*ptr;

	ptr = (char *)s;
	i = 0;
	str = (char *)malloc((ft_strlen_int(ptr) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (ptr[i])
	{
		str[i] = ptr[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

int	found_newlines(char *all_read)
{
	int	i;

	i = 0;
	if (!all_read)
		return (0);
	while (all_read[i])
	{
		if (all_read[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}
