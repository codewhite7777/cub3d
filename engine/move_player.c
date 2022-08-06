/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alee <alee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 01:22:05 by dongkim           #+#    #+#             */
/*   Updated: 2022/08/06 20:27:00 by dongkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "move_player.h"
#include "engine_utils.h"
#include <mlx.h>

static void	move_player_calculator(t_cub3d *p_data,
	int x_cor, int y_cor, double radian)
{
	double			tmp;
	t_player_data	*player;
	t_content_data	*content;
	char			tile;

	player = &p_data->player;
	content = &p_data->content_data;
	tmp = player->pos.x + (x_cor * cos(radian)) * 0.001 * PLAYER_SPEED;
	tile = content->content_ptr[(unsigned int)player->pos.y][(unsigned int)tmp];
	if (tile != TILE_WALL && !(tile >= TILE_DOOR_C && tile < TILE_DOOR_O))
		player->pos.x = tmp;
	tmp = player->pos.y + (y_cor * sin(radian)) * 0.001 * PLAYER_SPEED;
	tile = content->content_ptr[(unsigned int)tmp][(unsigned int)player->pos.x];
	if (tile != TILE_WALL && !(tile >= TILE_DOOR_C && tile < TILE_DOOR_O))
		player->pos.y = tmp;
	p_data->update = 1;
}

static void	player_angle_calculator(t_cub3d *p_data, int dir)
{
	p_data->player.radian
		= radian_correction(p_data->player.radian + (ONE_TO_RAD * dir));
	p_data->update = 1;
}

void	move_player(t_cub3d *p_data, char *key_pressed)
{
	t_player_data	*player;

	player = &p_data->player;
	if (key_pressed[event_key_up])
		move_player_calculator(p_data, 1, 1, player->radian);
	if (key_pressed[event_key_down])
		move_player_calculator(p_data, -1, -1, player->radian);
	if (key_pressed[event_key_left])
		move_player_calculator(p_data, 1, -1, (PI / 2) - player->radian);
	if (key_pressed[event_key_right])
		move_player_calculator(p_data, -1, 1, (PI / 2) - player->radian);
	if (key_pressed[event_key_arrow_left])
		player_angle_calculator(p_data, -1);
	if (key_pressed[event_key_arrow_right])
		player_angle_calculator(p_data, 1);
}

void	move_mouse(t_cub3d *p_data)
{
	int	x;
	int	y;

	mlx_mouse_get_pos(p_data->mlx.mlx_win, &x, &y);
	if (x != WIN_WIDTH / 2)
	{
		mlx_mouse_hide();
		p_data->player.radian
			= radian_correction(p_data->player.radian + ONE_TO_RAD \
			* (((double)(x - (WIN_WIDTH / 2)) *MOUSE_SPEED) / 100));
		mlx_mouse_move(p_data->mlx.mlx_win, WIN_WIDTH / 2, 0);
		mlx_mouse_get_pos(p_data->mlx.mlx_win, &x, &y);
		p_data->update = 1;
	}
}
