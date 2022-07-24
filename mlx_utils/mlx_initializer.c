/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_initializer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alee <alee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 12:31:18 by alee              #+#    #+#             */
/*   Updated: 2022/07/25 04:23:07 by alee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include <mlx.h>
#include "mlx_initializer.h"
#include <stdlib.h>
#include "event_hook.h"
#include "xpm_loader.h"

void	mlx_start(t_cub3d *p_data)
{
	p_data->mlx.mlx = mlx_init();
	p_data->mlx.mlx_win = mlx_new_window(p_data->mlx.mlx, \
								WIN_WIDTH, WIN_HEIGHT, "cub3D");
	p_data->mlx.img.img = mlx_new_image(p_data->mlx.mlx, \
								WIN_WIDTH, WIN_HEIGHT);
	p_data->mlx.img.width = WIN_WIDTH;
	p_data->mlx.img.height = WIN_HEIGHT;
	p_data->mlx.img.addr = mlx_get_data_addr(p_data->mlx.img.img,
			&p_data->mlx.img.bits_per_pixel,
			&p_data->mlx.img.line_length, &p_data->mlx.img.endian);
	mlx_hook(p_data->mlx.mlx_win, event_key_press, 0, \
							key_event, (void *)p_data);
	mlx_hook(p_data->mlx.mlx_win, event_key_release, 0, \
							key_release_event, (void *)p_data);
	mlx_hook(p_data->mlx.mlx_win, event_window_destroy, 0, \
							exit_event, (void *)p_data);
	xpm_load(p_data);
	return ;
}

void	mlx_finish(t_cub3d *p_data)
{
	mlx_destroy_image(p_data->mlx.mlx, p_data->mlx.img.img);
	mlx_destroy_window(p_data->mlx.mlx, p_data->mlx.mlx_win);
	return ;
}
