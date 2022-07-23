/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongkim <dongkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 01:22:05 by dongkim           #+#    #+#             */
/*   Updated: 2022/07/24 02:04:04 by dongkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "move_player.h"

void	move_player_calculator(t_cub3d *p_data)
{
	if (p_data->key_pressed[event_key_left])
		p_data->player.xpos -= 0.1;
	if (p_data->key_pressed[event_key_right])
		p_data->player.xpos += 0.1;
	if (p_data->key_pressed[event_key_up])
		p_data->player.ypos -= 0.1;
	if (p_data->key_pressed[event_key_down])
		p_data->player.ypos += 0.1;
	if (p_data->key_pressed[event_key_arrow_left])
		;
	if (p_data->key_pressed[event_key_arrow_right])
		;
}

