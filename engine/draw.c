/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alee <alee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 04:43:14 by alee              #+#    #+#             */
/*   Updated: 2022/07/30 17:31:41 by alee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include <mlx.h>
//debug
#include <stdlib.h>

void	draw_screen(t_cub3d *p_data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < WIN_HEIGHT)
	{
		while (j < WIN_WIDTH)
		{
			p_data->mlx.img.addr[(i * WIN_WIDTH) + j] = rand() % 255;
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(p_data->mlx.mlx,
		p_data->mlx.mlx_win, p_data->mlx.img.img, 0, 0);
	return ;
}
