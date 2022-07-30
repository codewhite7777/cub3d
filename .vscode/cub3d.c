/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alee <alee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 23:13:00 by alee              #+#    #+#             */
/*   Updated: 2022/07/30 05:05:47 by alee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "ft_utils/ft_utils_01.h"
#include "parse/file_loader.h"
#include "parse/parse_data.h"
#include "parse/parse_data_debug.h"
#include "parse/content_checker.h"
#include "mlx_utils/mlx_initializer.h"
#include "mlx_utils/xpm_loader.h"
#include <stdlib.h>
#include <mlx.h>
#include "parse/content_checker_utils.h"
#include "mlx_utils/loop_hook.h"
#include "parse/set_player.h"

void	init_cub3d(int argc, char *argv[], t_cub3d *p_data)
{
	if (argc != 2)
		ft_exit("Error\nInvalid arguments", 1);
	if (file_check(argv[1]) == 0)
		ft_exit("Error\nInvalid map type", 1);
	file_info(argv[1], p_data);
	file_alloc(argv[1], p_data);
	parse_data(p_data);
#if (DEBUG == 1)
	debug_parse_data(p_data);
#endif
	content_checker(p_data);
	set_player(p_data);
	set_player_info(p_data);
#if (DEBUG == 1)
	debug_player_data(p_data);
#endif
	mlx_start(p_data);
	xpm_load(p_data);
	mlx_loop_hook(p_data->mlx.mlx, loop_main, p_data);
	return ;
}

void	close_cub3d(t_cub3d *p_data)
{
	ft_dptr_free(p_data->file_ptr, p_data->file_line);
	ft_dptr_free(p_data->content_data.content_ptr, \
					p_data->content_data.content_line);
	xpm_buf_free(ASSET_MAX, p_data);
	mlx_finish(p_data);
	exit(0);
	return ;
}
