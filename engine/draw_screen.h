/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_screen.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alee <alee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 23:52:23 by alee              #+#    #+#             */
/*   Updated: 2022/08/06 05:48:50 by dongkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_SCREEN_H
# define DRAW_SCREEN_H
# include "../cub3d.h"

typedef struct s_radian_calc
{
	double	radian;
	double	rad_per_pixel;
}				t_radian_calc;

void	draw_screen(t_cub3d *p_data);
void	draw_background(t_cub3d *p_data);

#endif
