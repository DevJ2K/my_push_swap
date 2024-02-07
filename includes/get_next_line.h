/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajavon <tajavon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:39:06 by tajavon           #+#    #+#             */
/*   Updated: 2024/02/07 18:38:57 by tajavon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 14
# endif

char	*get_next_line(int fd);
int		ft_strlen_int(const char *str);
void	new_all_read(char **all_read, char *buffer, int nb_bytes_read);
char	*ft_strcpy(char *dest, char *src);
char	*ft_strncat(char *dest, char *src, int nb);
int		found_newlines(char *all_read);
char	*extract_line(char *all_read);
void	clean_read_line(char **all_read);
char	*ft_strdup(const char *s);
void	read_and_add(int fd, char **all_read);

#endif
