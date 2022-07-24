/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alee <alee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 00:07:33 by alee              #+#    #+#             */
/*   Updated: 2022/07/25 04:20:34 by alee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include "../libft/libft.h"
#include "../utils/ft_utils_01.h"
#include "../utils/ft_utils_02.h"
#include "parse_data.h"
#include "parse_utils_01.h"

int	parse_data(t_cub3d *p_data)
{
	int		idx;
	int		parse_cnt;
	t_parse	parse_type;

	parse_cnt = 0;
	idx = 0;
	while (idx < p_data->file_line && parse_cnt < 6)
	{
		parse_type = parse_line(p_data->file_ptr[idx], p_data);
		if (parse_type == PARSE_ERROR)
			ft_exit("Error\nInvalid parse symbol", 1);
		if (parse_type != PARSE_NONE)
			parse_cnt++;
		p_data->parse_flag |= parse_type;
		idx++;
	}
	p_data->content_data.content_idx = idx;
	if (p_data->parse_flag != PARSE_FINISH)
	{
		ft_dptr_free(p_data->file_ptr, p_data->file_line);
		ft_exit("Error\nIncomplete data", 1);
	}
	return (0);
}

t_parse	parse_line(char *line, t_cub3d *p_data)
{
	if (ft_strnstr(line, "NO", ft_strlen(line)))
		return (parse_asset(line, NO, PARSE_NORTH, p_data));
	else if (ft_strnstr(line, "SO", ft_strlen(line)))
		return (parse_asset(line, SO, PARSE_SOUTH, p_data));
	else if (ft_strnstr(line, "WE", ft_strlen(line)))
		return (parse_asset(line, WE, PARSE_WEST, p_data));
	else if (ft_strnstr(line, "EA", ft_strlen(line)))
		return (parse_asset(line, EA, PARSE_EAST, p_data));
	else if (ft_strnstr(line, "F", ft_strlen(line)))
		return (parse_rgb(line, "F", PARSE_FLOOR, p_data));
	else if (ft_strnstr(line, "C", ft_strlen(line)))
		return (parse_rgb(line, "C", PARSE_CEIL, p_data));
	if (ft_strlen(line))
		return (PARSE_ERROR);
	return (PARSE_NONE);
}

int	parse_asset(char *line, t_asset type, t_parse ret, t_cub3d *p_data)
{
	char	**buf;

	buf = ft_split(line_convert(line), ' ');
	if (!buf)
	{
		ft_dptr_free(p_data->file_ptr, p_data->file_line);
		ft_exit("Error\nMemory allocation fail(split)", 1);
	}
	if (split_count(&buf) != 2)
	{
		split_free(buf);
		return (PARSE_NONE);
	}
	p_data->parse_data.asset_file[type] = ft_strdup(buf[1]);
	split_free(buf);
	return (ret);
}

int	parse_rgb(char *line, const char *type, t_parse ret, t_cub3d *p_data)
{
	char	**buf;

	buf = ft_split(line_convert(ft_strchr(line_convert(line), *type) + 1), ',');
	if (!buf)
	{
		ft_dptr_free(p_data->file_ptr, p_data->file_line);
		ft_exit("Error\nMemory allocation fail(split)", 1);
	}
	if (split_count(&buf) != 3)
	{
		split_free(buf);
		return (PARSE_NONE);
	}
	if (*type == 'C')
		p_data->parse_data.c_color = \
		insert_rgb(ft_atoi(buf[0]), ft_atoi(buf[1]), ft_atoi(buf[2]));
	if (*type == 'F')
		p_data->parse_data.f_color = \
		insert_rgb(ft_atoi(buf[0]), ft_atoi(buf[1]), ft_atoi(buf[2]));
	split_free(buf);
	return (ret);
}
