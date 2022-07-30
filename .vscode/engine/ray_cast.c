/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alee <alee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 05:09:16 by alee              #+#    #+#             */
/*   Updated: 2022/07/30 17:29:04 by alee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include <math.h>

//debug
#include <stdio.h>

void	ray_casting(t_cub3d *p_data)
{
	int		i;
	int		hit;
	double	cameraX;

	i = 0;
	hit = 0;
	while (i < WIN_WIDTH)
	{
		cameraX = 2 * i / (double)WIN_WIDTH - 1;
		p_data->player.ray_dir.x = p_data->player.dir.x + p_data->player.plane.x * cameraX;
		p_data->player.ray_dir.y = p_data->player.dir.y + p_data->player.plane.y * cameraX;
		p_data->player.delta_dist.x = fabs(1 / p_data->player.ray_dir.x);
		p_data->player.delta_dist.y = fabs(1 / p_data->player.ray_dir.y);
		p_data->map_x = (int)p_data->player.pos.x;
		p_data->map_y = (int)p_data->player.pos.y;
		if (p_data->player.ray_dir.x < 0.)
		{
			p_data->step_x = -1;
			p_data->player.side_dist.x = (p_data->player.pos.x - ((int)p_data->player.pos.x) * p_data->player.delta_dist.x);
		}
		else
		{
			p_data->step_x = 1;
			p_data->player.side_dist.x = (((int)p_data->player.pos.x + 1. - p_data->player.pos.x) * p_data->player.delta_dist.x);
		}
		if (p_data->player.ray_dir.y < 0)
		{
			p_data->step_y = -1;
			p_data->player.side_dist.y = (p_data->player.pos.y - (int)p_data->player.pos.y) * p_data->player.delta_dist.y;
		}
		else
		{
			p_data->step_y = 1;
			p_data->player.side_dist.y = ((int)p_data->player.pos.y + 1. - p_data->player.pos.y) * p_data->player.delta_dist.y;
		}
		while (hit == 0)
		{
			if (p_data->player.side_dist.x < p_data->player.side_dist.y)
			{
				p_data->player.side_dist.x += p_data->player.delta_dist.x;
				p_data->map_x += p_data->step_x;
				p_data->side = 0;
			}
			else
			{
				p_data->player.side_dist.y += p_data->player.delta_dist.y;
				p_data->map_y += p_data->step_y;
				p_data->side = 1;
			}
			if (p_data->content_data.content_ptr[p_data->map_y][p_data->map_x] == 1)
				hit = 1;
		}
		
		i++;
	}
	return ;
}
