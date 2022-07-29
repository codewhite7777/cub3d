/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongkim <dongkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 22:49:38 by dongkim           #+#    #+#             */
/*   Updated: 2022/07/29 17:50:01 by dongkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_CAST_H
# define RAY_CAST_H

# include "../cub3d.h"
# include <math.h>

typedef struct s_raycast
{
    double  x_len;
    double  y_len;
    double  x_tan_len;
    double  x_asix_near_rdist;
    double  y_asix_near_rdist;
    double  x_one_move_rdist;
    double  y_one_move_rdist;
    double  distance;
    int     dir;
    int     x_dir;
    int     y_dir;
    int     x_step;
    int     y_step;
	double	radian;
}               t_raycast;

double	ray_cast_distance(t_cub3d *p_data, double radian, double *rpos,
		double max_distance);

#endif
