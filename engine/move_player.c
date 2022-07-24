/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongkim <dongkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 01:22:05 by dongkim           #+#    #+#             */
/*   Updated: 2022/07/24 23:16:36 by dongkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "move_player.h"

static void	move_player_calculator(t_cub3d *p_data,
	int x_cor, int y_cor, double radian)
{
	double			tmp;
	t_player_data	*player;
	t_content_data	*content;

	player = &p_data->player;
	content = &p_data->content_data;
	tmp = player->xpos + (x_cor * cos(radian)) * 0.1;
	if (content->content_ptr[(unsigned int)player->ypos][(unsigned int)tmp] != 1)
		player->xpos = tmp;
	tmp = player->ypos + (y_cor * sin(radian)) * 0.1;
	if (content->content_ptr[(unsigned int)tmp][(unsigned int)player->xpos] != 1)
		player->ypos = tmp;
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
		player->radian = (player->radian - ONE_TO_RAD);
	if (key_pressed[event_key_arrow_right])
		player->radian = (player->radian + ONE_TO_RAD);
	if (player->radian < 0)
		player->radian += (2 * PI);
	if (player->radian >= (2 * PI))
		player->radian -= (2 * PI);
}

