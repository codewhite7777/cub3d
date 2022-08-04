/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_screen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alee <alee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 23:52:35 by alee              #+#    #+#             */
/*   Updated: 2022/08/04 09:46:53 by dongkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include "ray_cast.h"
#include "../mlx_utils/mlx_draw.h"

static unsigned int	get_color_in_texture(t_img *wall, double x, double y)
{
	unsigned int	color;
	char			*dst;

	dst = wall->addr + (wall->line_length * (unsigned int)(wall->height * y)
		+ (wall->bits_per_pixel / 8) * (unsigned int)(wall->width * x));
	color = *(unsigned int *)dst;
	return (color);
}

static void	draw_texture_vertical(t_cub3d *p_data, int *pos,
		double *rpos, unsigned int size, int wall_dir)
{
	t_img			*wall;
	unsigned int	i;
	double			xpos;

	if (wall_dir == WALL_SO)
		xpos = rpos[0] - (int)rpos[0];
	else if (wall_dir == WALL_NO)
		xpos = 1 - (rpos[0] - (int)rpos[0]);
	else if (wall_dir == WALL_WE)
		xpos = rpos[1] - (int)rpos[1];
	else if (wall_dir == WALL_EA)
		xpos = 1 - (rpos[1] - (int)rpos[1]);
	wall = &p_data->xpm_data[wall_dir];
	i = 0;
	while (i < size && i < WIN_HEIGHT)
	{
		mlx_pixel_to_image(&p_data->mlx.img, pos[0], (pos[1] >= 0) * pos[1] + i,
			get_color_in_texture(wall, xpos,
			(double)(i + ((pos[1] < 0) * pos[1] * -1)) / size));
		i++;
	}
}


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
			mlx_pixel_to_image(&p_data->mlx.img, j, i, p_data->parse_data.c_color);
			j++;
		}
		i++;
	}
	while (i < WIN_HEIGHT)
	{
		j = 0;
		while (j < WIN_WIDTH)
		{
			mlx_pixel_to_image(&p_data->mlx.img, j, i, p_data->parse_data.f_color);
			j++;
		}
		i++;
	}
}

void	draw_screen(t_cub3d *p_data)
{
	double	radian;
	double	rad_per_pixel;
	double	vertical_len[2];
	int		wall_dir;
	int		pos[2];
	double	rpos[2];

	rad_per_pixel = PI / 180 * WIN_FOV / WIN_WIDTH;
	radian = p_data->player.radian - (PI / 180 * (WIN_FOV / 2));
	vertical_len[0] = WIN_WIDTH / (tan(PI / 180 * (WIN_FOV / 2)) * 2);
	pos[0] = 0;
	while (pos[0] < WIN_WIDTH)
	{
		vertical_len[1] = vertical_len[0]
			/ ray_cast_distance(p_data, radian, rpos, &wall_dir);
		pos[1] = WIN_HEIGHT / 2 - vertical_len[1] / 2;
		draw_texture_vertical(p_data, pos,
			rpos, vertical_len[1], wall_dir);
		radian += rad_per_pixel;
		pos[0]++;
	}
}
