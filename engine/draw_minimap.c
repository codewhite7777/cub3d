/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alee <alee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 18:45:48 by dongkim           #+#    #+#             */
/*   Updated: 2022/07/25 04:30:32 by alee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw_minimap.h"

static void	init_minimap(t_cub3d *p_data, t_minimap *p_map, \
													unsigned int tile_size)
{
	p_map->width = p_data->content_data.content_len * tile_size;
	p_map->height = p_data->content_data.content_line * tile_size;
}

static void	draw_content(t_cub3d *p_data, t_minimap *map, \
								unsigned int *bpos, unsigned int tile_size)
{
	unsigned int	pos[2];
	char			**content;
	char			c;

	content = p_data->content_data.content_ptr;
	pos[1] = bpos[1];
	while (pos[1] < map->height + bpos[1])
	{
		pos[0] = bpos[0];
		while (pos[0] < map->width + bpos[0])
		{
			c = \
		content[(pos[1] - bpos[1]) / tile_size][(pos[0] - bpos[0]) / tile_size];
			if (c == 1)
				mlx_draw_square(&p_data->mlx.img, pos, tile_size, 0x00000000);
			else if (c == 0 || c == 2)
				mlx_draw_square(&p_data->mlx.img, pos, tile_size, 0x00FFFFFF);
			else
				mlx_draw_square(&p_data->mlx.img, pos, tile_size, 0xAAAAAAAA);
			pos[0] += tile_size;
		}
		pos[1] += tile_size;
	}
}

static void	draw_player(t_player_data *player, t_img *img,
	unsigned int *bpos, unsigned int tile_size)
{
	unsigned int	pos[2];
	unsigned int	player_size;

	player_size = tile_size / 3;
	pos[0] = player->pos.x * tile_size - (player_size / 2) + bpos[0];
	pos[1] = player->pos.y * tile_size - (player_size / 2) + bpos[1];
	if (player_size == 0)
		player_size = 1;
	mlx_draw_square(img, pos, player_size, 0x00FF0000);
}

void	draw_minimap(t_cub3d *p_data, unsigned int x, unsigned int y,
		unsigned int tile_size)
{
	t_minimap		minimap;
	unsigned int	pos[2];

	pos[0] = x;
	pos[1] = y;
	init_minimap(p_data, &minimap, tile_size);
	draw_content(p_data, &minimap, pos, tile_size);
	draw_player(&p_data->player, &p_data->mlx.img, pos, tile_size);
	return ;
}
