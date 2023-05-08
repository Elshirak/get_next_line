/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selbakya <selbakya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 23:31:42 by selbakya          #+#    #+#             */
/*   Updated: 2023/05/08 23:55:04 by selbakya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_get_slice(int fd, char *few_buffers)
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
	static char		*buf[OPEN_MAX];
	char			*to_free;
	char			*res_str;
	size_t			len_out;

	if ((fd < 0 || fd > OPEN_MAX) || BUFFER_SIZE == 0)
	{
		if (buf[fd])
			free(buf[fd]);
		return (NULL);
	}
	buf[fd] = ft_get_slice(fd, buf[fd]);
	if (!buf[fd])
		return (NULL);
	len_out = ft_strchr(buf[fd], '\n') - buf[fd];
	res_str = ft_substr(buf[fd], 0, len_out + 1);
	to_free = buf[fd];
	buf[fd] = ft_substr(buf[fd], len_out + 1, (ft_strlen(buf[fd]) - len_out));
	free(to_free);
	return (res_str);
}
