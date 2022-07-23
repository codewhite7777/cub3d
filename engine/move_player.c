/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongkim <dongkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 01:22:05 by dongkim           #+#    #+#             */
/*   Updated: 2022/07/24 06:17:28 by dongkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "move_player.h"

static void	move_player_calculator(t_player_data *player,
	int x_cor, int y_cor, double radian)
{
	player->xpos += (x_cor * cos(radian)) * 0.1;
	player->ypos += (y_cor * sin(radian)) * 0.1;
}

void	move_player(t_player_data *player, char *key_pressed)
{
	if (key_pressed[event_key_up])
		move_player_calculator(player, 1, 1, player->radian);
	if (key_pressed[event_key_down])
		move_player_calculator(player, -1, -1, player->radian);
	if (key_pressed[event_key_left])
		move_player_calculator(player, 1, -1, (PI / 2) - player->radian);
	if (key_pressed[event_key_right])
		move_player_calculator(player, -1, 1, (PI / 2) - player->radian);
	if (key_pressed[event_key_arrow_left])
		player->radian = (player->radian - ONE_TO_RAD);
	if (key_pressed[event_key_arrow_right])
		player->radian = (player->radian + ONE_TO_RAD);
	if (player->radian < 0)
		player->radian += (2 * PI);
	if (player->radian >= (2 * PI))
		player->radian -= (2 * PI);
}

