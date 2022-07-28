/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongkim <dongkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 01:21:17 by dongkim           #+#    #+#             */
/*   Updated: 2022/07/27 19:35:11 by dongkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOVE_PLAYER_H
# define MOVE_PLAYER_H

# include "../mlx_utils/event_hook.h"
# include "../cub3d.h"
# include <math.h>

void	move_player(t_cub3d *p_data, char *key_pressed);

#endif
