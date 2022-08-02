/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alee <alee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 19:57:00 by alee              #+#    #+#             */
/*   Updated: 2022/08/03 06:48:32 by alee             ###   ########.fr       */
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
	move_player(p_data, p_data->key_pressed);
	if (p_data->update)
	{
	draw_background(p_data);
	draw_screen(p_data);
#if MINIMAP_VER == 2
	draw_minimap_2(p_data);
#else
	draw_minimap(p_data);
#endif
	mlx_put_image_to_window(p_data->mlx.mlx,
		p_data->mlx.mlx_win, p_data->mlx.img.img, 0, 0);
	p_data->update = 0;
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	t_cub3d	data;

	ft_bzero(&data, sizeof(data));
	init_data(argc, argv, &data);
	mlx_loop_hook(data.mlx.mlx, loop_main, &data);
	mlx_loop(data.mlx.mlx);
	return (0);
}
