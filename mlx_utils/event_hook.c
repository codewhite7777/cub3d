/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alee <alee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 14:52:10 by alee              #+#    #+#             */
/*   Updated: 2022/08/06 07:39:00 by dongkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include "event_hook.h"
#include <stdlib.h>
#include <mlx.h>

//debug
#include <stdio.h>

int	key_event(int keycode, t_cub3d *p_data)
{
	if ((keycode == event_key_up || keycode == event_key_down
		|| keycode == event_key_left || keycode == event_key_right
		|| keycode == event_key_arrow_left || keycode == event_key_arrow_right
		|| keycode == event_key_arrow_up || keycode == event_key_arrow_down
		|| keycode == event_key_tab || keycode == event_key_space)
		&& p_data->key_pressed[(unsigned char)keycode] == 0)
	{
		p_data->key_pressed[(unsigned char)keycode] = 1;
		p_data->update = 1;
		if (keycode == event_key_tab)
			p_data->minimap.sw = !p_data->minimap.sw;
		else if (keycode == event_key_space)
			;
	}
	else if (keycode == event_key_esc)
	{
		printf("ESC\n");
		close_data(p_data);
	}
	return (0);
}

int	key_release_event(int keycode, t_cub3d *p_data)
{
	if (keycode == event_key_up || keycode == event_key_down
		|| keycode == event_key_left || keycode == event_key_right
		|| keycode == event_key_arrow_left
		|| keycode == event_key_arrow_right
		|| keycode == event_key_arrow_up
		|| keycode == event_key_arrow_down
		|| keycode == event_key_tab)
		p_data->key_pressed[(unsigned char)keycode] = 0;
	return (0);
}

int	exit_event(t_cub3d *p_data)
{
	printf("cub3d exit\n");
	close_data(p_data);
	return (0);
}
