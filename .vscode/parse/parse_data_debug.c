/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_data_debug.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alee <alee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 02:14:06 by alee              #+#    #+#             */
/*   Updated: 2022/07/30 05:39:30 by alee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../cub3d.h"

void	debug_print_dptr_toint(const char *msg, char **dptr, int ylen, int xlen)
{
	int	i;
	int	j;

	printf("%s \n", msg);
	i = 0;
	while (i < ylen)
	{
		printf("%d: ", i);
		j = 0;
		while (j < xlen)
		{
			printf("%4d ", dptr[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	printf("\n");
}

void	debug_parse_data(t_cub3d *p_data)
{
	int	idx;

	idx = 0;
	printf("no : [%s] \n", p_data->parse_data.asset_file[0]);
	printf("so : [%s] \n", p_data->parse_data.asset_file[1]);
	printf("we : [%s] \n", p_data->parse_data.asset_file[2]);
	printf("ea : [%s] \n", p_data->parse_data.asset_file[3]);
	printf("c : [0x%06x] \n", p_data->parse_data.c_color);
	printf("f : [0x%06x] \n", p_data->parse_data.f_color);
	printf("map(%d) : [%p] \n", p_data->file_line, p_data->file_ptr);
	printf("content_idx: %d, content_len: %d, content_line: %d\n", \
	p_data->content_data.content_idx, p_data->content_data.content_len, \
	p_data->content_data.content_line);
	printf("content(%d) : [%p] \n", p_data->content_data.content_line, \
	p_data->content_data.content_ptr);
	while (idx < p_data->content_data.content_line)
	{
		printf("%d: %s\n", idx, \
		p_data->file_ptr[idx + p_data->content_data.content_idx]);
		idx++;
	}
	return ;
}

void	debug_player_data(t_cub3d *p_data)
{
	printf("Player pos x, y : [%.3lf] [%.3lf] \n", p_data->player.pos.x, \
		p_data->player.pos.y);
	printf("Player dir x, y : [%.3lf] [%.3lf] \n", p_data->player.dir.x, \
		p_data->player.dir.y);
	printf("Player plane x, y : [%.3lf] [%.3lf] \n", p_data->player.plane.x, \
		p_data->player.plane.y);
	printf("Player radian : [%.3lf] \n", p_data->player.radian);
	printf("Player ray_dir x, y : [%.3lf] [%.3lf] \n", \
	p_data->player.ray_dir.x, p_data->player.ray_dir.y);
	printf("Player side_dist x, y : [%.3lf] [%.3lf] \n", \
	p_data->player.side_dist.x, p_data->player.side_dist.y);
	printf("Player delta_dist x, y : [%.3lf] [%.3lf] \n", \
	p_data->player.delta_dist.x, p_data->player.delta_dist.y);
	return ;
}
