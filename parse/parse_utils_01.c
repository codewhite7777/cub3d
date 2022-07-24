/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils_01.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alee <alee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 14:38:04 by alee              #+#    #+#             */
/*   Updated: 2022/07/25 04:20:21 by alee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_utils_01.h"
#include "../libft/libft.h"

char	*line_convert(char *line)
{
	int	idx;

	idx = 0;
	while (line[idx] != '\0')
	{
		if (ft_isspace(line[idx]))
			line[idx] = ' ';
		idx++;
	}
	return (line);
}

int	insert_rgb(int r, int g, int b)
{
	int	ret;

	ret = 0;
	ret |= (r << 16);
	ret |= (g << 8);
	ret |= b;
	return (ret);
}
