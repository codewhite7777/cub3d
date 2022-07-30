/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   content_checker_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alee <alee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 03:52:55 by alee              #+#    #+#             */
/*   Updated: 2022/07/30 04:27:44 by alee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include "../libft/libft.h"
#include <stdlib.h>
#include "../ft_utils/ft_utils_01.h"
#include "content_checker_utils.h"

char	**content_malloc(t_cub3d *p_data, char setval)
{
	int		i;
	char	**ret;

	ret = ft_calloc(p_data->content_data.content_line + 1, sizeof(char *));
	if (ret == 0)
		return (0);
	i = 0;
	while (i < p_data->content_data.content_line)
	{
		ret[i] = malloc(sizeof(char) * (p_data->content_data.content_len + 1));
		if (ret[i] == 0)
			return (0);
		ft_memset(ret[i], setval, p_data->content_data.content_len);
		i++;
	}
	return (ret);
}

void	dfs_content_check(t_cub3d *p_data, char **visit_ptr, int y, int x)
{
	if (!(x >= 0 && y >= 0
			&& x <= p_data->content_data.content_len - 1
			&& y <= p_data->content_data.content_line - 1))
		return ;
	if (p_data->content_data.content_ptr[y][x] == 1)
		return ;
	if (visit_ptr[y][x] == 1)
		return ;
	if (p_data->content_data.content_ptr[y][x] < 0)
		ft_exit("Error\nInvalid map content", 1);
	visit_ptr[y][x] = 1;
	dfs_content_check(p_data, visit_ptr, y - 1, x);
	dfs_content_check(p_data, visit_ptr, y + 1, x);
	dfs_content_check(p_data, visit_ptr, y, x - 1);
	dfs_content_check(p_data, visit_ptr, y, x + 1);
}
