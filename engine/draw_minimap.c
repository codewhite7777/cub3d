/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alee <alee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 18:45:48 by dongkim           #+#    #+#             */
/*   Updated: 2022/08/05 17:34:05 by dongkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw_minimap.h"
#include "ray_cast.h"

static void	draw_content(t_cub3d *p_data, \
		unsigned int *bpos, unsigned int tile_size)
{
	unsigned int	pos[2];
	char			**content;
	char			c;
	int				idx;

	idx = p_data->mlx.img_idx;
	content = p_data->content_data.content_ptr;
	pos[1] = bpos[1];
	while (pos[1] < p_data->minimap.height + bpos[1])
	{
		pos[0] = bpos[0];
		while (pos[0] < p_data->minimap.width + bpos[0])
		{
			c = \
		content[(pos[1] - bpos[1]) / tile_size][(pos[0] - bpos[0]) / tile_size];
			if (c == 1)
				mlx_draw_square(&p_data->mlx.img[idx], pos, tile_size, COLOR_WALL);
			else if (c == 0 || c == 2)
				mlx_draw_square(&p_data->mlx.img[idx], pos, tile_size, COLOR_FLOOR);
			else
				mlx_draw_square(&p_data->mlx.img[idx], pos, tile_size, COLOR_NONE);
			pos[0] += tile_size;
		}
		pos[1] += tile_size;
	}
}

static void	draw_player(t_player_data *player, t_img *img, \
	unsigned int *bpos, unsigned int tile_size)
{
	unsigned int	pos[2];
	unsigned int	player_size;

	player_size = tile_size / 3;
	pos[0] = player->pos.x * tile_size - (player_size / 2) + bpos[0];
	pos[1] = player->pos.y * tile_size - (player_size / 2) + bpos[1];
	if (player_size == 0)
		player_size = 1;
	mlx_draw_square(img, pos, player_size, COLOR_PLAYER);
}

static void	draw_sight(t_cub3d *p_data, unsigned int *pos, \
	unsigned int tile_size)
{
	unsigned int	ppos[2];
	unsigned int	dpos[2];
	double			rpos[2];
	double			radian;
	int				idx;

	idx = p_data->mlx.img_idx;
	ppos[0] = p_data->player.pos.x * tile_size + pos[0];
	ppos[1] = p_data->player.pos.y * tile_size + pos[1];
	radian = p_data->player.radian - (ONE_TO_RAD * WIN_FOV / 2);
	while (radian < p_data->player.radian + (ONE_TO_RAD * WIN_FOV / 2))
	{
		ray_cast_distance(p_data, radian, rpos, 0);
		dpos[0] = rpos[0] * tile_size + pos[0];
		dpos[1] = rpos[1] * tile_size + pos[1];
		mlx_draw_line(&p_data->mlx.img[idx], ppos, dpos, COLOR_RAY);
		radian += ONE_TO_RAD;
	}
}

void	init_minimap(t_cub3d *p_data)
{
	t_minimap	*minimap;

	minimap = &p_data->minimap;
	minimap->sw = 1;
	minimap->width = MINIMAP_WIDTH;
	minimap->height = MINIMAP_HEIGHT;
	minimap->pos[0] = MINIMAP_XPOS;
	minimap->pos[1] = MINIMAP_YPOS;
	minimap->tile_size = MINIMAP_TILESZ;
	minimap->img.width = minimap->width * minimap->tile_size;
	minimap->img.height = minimap->height * minimap->tile_size;
	minimap->img.img = mlx_new_image(p_data->mlx.mlx,
			minimap->img.width, minimap->img.height);
	minimap->img.addr = mlx_get_data_addr(minimap->img.img,
			&minimap->img.bits_per_pixel,
			&minimap->img.line_length,
			&minimap->img.endian);
}

void	draw_minimap(t_cub3d *p_data)
{
	t_minimap	*minimap;

	minimap = &p_data->minimap;
	if (minimap->tile_size)
	{
		minimap->width = p_data->content_data.content_len
			* minimap->tile_size;
		minimap->height = p_data->content_data.content_line
			* minimap->tile_size;
		draw_content(p_data, minimap->pos, minimap->tile_size);
		draw_player(&p_data->player, &p_data->mlx.img[p_data->mlx.img_idx], minimap->pos, \
				minimap->tile_size);
		draw_sight(p_data, minimap->pos, minimap->tile_size);
	}
}
