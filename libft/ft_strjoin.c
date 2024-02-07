/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 16:05:31 by tajavon           #+#    #+#             */
/*   Updated: 2023/11/24 18:50:52 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, char *src)
{
	size_t	end_dest;
	size_t	i;

	i = 0;
	end_dest = ft_strlen(dest);
	while (src[i])
	{
		dest[end_dest + i] = src[i];
		i++;
	}
	dest[end_dest + i] = '\0';
	return (dest);
}

size_t	total_len_of(int size, char **strs, size_t sepstr)
{
	int		i;
	size_t	total_len;

	i = 0;
	total_len = 0;
	while (i < size)
	{
		total_len += ft_strlen(strs[i]);
		if (i + 1 < size)
			total_len += sepstr;
		i++;
	}
	return (total_len);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*str;
	int		i;

	i = 0;
	if (size == 0)
	{
		str = malloc(1 * sizeof(char));
		if (!str)
			return (NULL);
		str[0] = '\0';
		return (str);
	}
	str = malloc((total_len_of(size, strs, ft_strlen(sep)) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[0] = '\0';
	while (i < size)
	{
		ft_strcat(str, strs[i]);
		if (i + 1 < size)
			ft_strcat(str, sep);
		i++;
	}
	return (str);
}

// int	main(int argc, char **argv)
// {
// 	printf("./ex03/output___said___this___is___a___success :\n");
// 	printf("%s\n",  ft_strjoin(argc - 1, &argv[1], "___"));
// }
