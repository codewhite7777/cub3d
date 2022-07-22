/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   content_checker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alee <alee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 14:41:27 by dongkim           #+#    #+#             */
/*   Updated: 2022/07/22 15:17:55 by alee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include "../libft/libft.h"
#include "../utils/ft_utils_01.h"
#include "../utils/ft_utils_02.h"
#include "content_checker.h"
#include "../utils/debug.h"

// 맵에 들어와야하는 문자만 들어왔는지(공백, NEWS, 012),
// player가 한개인지 체크
static int	set_content_data(t_cub3d *p_data)
{
	int	idx;
	int	line_len;

	while (!ft_strlen(p_data->file_ptr[p_data->content_data.content_idx]))
		p_data->content_data.content_idx++;
	idx = p_data->content_data.content_idx;
	while (ft_strlen(p_data->file_ptr[idx]) && idx < p_data->file_line)
	{
		line_len = ft_strlen(p_data->file_ptr[idx]);
		if (p_data->content_data.content_len < line_len)
			p_data->content_data.content_len = line_len;
		if (ft_isin_line(p_data->file_ptr[idx], "\t\n\v\f\r NEWS012") != line_len)
			return (0);
		p_data->content_data.player_cnt
			+= ft_isin_line(p_data->file_ptr[idx], "NEWS");
		p_data->content_data.content_line++;
		idx++;
	}
	while (idx < p_data->file_line && ft_strlen(p_data->file_ptr[idx]) == 0)
		idx++;
	return (idx == p_data->file_line && p_data->content_data.player_cnt == 1);
}

static char	**content_malloc(t_cub3d *p_data, char setval)
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

static void	set_content(t_cub3d *p_data)
{
	int	i;
	int	j;
	int	line_len;

	i = 0;
	while (i < p_data->content_data.content_line)
	{
		j = 0;
		line_len
			= ft_strlen(p_data->file_ptr[p_data->content_data.content_idx + i]);
		while (j < line_len)
		{
			p_data->content_data.content_ptr[i][j]
				+= p_data->file_ptr[p_data->content_data.content_idx + i][j];
			j++;
		}
		i++;
	}
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

static void	content_close_check(t_cub3d *p_data)
{
	char	**visit_ptr;
	int		i;
	int		j;

	visit_ptr = content_malloc(p_data, 0);
	if (visit_ptr == 0)
		ft_exit("Error\nMemory allocation error", 1);
	i = 0;
	while (i < p_data->content_data.content_line)
	{
		j = 0;
		while (j < p_data->content_data.content_len)
		{
			if (p_data->content_data.content_ptr[i][j] >= 0
				&& p_data->content_data.content_ptr[i][j] != 1
				&& visit_ptr[i][j] == 0)
				dfs_content_check(p_data, visit_ptr, i, j);
			j++;
		}
		i++;
	}
	debug_print_dptr_toint("===== VISIT =====", visit_ptr, i, j);
	debug_print_dptr_toint("===== CONTENT =====", \
	p_data->content_data.content_ptr, i, j);
	ft_dptr_free(visit_ptr, p_data->content_data.content_line);
}

void	content_checker(t_cub3d *p_data)
{
	if (!set_content_data(p_data))
		ft_exit("Error\nInvalid map content", 1);
	p_data->content_data.content_ptr = content_malloc(p_data, -0x30);
	if (p_data->content_data.content_ptr == 0)
		ft_exit("Error\nMemory allocation error", 1);
	set_content(p_data);
	content_close_check(p_data);
}
