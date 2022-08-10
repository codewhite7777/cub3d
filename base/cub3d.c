/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alee <alee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 20:58:15 by alee              #+#    #+#             */
/*   Updated: 2022/08/10 16:47:39 by dongkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "../utils/ft_utils_01.h"
#include "../utils/ft_utils_02.h"
#include "../parse/file_loader.h"
#include "../parse/parse_data.h"
#include "../parse/content_checker.h"
#include "../mlx_utils/mlx_initializer.h"
#include "../mlx_utils/xpm_loader.h"
#include "../utils/debug.h"
#include "../engine/draw_minimap.h"
#include <stdlib.h>
#include <stdio.h>

void	init_data(int argc, char *argv[], t_cub3d *p_data)
{
	if (argc != 2)
		ft_exit("Error\nInvalid arguments", 1);
	if (file_check(argv[1]) == 0)
		ft_exit("Error\nInvalid map type", 1);
	file_info(argv[1], p_data);
	file_alloc(argv[1], p_data);
	parse_data(p_data);
	if (ASSET_MAX > 4)
	{
		p_data->parse_data.asset_file[WALL_DOOR] = ft_strdup(XPM_DOOR_PATH);
		if (p_data->parse_data.asset_file[WALL_DOOR] == 0)
			ft_exit("Error\nMemory allocation fail(WALL_DOOR)", 1);
	}
	content_checker(p_data);
	mlx_start(p_data);
	init_minimap(p_data);
	p_data->update = 1;
	p_data->frame = 0;
	p_data->op_door.door_status = 0;
	p_data->mlx.img_idx = 0;
}

void	close_data(t_cub3d *p_data)
{
	ft_dptr_free(p_data->file_ptr, p_data->file_line);
	ft_dptr_free(p_data->content_data.content_ptr, \
					p_data->content_data.content_line);
	xpm_buf_free(ASSET_MAX, p_data);
	mlx_finish(p_data);
	exit(0);
}