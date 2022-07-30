/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_hook.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alee <alee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 02:29:58 by alee              #+#    #+#             */
/*   Updated: 2022/07/30 02:33:06 by alee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENT_HOOK_H
# define EVENT_HOOK_H
# include "../cub3d.h"

typedef enum e_x_event
{
	event_key_press = 2,
	event_key_release = 3,
	event_mouse_down = 4,
	event_mouse_up = 5,
	event_mouse_move = 6,
	event_window_destroy = 17,
}				t_x_event;

typedef enum e_key_event
{
	event_key_left = 0,
	event_key_down = 1,
	event_key_right = 2,
	event_key_up = 13,
	event_key_arrow_left = 123,
	event_key_arrow_up = 126,
	event_key_arrow_right = 124,
	event_key_arrow_down = 125,
	event_key_esc = 53,
}				t_key_event;

int	key_press_event(int keycode, t_cub3d *p_data);
int	key_release_event(int keycode, t_cub3d *p_data);
int	exit_event(t_cub3d *p_data);

#endif
