/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selbakya <selbakya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 19:32:50 by selbakya          #+#    #+#             */
/*   Updated: 2023/05/08 17:23:41 by selbakya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_get_buffers(int fd, char *few_buffers)
{
	char	real_buf[BUFFER_SIZE + 1];
	long	read_flag_index;
	
	while(1)
	{
		read_flag_index = read(fd, real_buf, BUFFER_SIZE);	
		if (read_flag_index == -1)
			return (0);
		real_buf[read_flag_index] = '\0';
		if (!few_buffers)
			few_buffers = ft_strdup(real_buf);
		else
			few_buffers = ft_strjoin(few_buffers, real_buf);
		if (ft_strchr(real_buf, '\n') || read_flag_index == 0)
			break;		
	}
	return (few_buffers);
}

char	*get_next_line(int fd)
{
	static char	*few_buffers;
	long		nl_symbol;
	char		*output_line;
	char		*temp_point;

	if (BUFFER_SIZE < 0 || read(fd, 0, 0) || fd < 0)
		return (NULL);
	few_buffers = ft_get_buffers(fd, few_buffers);
	if (!few_buffers)
		return (NULL);
	nl_symbol = ft_strlen(few_buffers) - ft_strlen(ft_strchr(few_buffers, '\n')) + 1;
	output_line = ft_substr(few_buffers, 0, nl_symbol);
	temp_point = few_buffers;
	few_buffers = ft_substr(few_buffers, nl_symbol, ft_strlen(few_buffers));
	free(few_buffers);
	return(output_line);
}
