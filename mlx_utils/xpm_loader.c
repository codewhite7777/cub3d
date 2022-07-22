/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpm_loader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alee <alee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 13:43:50 by alee              #+#    #+#             */
/*   Updated: 2022/07/22 14:10:34 by alee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include <mlx.h>
#include "xpm_loader.h"

int	xpm_load(t_cub3d *p_data)
{
	int	idx;
	int	err;

	idx = 0;
	err = 0;
	while (idx < ASSET_MAX)
	{
		p_data->xpm_data[idx].img = mlx_xpm_file_to_image(p_data->mlx.mlx, \
		p_data->parse_data.asset_file[idx], &p_data->xpm_data[idx].width, \
		&p_data->xpm_data[idx].height);
		if (!p_data->xpm_data[idx].img)
		{
			xpm_free(idx, p_data);
			return (!err);
		}
		idx++;
	}
	return (err);
}

void	xpm_free(int index, t_cub3d *p_data)
{
	int	idx;

	idx = 0;
	while (idx < index)
	{
		mlx_destroy_image(p_data->mlx.mlx, p_data->xpm_data[idx].img);
		idx++;
	}
	return ;
}
