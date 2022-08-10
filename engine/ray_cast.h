/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alee <alee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 22:49:38 by dongkim           #+#    #+#             */
/*   Updated: 2022/08/10 14:49:57 by dongkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_CAST_H
# define RAY_CAST_H

# include "../base/cub3d.h"
# include <math.h>

typedef struct s_raycast
{
	double	x_len;
	double	y_len;
	double	x_asix_near_rdist;
	double	y_asix_near_rdist;
	double	x_one_move_rdist;
	double	y_one_move_rdist;
	double	distance;
	int		dir;
	int		x_dir;
	int		y_dir;
	double	radian;
}				t_raycast;

typedef struct s_draw_wall
{
	int		wall_dir;
	double	vertical_len;
	double	ray_wall_dpos[2];
	double	ray_door_dpos[2];
	double	door_vertical_len;
	int		door_pos[2];
	double	door_distance;
	char	door_status;
	int		door_dir;
}				t_draw_wall;

double	ray_cast_distance(t_cub3d *p_data, double radian, t_draw_wall *wall);

#endif
