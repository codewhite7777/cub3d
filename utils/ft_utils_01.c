/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_01.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alee <alee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 20:51:11 by alee              #+#    #+#             */
/*   Updated: 2022/07/21 11:40:16 by alee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../cub3d.h"

//debug
#include <stdio.h>

void	ft_exit(const char *msg, int exit_code)
{
	if (msg)
		ft_putstr_fd((char *)msg, STDERR_FILENO);
	exit(exit_code);
	return ;
}

void	ft_map_free(t_cub3d *p_data, int idx_max)
{
	int	idx;

	idx = 0;
	while (idx < idx_max)
	{
		free(p_data->map_ptr[idx]);
		idx++;
	}
	free(p_data->map_ptr);
	return ;
}

int	split_count(char ***buf)
{
	int	count;

	count = 0;
	while ((*buf)[count])
		count++;
	return (count);
}

void	split_free(char **buf)
{
	int	idx;

	idx = 0;
	while (buf[idx])
	{
		free(buf[idx]);
		idx++;
	}
	free(buf);
}

int ft_isin(char c, const char *del)
{
	int	idx;

	idx = 0;
	while (del[idx])
	{
		if (del[idx] == c)
			return (1);
		idx++;
	}
	return (0);
}

int	ft_isin_line(const char *line, const char *del)
{
	int	idx;
	int	cnt;

	idx = 0;
	cnt = 0;
	while (line[idx])
	{
		if (ft_isin(line[idx], del))
			cnt++;
		idx++;
	}
	return (cnt);
}

void	ft_dptr_free(char **dptr, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		free(dptr[i]);
		i++;
	}
	free(dptr);
}
