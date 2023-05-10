/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selbakya <selbakya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 19:32:50 by selbakya          #+#    #+#             */
/*   Updated: 2023/05/08 22:53:21 by selbakya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_get_slice(int fd, char *few_buffers)
{
	char	real_buf[BUFFER_SIZE + 1];
	char	*tmp_line;
	long	read_flag_size;

	read_flag_size = 1;
	while (1)
	{
		read_flag_size = read(fd, real_buf, BUFFER_SIZE);
		if (read_flag_size < 0)
		{
			if (few_buffers)
				free(few_buffers);
			return (NULL);
		}
		real_buf[read_flag_size] = '\0';
		if (!few_buffers)
			tmp_line = ft_strdup(real_buf);
		else
			tmp_line = ft_strjoin(few_buffers, real_buf);
		few_buffers = tmp_line;
		if (ft_strchr(few_buffers, '\n') || read_flag_size == 0)
			break ;
	}
	return (few_buffers);
}

char	*get_next_line(int fd)
{
	static char		*few_buf;
	char			*to_free;
	char			*res_str;
	size_t			len_out;

	if ((fd < 0 || fd > OPEN_MAX) || BUFFER_SIZE == 0)
	{
		if (few_buf)
			free(few_buf);
		return (NULL);
	}
	few_buf = ft_get_slice(fd, few_buf);
	if (!few_buf)
		return (NULL);
	len_out = ft_strchr(few_buf, '\n') - few_buf;
	res_str = ft_substr(few_buf, 0, len_out + 1);
	to_free = few_buf;
	few_buf = ft_substr(few_buf, len_out + 1, (ft_strlen(few_buf) - len_out));
	free(to_free);
	return (res_str);
}
