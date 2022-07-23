/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alee <alee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 14:52:10 by alee              #+#    #+#             */
/*   Updated: 2022/07/24 01:34:24 by dongkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include "event_hook.h"
#include <stdlib.h>

//debug
#include <stdio.h>

int	key_event(int keycode, t_cub3d *p_data)
{
	if (keycode == event_key_up || keycode == event_key_down
		|| keycode == event_key_left || keycode == event_key_right
		|| keycode == event_key_arrow_left
		|| keycode == event_key_arrow_right
		|| keycode == event_key_arrow_up
		|| keycode == event_key_arrow_down)
		p_data->key_pressed[(unsigned char)keycode] = 1;
	if (keycode == event_key_up)
		printf("UP\n");
	else if (keycode == event_key_down)
		printf("DOWN\n");
	else if (keycode == event_key_left)
		printf("LEFT\n");
	else if (keycode == event_key_right)
		printf("RIGHT\n");
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
		|| keycode == event_key_arrow_down)
		p_data->key_pressed[(unsigned char)keycode] = 0;
	if (keycode == event_key_up)
		printf("UP RELEASE\n");
	else if (keycode == event_key_down)
		printf("DOWN RELEASE\n");
	else if (keycode == event_key_left)
		printf("LEFT RELEASE\n");
	else if (keycode == event_key_right)
		printf("RIGHT RELEASE\n");
	return (0);
}

int	exit_event(t_cub3d *p_data)
{
	printf("cub3d exit\n");
	close_data(p_data);
	return (0);
}
