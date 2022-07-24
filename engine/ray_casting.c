/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alee <alee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 00:18:42 by alee              #+#    #+#             */
/*   Updated: 2022/07/25 04:41:19 by alee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include "ray_casting.h"

//debug
#include <mlx.h>
#include <stdio.h>

void	ray_cast(t_cub3d *p_data, t_ray *o_ray, int col)
{
	int	is_hit;
	int	next_side;

	is_hit = 0;
	while (is_hit == 0)
	{
		next_side = (o_ray->side_distance.x < o_ray->side_distance.y);
		if (next_side)
		{
			o_ray->side_distance.x += o_ray->delta_distance.x;
			o_ray->map_pos.x += o_ray->step.x;
		}
		else
		{
			o_ray->side_distance.y += o_ray->delta_distance.y;
			o_ray->map_pos.y += o_ray->step.y;
		}
		o_ray->side = !next_side;
		//맵의 끝이라면 is_hit를 1값으로 변경
		// if (is_end(&o_ray->map_pos, ))
		// {
			//map_pos.x,y에서 좌표값 빼야함
			// is_hit = 1;
		// }
		//벽을 만났다면 is_hit를 1값으로 변경
		// if (is_type(o_ray->map_pos, ) == '1')
			// is_hit = 1;

		//임시로 is_hit값 변경
		is_hit = 1;
	}
	//방향 설정 : TODO ray_to direction();
	// o_ray->direction = ray_to_direction();

	//거리 설정 : TODO ray_to_distance();
	// o_ray->distance = ray_to_distance();
	(void)p_data;
	(void)col;
	return ;
}
