/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selbakya <selbakya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 15:36:31 by selbakya          #+#    #+#             */
/*   Updated: 2023/05/07 22:43:06 by selbakya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len_result_string;
	char	*ptr_result;
	char	*result;

	if (!s1)
		return (ft_strdup(s2));
	len_result_string = ft_strlen(s1) + ft_strlen(s2) + 1;
	ptr_result = (char *) malloc(len_result_string * sizeof(char));
	if (!ptr_result)
		return (NULL);
	result = ptr_result;
	while (*s1 != '\0')
		*ptr_result++ = *s1++;
	if (!s1)
		return (result);
	while (*s2 != '\0')
		*ptr_result++ = *s2++;
	*ptr_result = '\0';
	return (result);
}

int	ft_strlen(const char *s)
{
	int	counter;

	counter = 0;
	while (s[counter])
		++counter;
	return (counter);
}

char	*ft_substr(char const *s, unsigned int start, int len)
{
	int		string_size;
	char	*ptr_to_result_string;
	int		iterator;

	if (s == 0)
		return (NULL);
	string_size = ft_strlen(&s[start]);
	if (string_size >= len)
		string_size = len;
	if ((int)start > ft_strlen(s))
		return (ft_strdup(""));
	ptr_to_result_string = (char *) malloc((string_size + 1) * sizeof (char));
	if (!ptr_to_result_string)
		return (NULL);
	iterator = 0;
	while (iterator != string_size)
	{
		ptr_to_result_string[iterator] = s[iterator + start];
		++iterator;
	}
	ptr_to_result_string[iterator] = '\0';
	return (ptr_to_result_string);
}
