/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alee <alee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 19:57:00 by alee              #+#    #+#             */
/*   Updated: 2022/08/10 16:53:55 by dongkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../utils/ft_utils_01.h"
#include "cub3d.h"
#include <mlx.h>
#include "../engine/draw_minimap.h"
#include "../engine/move_player.h"
#include "../engine/draw_screen.h"
#include "../engine/door_operator.h"

static int	loop_main(t_cub3d *p_data)
{
	p_data->frame++;
	move_player(p_data, p_data->key_pressed);
	move_mouse(p_data);
	if (p_data->op_door.door_status != 0 && p_data->frame % 20 == 0)
		door_operator(p_data);
	if (p_data->update)
	{
		draw_background(p_data);
		draw_screen(p_data);
		if (p_data->minimap.sw)
			draw_minimap_2(p_data);
		mlx_put_image_to_window(p_data->mlx.mlx,
			p_data->mlx.mlx_win,
			p_data->mlx.img[p_data->mlx.img_idx].img, 0, 0);
		p_data->update = 0;
		p_data->mlx.img_idx = !p_data->mlx.img_idx;
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
