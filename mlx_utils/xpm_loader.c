/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpm_loader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alee <alee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 13:43:50 by alee              #+#    #+#             */
/*   Updated: 2022/08/10 14:44:11 by dongkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../base/cub3d.h"
#include <mlx.h>
#include "xpm_loader.h"
#include <stdlib.h>
#include "../utils/ft_utils_01.h"
#include "../utils/ft_utils_02.h"

int	xpm_load(t_cub3d *p_data)
{
	int	idx;

	idx = 0;
	while (idx < ASSET_MAX)
	{
		p_data->xpm_data[idx].img = mlx_xpm_file_to_image(p_data->mlx.mlx, \
			p_data->parse_data.asset_file[idx], \
			(int *)&p_data->xpm_data[idx].width, \
			(int *)&p_data->xpm_data[idx].height);
		if (!p_data->xpm_data[idx].img)
		{
			ft_dptr_free(p_data->file_ptr, p_data->file_line);
			ft_dptr_free(p_data->content_data.content_ptr,
				p_data->content_data.content_line);
			xpm_buf_free(idx, p_data);
			ft_exit("Error\nInvalid xpm file", 1);
		}
		p_data->xpm_data[idx].addr \
			= mlx_get_data_addr(p_data->xpm_data[idx].img, \
			&p_data->xpm_data[idx].bits_per_pixel, \
			&p_data->xpm_data[idx].line_length, &p_data->xpm_data[idx].endian);
		idx++;
	}
	return (0);
}

void	xpm_buf_free(int index, t_cub3d *p_data)
{
	int	idx;

	idx = 0;
	while (idx < index)
	{
		free(p_data->parse_data.asset_file[idx]);
		mlx_destroy_image(p_data->mlx.mlx, p_data->xpm_data[idx].img);
		idx++;
	}
	return ;
}
