/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_loader.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alee <alee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 20:39:10 by alee              #+#    #+#             */
/*   Updated: 2022/07/21 00:35:54 by alee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "../utils/ft_utils_01.h"
#include "../cub3d.h"
#include "../get_next_line/get_next_line.h"
#include <stdlib.h>
#include "../libft/libft.h"

int	file_check(const char *file_name)
{
	int	file_len;

	file_len = ft_strlen(file_name);
	if (file_len < 4)
		return (0);
	if (ft_strrchr(file_name, '.') == (char *)0 || \
	ft_strcmp(ft_strrchr(file_name, '.'), ".cub") != 0)
		return (0);
	return (1);
}

int	file_info(const char *file_name, t_cub3d *p_data)
{
	int		fd;
	char	*buf;

	buf = (char *)0;
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		ft_exit("Error\nInvalid map file", 1);
	while (get_next_line(fd, &buf) > 0)
	{
		free(buf);
		buf = (char *)0;
		p_data->map_line++;
	}
	if (buf)
		free(buf);
	p_data->map_line++;
	close(fd);
	if (p_data->map_line <= PARSE_MIN_LINE)
		ft_exit("Error\nNo map data", 1);
	return (0);
}

int	file_alloc(const char *file_name, t_cub3d *p_data)
{
	int		fd;
	int		idx;

	idx = 0;
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		ft_exit("Error\nInvalid map file", 1);
	p_data->map_ptr = (char **)malloc(sizeof(char *) * p_data->map_line);
	if (!p_data->map_ptr)
		ft_exit("Error\nMemory allocation fail", 1);
	while (idx < p_data->map_line)
	{
		get_next_line(fd, &p_data->map_ptr[idx]);
		if (!p_data->map_ptr[idx])
		{
			ft_map_free(p_data, idx);
			ft_exit("Error\nMemory allocationfail", 1);
		}
		idx++;
	}
	close(fd);
	return (0);
}
