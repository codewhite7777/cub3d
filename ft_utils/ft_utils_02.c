/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_02.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alee <alee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 03:42:04 by alee              #+#    #+#             */
/*   Updated: 2022/07/30 03:43:28 by alee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils_02.h"

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
