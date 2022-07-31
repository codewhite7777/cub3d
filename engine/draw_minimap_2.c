/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongkim <dongkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 17:31:21 by dongkim           #+#    #+#             */
/*   Updated: 2022/08/01 03:40:26 by dongkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw_minimap.h"
#include <math.h>

static void	tile_selector(t_cub3d *p_data, int *pos, int *idx,
	unsigned int tile_size)
{
	char			c;
	unsigned int	*upos;

	upos = (unsigned int *)pos;
	if (idx[1] < 0 || idx[0] < 0
			|| idx[1] >= p_data->content_data.content_line
			|| idx[0] >= p_data->content_data.content_len)
	{
		mlx_draw_square(&p_data->minimap.img, upos,
			tile_size, COLOR_NONE);
	}
	else
	{
		c = p_data->content_data.content_ptr[idx[1]][idx[0]];
		if (c == 1)
			mlx_draw_square(&p_data->minimap.img, upos, tile_size, COLOR_WALL);
		else if (c == 0 || c == 2)
			mlx_draw_square(&p_data->minimap.img, upos, tile_size, COLOR_FLOOR);
		else
			mlx_draw_square(&p_data->minimap.img, upos, tile_size, COLOR_NONE);
	}
}

static void	draw_content(t_cub3d *p_data)
{
	int				pos[2];
	int				idx[2];
	unsigned int	tile_size;

	tile_size = p_data->minimap.tile_size;
	idx[1] = (int)p_data->player.pos.y - p_data->minimap.height / 2;
	pos[1] = ((int)p_data->player.pos.y - p_data->player.pos.y) * tile_size;
	while (pos[1] < (int)(tile_size * p_data->minimap.height))
	{
		idx[0] = (int)p_data->player.pos.x - p_data->minimap.width / 2;
		pos[0] = ((int)p_data->player.pos.x - p_data->player.pos.x) * tile_size;
		while (pos[0] < (int)(tile_size * p_data->minimap.width))
		{
			tile_selector(p_data, pos, idx, tile_size);
			pos[0] += tile_size;
			idx[0]++;
		}
		pos[1] += tile_size;
		idx[1]++;
	}
}

static void draw_player(t_cub3d *p_data, unsigned int *ppos)
{
	unsigned int	player_size;
	t_minimap		*minimap;
	unsigned int	pos[2];

	minimap = &p_data->minimap;
	player_size = minimap->tile_size / 3;
	ppos[0] = minimap->width / 2 * minimap->tile_size;
	ppos[1] = minimap->height / 2 * minimap->tile_size;
	pos[0] = ppos[0] - player_size / 2;
	pos[1] = ppos[1] - player_size / 2;
	mlx_draw_square(&minimap->img, pos, player_size, COLOR_PLAYER);
}

static void	draw_sight(t_cub3d *p_data, unsigned int *ppos,
	unsigned int distance)
{
	double			radian;
	double			d_radian;
	unsigned int	dpos[2];

	radian = p_data->player.radian - (ONE_TO_RAD * WIN_FOV / 2);
	d_radian = p_data->player.radian + (ONE_TO_RAD * WIN_FOV / 2);
	while (radian < d_radian)
	{
		dpos[0] = cos(radian) * p_data->minimap.tile_size * distance
			+ ppos[0];
		dpos[1] = sin(radian) * p_data->minimap.tile_size * distance
			+ ppos[1];
		mlx_draw_line(&p_data->minimap.img, ppos, dpos, COLOR_RAY);
		radian += ONE_TO_RAD;
	}
}

void	draw_minimap_2(t_cub3d *p_data)
{
	unsigned int	ppos[2];

	if (p_data->minimap.width && p_data->minimap.height
			&& p_data->minimap.tile_size)
	{
		draw_content(p_data);
		draw_player(p_data, ppos);
		draw_sight(p_data, ppos, 3);
		mlx_put_image_to_image(&p_data->mlx.img, &p_data->minimap.img,
			p_data->minimap.pos);
	}
}
