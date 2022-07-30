/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alee <alee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 02:30:39 by alee              #+#    #+#             */
/*   Updated: 2022/07/30 04:59:13 by alee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include "event_hook.h"

int	key_press_event(int keycode, t_cub3d *p_data)
{
	if (keycode == event_key_up)
		p_data->key_w = 1;
	else if (keycode == event_key_down)
		p_data->key_s = 1;
	else if (keycode == event_key_left)
		p_data->key_a = 1;
	else if (keycode == event_key_right)
		p_data->key_d = 1;
	else if (keycode == event_key_esc)
		p_data->key_esc = 1;
	return (0);
}

int	key_release_event(int keycode, t_cub3d *p_data)
{
	if (keycode == event_key_up)
		p_data->key_w = 0;
	else if (keycode == event_key_down)
		p_data->key_s = 0;
	else if (keycode == event_key_left)
		p_data->key_a = 0;
	else if (keycode == event_key_right)
		p_data->key_d = 0;
	else if (keycode == event_key_esc)
		exit_event(p_data);
	return (0);
}

int	exit_event(t_cub3d *p_data)
{
	close_cub3d(p_data);
	return (0);
}
