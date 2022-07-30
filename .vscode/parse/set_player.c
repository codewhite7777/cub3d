/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alee <alee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 04:26:28 by alee              #+#    #+#             */
/*   Updated: 2022/07/30 06:23:09 by alee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include "set_player.h"
#include "../ft_utils/ft_pos.h"

void	set_player(t_cub3d *p_data)
{
	int		i;
	int		j;
	char	*c;

	i = -1;
	while (++i < p_data->content_data.content_line)
	{
		j = -1;
		while (++j < p_data->content_data.content_len)
		{
			c = &p_data->content_data.content_ptr[i][j];
			if (*c >= ('E' - 0x30))
			{
				p_data->player.pos.y = i + 0.5;
				p_data->player.pos.x = j + 0.5;
				p_data->player.radian = trans_radian(*c + 0x30);
				*c = 0;
				return ;
			}
		}
	}
}

double	trans_radian(unsigned char direction)
{
	if (direction == 'N')
		return (PI / 2 * 3);
	if (direction == 'E')
		return (0);
	if (direction == 'W')
		return (PI);
	if (direction == 'S')
		return (PI / 2);
	else
		return (0);
}

void	set_player_info(t_cub3d *p_data)
{
	ft_set_pos(&p_data->player.dir, -1., 0.);
	ft_set_pos(&p_data->player.plane, 0., 0.66);
	ft_set_pos(&p_data->player.ray_dir, 0., 0.);
	ft_set_pos(&p_data->player.side_dist, 0., 0.);
	ft_set_pos(&p_data->player.delta_dist, 0., 0.);
	p_data->player.move_speed = 0.05;
	p_data->player.rotate_speed = 0.05;
	p_data->map_x = 0;
	p_data->map_y = 0;
	p_data->key_a = 0;
	p_data->key_w = 0;
	p_data->key_s = 0;
	p_data->key_d = 0;
	p_data->key_esc = 0;
	p_data->step_x = 0;
	p_data->step_y = 0;
	p_data->side = 0;
	return ;
}
