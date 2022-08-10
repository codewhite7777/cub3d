/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongkim <dongkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 01:21:17 by dongkim           #+#    #+#             */
/*   Updated: 2022/08/10 14:49:46 by dongkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOVE_PLAYER_H
# define MOVE_PLAYER_H

# include "../mlx_utils/event_hook.h"
# include "../base/cub3d.h"
# include <math.h>

void	move_player(t_cub3d *p_data, char *key_pressed);
void	move_mouse(t_cub3d *p_data);

#endif
