/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_player.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alee <alee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 04:26:11 by alee              #+#    #+#             */
/*   Updated: 2022/07/30 04:34:03 by alee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_PLAYER_H
# define SET_PLAYER_H
# include "../cub3d.h"

void	set_player(t_cub3d *p_data);
double	trans_radian(unsigned char direction);
void	set_player_info(t_cub3d *p_data);

#endif
