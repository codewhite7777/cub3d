/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_operator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongkim <dongkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 18:21:32 by dongkim           #+#    #+#             */
/*   Updated: 2022/08/06 20:27:42 by dongkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "door_operator.h"
#include "ray_cast.h"

void	door_operator(t_cub3d *p_data)
{
	char	*c;

	c = &p_data->content_data.content_ptr \
		[p_data->op_door.door_pos[1]][p_data->op_door.door_pos[0]];
	*c += p_data->op_door.door_status;
	p_data->update = 1;
	if (*c == TILE_DOOR_C || *c == TILE_DOOR_O)
		p_data->op_door.door_status = 0;
}

void	set_door_operator(t_cub3d *p_data)
{
	t_draw_wall	wall;

	if (p_data->op_door.door_status == 0)
	{
		ray_cast_distance(p_data, p_data->player.radian, &wall);
		if (wall.door_status != -1 && wall.door_distance < 0.8)
		{
			p_data->op_door.door_pos[0] = wall.door_pos[0];
			p_data->op_door.door_pos[1] = wall.door_pos[1];
			if (wall.door_status == TILE_DOOR_C)
				p_data->op_door.door_status = 1;
			else
				p_data->op_door.door_status = -1;
		}
	}
}
