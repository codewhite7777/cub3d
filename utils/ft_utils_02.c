/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_02.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alee <alee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 15:13:00 by alee              #+#    #+#             */
/*   Updated: 2022/07/26 18:50:51 by dongkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils_02.h"
#include <stdlib.h>

//debug
#include <stdio.h>

int	ft_isin(char c, const char *del)
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

void	ft_ptr_free(char *ptr, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		free(ptr + i);
		i++;
	}
	return ;
}

int	ft_abs(int num)
{
	if (num < 0)
		num *= -1;
	return (num);
}