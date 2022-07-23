/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   content_checker_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongkim <dongkim@student.42seoul.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 20:39:15 by dongkim           #+#    #+#             */
/*   Updated: 2022/07/23 20:39:36 by dongkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "content_checker.h"

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
