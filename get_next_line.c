/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selbakya <selbakya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 19:32:50 by selbakya          #+#    #+#             */
/*   Updated: 2023/05/07 23:25:15 by selbakya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char static	ft_read_line(int fd, char *collector_buff)
{
	int		read_flag_or_index;
	char	tmp_buf[BUFFER_SIZE + 1];

	read_flag_or_index = 1;
	while (!ft_strchr(collector_buff, '\n') && read_flag_or_index > 0)
	{
		read_flag_or_index = read(fd, tmp_buf, BUFFER_SIZE);
		if (read_flag_or_index == -1)
		{
			free (collector_buff);
			return (NULL);
		}
		tmp_buf[read_flag_or_index] = '\0';
		collector_buff = ft_strjoin(collector_buff, tmp_buf);
		free (tmp_buf);
	}
	return (collector_buff);
}

char	*ft_make_output_remove_extra(char *collector_buff)
{
	char	*output_line;
	int		index_newline_symbol;
	int		use_part;

	index_newline_symbol = ft_strchr(collector_buff, '\n');
	use_part = ft_strlen(collector_buff) - ft_strlen(index_newline_symbol) + 1;
	if (index_newline_symbol)
		output_line = ft_substr(collector_buff, 0, use_part);
	else
		output_line = ft_strdup(collector_buff);
	return (output_line);
}

char	*ft_dzi_buffer(char *collector_buf)
{
	char	*tmp_pointer;
	int		length;

	if (ft_strchr(collector_buf, '\n'))
	{
		tmp_pointer = collector_buf;
		length = ft_strlen(ft_strchr(collector_buf, '\n') + 1);
		collector_buf = ft_substr(collector_buf, ft_strlen(collector_buf) - length, length);
		free (tmp_pointer);
		tmp_pointer = NULL;
	}
	else
	{
		free(collector_buf);
		return (NULL);
	}
	return (collector_buf);
}

char	*get_next_line(int fd)
{
	char		*output_string;
	char static	*collector_buff = NULL;

	if (BUFFER_SIZE <= 0 || fd < 0 || read(fd, 0, 0) < 0)
		return (NULL);
	collector_buff = read_line(fd, collector_buff);
	if (collector_buff[0] == '\0')
	{
		free(collector_buff);
		collector_buff = NULL;
		return (NULL);
	}
	output_string = ft_make_output_remove_extra(collector_buff);
	collector_buff = ft_dzi_buffer(collector_buff);
	return (output_string);
}
