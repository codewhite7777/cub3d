/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongkim <dongkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 17:31:21 by dongkim           #+#    #+#             */
/*   Updated: 2022/07/29 22:57:34 by dongkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw_minimap.h"

static void	tile_selector(t_cub3d *p_data, int *idx, unsigned int *pos,
	unsigned int tile_size)
{
	char			c;
	unsigned int	*uidx;

	if (idx[1] < 0 || idx[0] < 0)
	{
		mlx_draw_square(&p_data->mlx.img, pos,
			tile_size, COLOR_NONE);
	}
	else
	{
		uidx = (unsigned int *)idx;
		c = p_data->content_data.content_ptr[uidx[1]][uidx[0]];
		if (c == 1)
			mlx_draw_square(&p_data->mlx.img, pos, tile_size, COLOR_WALL);
		else if (c == 0 || c == 2)
			mlx_draw_square(&p_data->mlx.img, pos, tile_size, COLOR_FLOOR);
		else
			mlx_draw_square(&p_data->mlx.img, pos, tile_size, COLOR_NONE);
	}
}

#include <stdio.h>
static void	draw_content(t_cub3d *p_data, t_minimap_setting *settings)
{
	while ()
	{
		while ()
		{
		}
	}
}

void	draw_minimap_2(t_cub3d *p_data, t_minimap_setting *settings)
{
	unsigned int	bak_wh[2];
	
	if (settings->size.width && settings->size.height && settings->tile_size)
	{
	/*	bak_wh[0] = p_data->mlx.img.width;
		bak_wh[1] = p_data->mlx.img.height;
		p_data->mlx.img.width = settings->size.width * settings->tile_size
			+ settings->pos[0];
		p_data->mlx.img.height = settings->size.height *settings->tile_size
			+ settings->pos[1];*/
		draw_content(p_data, settings);
	/*	p_data->mlx.img.width = bak_wh[0];
		p_data->mlx.img.height = bak_wh[1];*/
	}
}
