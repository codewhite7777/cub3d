/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongkim <dongkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 01:21:17 by dongkim           #+#    #+#             */
/*   Updated: 2022/07/24 23:08:36 by dongkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOVE_PLAYER_H
# define MOVE_PLAYER_H

# define PI			3.14159265359
# define ONE_TO_RAD	0.01745329251

# include "../mlx_utils/event_hook.h"
# include <math.h>

void	move_player(t_cub3d *p_data, char *key_pressed);

#endif
