/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alee <alee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 05:09:16 by alee              #+#    #+#             */
/*   Updated: 2022/07/30 20:05:26 by alee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include <math.h>
#include "ray_cast.h"

//debug
#include <stdio.h>

void	ray_casting(t_cub3d *p_data)
{
	int				i;
	int				hit;
	double			cameraX;
	t_player_data	*p;

	i = 0;
	hit = 0;
	p = &p_data->player;
	while (i < WIN_WIDTH)
	{
		cameraX = 2 * i / (double)WIN_WIDTH - 1;
		ft_set_pos(&p->ray_dir, p->dir.x + p->plane.x * cameraX, p->dir.y + p->plane.y * cameraX);
		ft_set_pos(&p->delta_dist, fabs(1 / p->ray_dir.x), fabs(1 / p->ray_dir.y));
		p_data->map_x = (int)p_data->player.pos.x;
		p_data->map_y = (int)p_data->player.pos.y;
		if (p->ray_dir.x < 0.)
		{
			p_data->step_x = -1;
			p->side_dist.x = (p->pos.x - ((int)p->pos.x) * p->delta_dist.x);
		}
		else
		{
			p_data->step_x = 1;
			p->side_dist.x = (((int)p->pos.x + 1. - p->pos.x) * p->delta_dist.x);
		}
		if (p_data->player.ray_dir.y < 0)
		{
			p_data->step_y = -1;
			p->side_dist.y = (p->pos.y - (int)p->pos.y) * p->delta_dist.y;
		}
		else
		{
			p_data->step_y = 1;
			p->side_dist.y = ((int)p->pos.y + 1. - p->pos.y) * p->delta_dist.y;
		}
		while (hit == 0)
		{
			if (p->side_dist.x < p->side_dist.y)
			{
				p->side_dist.x += p->delta_dist.x;
				p_data->map_x += p_data->step_x;
				p_data->side = 0;
			}
			else
			{
				p->side_dist.y += p->delta_dist.y;
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

void	ray_init(t_cub3d *p_data)
{
	(void)p_data;
	return ;
}
