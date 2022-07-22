/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alee <alee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 14:52:10 by alee              #+#    #+#             */
/*   Updated: 2022/07/22 17:09:59 by alee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include "event_hook.h"
#include <stdlib.h>

//debug
#include <stdio.h>

int	key_event(int keycode, t_cub3d *p_data)
{
	if (keycode == event_key_up)
		printf("UP\n");
	if (keycode == event_key_down)
		printf("DOWN\n");
	if (keycode == event_key_left)
		printf("LEFT\n");
	if (keycode == event_key_right)
		printf("RIGHT\n");
	if (keycode == event_key_esc)
	{
		printf("ESC\n");
		close_data(p_data);
	}
	(void)p_data;
	return (0);
}

int	exit_event(t_cub3d *p_data)
{
	printf("cub3d exit\n");
	close_data(p_data);
	return (0);
}
