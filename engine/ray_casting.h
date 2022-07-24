/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alee <alee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 00:18:26 by alee              #+#    #+#             */
/*   Updated: 2022/07/25 04:16:57 by alee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_CASTING_H
# define RAY_CASTING_H

typedef struct s_ray
{
	int			direction;
	double		distance;

	int			side;
	t_pos		map_pos;
	t_pos		step;
	t_pos		side_distance;
	t_pos		delta_distance;
}				t_ray;

void	ray_cast(t_cub3d *p_data, t_ray *o_ray, int col);
// int		is_end(t_pos *cur_pos);

#endif
