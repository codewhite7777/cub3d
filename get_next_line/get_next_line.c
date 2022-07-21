/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alee <alee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 22:39:09 by alee              #+#    #+#             */
/*   Updated: 2022/03/14 21:20:30 by alee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <limits.h>
#include <unistd.h>
#include <stdlib.h>

int	get_next_line(int fd, char **line)
{
	char		buf[BUFFER_SIZE + 1];
	static char	*s_buf;
	int			rd_size;

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0 || !line)
		return (-1);
	rd_size = read(fd, buf, BUFFER_SIZE);
	while (rd_size > 0)
	{
		buf[rd_size] = '\0';
		if (!s_buf && init_buf(&s_buf) == -1)
			return (-1);
		if (append_buf(&s_buf, buf) == -1)
			return (-1);
		if (ft_strchr(s_buf, '\n'))
			return (trim_buf(&s_buf, line));
		rd_size = read(fd, buf, BUFFER_SIZE);
	}
	if (rd_size < 0)
		return (-1);
	if (!s_buf && init_buf(&s_buf) == -1)
		return (-1);
	return (trim_buf(&s_buf, line));
}

int	append_buf(char **o_buf, char *n_buf)
{
	char	*tmp_buf;

	tmp_buf = ft_strjoin(*o_buf, n_buf);
	if (!tmp_buf)
	{
		free(*o_buf);
		*o_buf = (char *)(0);
		return (-1);
	}
	free(*o_buf);
	*o_buf = tmp_buf;
	return (1);
}

int	trim_buf(char **s_buf, char **line)
{
	char	*tmp_buf;

	tmp_buf = ft_strchr(*s_buf, '\n');
	if (tmp_buf)
	{
		*tmp_buf = '\0';
		*line = ft_strdup(*s_buf);
		if (!(*line))
			return (free_buf(s_buf));
		tmp_buf++;
		tmp_buf = ft_strdup(tmp_buf);
		if (!tmp_buf)
			return (free_buf(s_buf));
		free(*s_buf);
		*s_buf = tmp_buf;
		return (1);
	}
	tmp_buf = ft_strchr(*s_buf, '\0');
	*line = ft_strdup(*s_buf);
	if (!(*line))
		return (free_buf(s_buf));
	free(*s_buf);
	*s_buf = (char *)0;
	return (0);
}

int	init_buf(char **buf)
{
	if (!(*buf))
		*buf = ft_strdup("");
	if (!(*buf))
		return (-1);
	return (1);
}

int	free_buf(char **buf)
{
	if (!(*buf))
		free(*buf);
	*buf = (char *)(0);
	return (-1);
}
