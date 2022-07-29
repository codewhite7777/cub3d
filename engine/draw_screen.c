/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_screen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alee <alee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 23:52:35 by alee              #+#    #+#             */
/*   Updated: 2022/07/29 18:00:05 by dongkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include "ray_cast.h"
#include "../mlx_utils/mlx_draw.h"

void	draw_background(t_cub3d *p_data)
{
	int	i;
	int	j;

	i = 0;
	while (i < WIN_HEIGHT / 2)
	{
		j = 0;
		while (j < WIN_WIDTH)
		{
			mlx_pixel_to_image(&p_data->mlx.img, j, i, 0x00000000);
			j++;
		}
		i++;
	}
	while (i < WIN_HEIGHT)
	{
		j = 0;
		while (j < WIN_WIDTH)
		{
			mlx_pixel_to_image(&p_data->mlx.img, j, i, 0x33333333);
			j++;
		}
		i++;
	}
}

void	draw_screen(t_cub3d *p_data)
{
	int				i;
	double			radian;
	double			rad_per_fixel;
	double			vertical_len;
	double			rvlen;
	unsigned int	pos[2];
	double			rc;

	rad_per_fixel = ONE_TO_RAD * WIN_FOV / WIN_WIDTH;
	radian = p_data->player.radian - (ONE_TO_RAD * WIN_FOV / 2);
	vertical_len = WIN_WIDTH / tan(ONE_TO_RAD * WIN_FOV / 2);
	i = 0;
	while (i < WIN_WIDTH)
	{
		rc = ray_cast_distance(p_data, radian, 0, -1);
		rvlen = vertical_len / rc;
		pos[0] = i;
		pos[1] = WIN_HEIGHT / 2 - rvlen / 2;
		mlx_draw_vertical(&p_data->mlx.img, pos, rvlen, 0x0000FFFF);
		radian += rad_per_fixel;
		i++;
	}
}
