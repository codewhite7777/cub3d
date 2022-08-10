/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_initializer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alee <alee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 12:31:18 by alee              #+#    #+#             */
/*   Updated: 2022/08/10 14:47:40 by dongkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../base/cub3d.h"
#include <mlx.h>
#include "mlx_initializer.h"
#include <stdlib.h>
#include "event_hook.h"
#include "xpm_loader.h"

static void	mlx_buffer_init(t_cub3d *p_data, t_img *img)
{
	img->img = mlx_new_image(p_data->mlx.mlx, \
								WIN_WIDTH, WIN_HEIGHT);
	img->width = WIN_WIDTH;
	img->height = WIN_HEIGHT;
	img->addr = mlx_get_data_addr(img->img,
			&img->bits_per_pixel,
			&img->line_length, &img->endian);
}

void	mlx_start(t_cub3d *p_data)
{
	p_data->mlx.mlx = mlx_init();
	p_data->mlx.mlx_win = mlx_new_window(p_data->mlx.mlx, \
								WIN_WIDTH, WIN_HEIGHT, "cub3D");
	mlx_buffer_init(p_data, &p_data->mlx.img[0]);
	mlx_buffer_init(p_data, &p_data->mlx.img[1]);
	mlx_hook(p_data->mlx.mlx_win, event_key_press, 0, \
							key_event, (void *)p_data);
	mlx_hook(p_data->mlx.mlx_win, event_key_release, 0, \
							key_release_event, (void *)p_data);
	mlx_hook(p_data->mlx.mlx_win, event_window_destroy, 0, \
							exit_event, (void *)p_data);
	xpm_load(p_data);
	mlx_mouse_hide();
	mlx_mouse_move(p_data->mlx.mlx_win, WIN_WIDTH / 2, 0);
}

void	mlx_finish(t_cub3d *p_data)
{
	mlx_destroy_image(p_data->mlx.mlx, p_data->mlx.img[0].img);
	mlx_destroy_image(p_data->mlx.mlx, p_data->mlx.img[1].img);
	mlx_destroy_image(p_data->mlx.mlx, p_data->minimap.img.img);
	mlx_destroy_window(p_data->mlx.mlx, p_data->mlx.mlx_win);
	return ;
}
