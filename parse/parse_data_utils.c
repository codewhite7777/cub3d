/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_data_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alee <alee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 00:37:37 by alee              #+#    #+#             */
/*   Updated: 2022/07/30 00:39:29 by alee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../libft/libft.h"

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
