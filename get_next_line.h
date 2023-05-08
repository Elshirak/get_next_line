/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selbakya <selbakya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 18:02:50 by selbakya          #+#    #+#             */
/*   Updated: 2023/05/08 22:30:34 by selbakya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <limits.h>
# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *source_string);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strchr(const char *pointer_str, int symbol);
char	*ft_strjoin(char *s1, char *s2);
char	*get_next_line(int fd);

#endif