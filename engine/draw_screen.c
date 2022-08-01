/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_screen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alee <alee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 23:52:35 by alee              #+#    #+#             */
/*   Updated: 2022/08/02 04:24:14 by dongkim          ###   ########.fr       */
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
	double	radian;
	double	rad_per_fixel;
	double	vertical_len;
	double	rvlen;
	int		pos[2];

	rad_per_fixel = PI / 180 * WIN_FOV / WIN_WIDTH;
	radian = p_data->player.radian - (ONE_TO_RAD * (WIN_FOV / 2));
	vertical_len = WIN_WIDTH / (tan(ONE_TO_RAD * (WIN_FOV / 2)) * 2);
	pos[0] = 0;
	while (pos[0] < WIN_WIDTH)
	{
		rvlen = vertical_len / ray_cast_distance(p_data, radian, 0, -1);
		if (rvlen < 0 || rvlen >= WIN_HEIGHT)
			rvlen = WIN_HEIGHT;
		pos[1] = WIN_HEIGHT / 2 - rvlen / 2;
		mlx_draw_vertical(&p_data->mlx.img,
			(unsigned int *)pos, rvlen, 0x0000FFFF);
		radian += rad_per_fixel;
		pos[0]++;
	}
}
