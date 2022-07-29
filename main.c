/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alee <alee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 19:57:00 by alee              #+#    #+#             */
/*   Updated: 2022/07/29 21:17:40 by dongkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "utils/ft_utils_01.h"
#include "cub3d.h"
#include <mlx.h>

//debug
#include<stdio.h>
#include "engine/draw_minimap.h"
#include "engine/move_player.h"
#include "engine/draw_screen.h"

static int	loop_main(t_cub3d *p_data)
{
	t_minimap_setting	minimap_settings;

	move_player(p_data, p_data->key_pressed);
	draw_background(p_data);
	draw_screen(p_data);
	minimap_settings.pos[0] = 100;
	minimap_settings.pos[1] = 10;
	minimap_settings.size.width = 6;
	minimap_settings.size.height = 4;
	minimap_settings.tile_size = 20;
	draw_minimap_2(p_data, &minimap_settings);
	mlx_put_image_to_window(p_data->mlx.mlx,
		p_data->mlx.mlx_win, p_data->mlx.img.img, 0, 0);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_cub3d	data;

	ft_bzero(&data, sizeof(data));
	init_data(argc, argv, &data);
	mlx_loop_hook(data.mlx.mlx, loop_main, &data);
	mlx_loop(data.mlx.mlx);
	//system("leaks cub3D");
	return (0);
}
