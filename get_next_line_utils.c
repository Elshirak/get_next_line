/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selbakya <selbakya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 15:36:31 by selbakya          #+#    #+#             */
/*   Updated: 2023/05/08 22:28:55 by selbakya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	length;

	length = 0;
	while (str[length])
		++length;
	return (length);
}

char	*ft_strdup(const char *source_string)
{
	int		length_str;
	int		i;
	char	*result;

	length_str = ft_strlen(source_string) + 1;
	result = (char *) malloc(sizeof(char) * length_str);
	if (!result)
		return (NULL);
	i = 0;
	while (i < length_str)
	{
		result[i] = source_string[i];
		++i;
	}
	return (result);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*str;
	size_t		range;
	size_t		i;

	if (!s || !(*s))
		return (NULL);
	i = ft_strlen(s);
	range = 0;
	if (start < i)
		range = i - start;
	if (range > len)
		range = len;
	str = (char *)malloc((range + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (i < range)
	{
		*(str + i) = *(s + start + i);
		i++;
	}
	*(str + i) = '\0';
	return (str);
}

char	*ft_strchr(const char *pointer_str, int symbol)
{
	unsigned char	c;

	c = (unsigned char)symbol;
	if (symbol == 0)
		return ((char *)(pointer_str + ft_strlen(pointer_str)));
	while (*pointer_str != 0)
	{
		if (*pointer_str == c)
			return ((char *)pointer_str);
		++pointer_str;
	}
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	len1;
	size_t	len2;
	long	i;
	char	*join;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	join = (char *)malloc((len1 + len2 + 1) * sizeof(char));
	if (!join)
		return (NULL);
	i = -1;
	while ((size_t)(++i) < len1)
		*(join + i) = *(s1 + i);
	--i;
	while ((size_t)(++i) < len1 + len2)
		*(join + i) = *(s2 + i - len1);
	*(join + len1 + len2) = '\0';
	if (s1)
		free(s1);
	return (join);
}

/*
ft_strjoin gets seg and memory leaks !!! this is working one:

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	len1;
	size_t	len2;
	long	i;
	char	*join;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	join = (char *)malloc((len1 + len2 + 1) * sizeof(char));
	if (!join)
		return (NULL);
	i = -1;
	while ((size_t)(++i) < len1)
		*(join + i) = *(s1 + i);
	--i;
	while ((size_t)(++i) < len1 + len2)
		*(join + i) = *(s2 + i - len1);
	*(join + len1 + len2) = '\0';
	if (s1)
		free(s1);
	return (join);
}

*/
