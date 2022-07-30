/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alee <alee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 16:29:48 by alee              #+#    #+#             */
/*   Updated: 2022/07/30 16:33:37 by alee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOVE_H
# define MOVE_H
# include "../cub3d.h"

int		move(t_cub3d *p_data);
void	move_front(t_cub3d *p_data);
void	move_back(t_cub3d *p_data);
void	move_left(t_cub3d *p_data);
void	move_right(t_cub3d *p_data);

#endif
