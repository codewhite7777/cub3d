/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_screen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alee <alee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 23:52:35 by alee              #+#    #+#             */
/*   Updated: 2022/08/10 14:43:48 by dongkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../base/cub3d.h"
#include "ray_cast.h"
#include "../mlx_utils/mlx_draw.h"
#include "draw_screen.h"

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
		t_draw_wall *wall)
{
	t_img			*xpm;
	unsigned int	i;
	double			xpos;
	int				idx;

	idx = p_data->mlx.img_idx;
	if (wall->wall_dir == WALL_SO || wall->wall_dir == WALL_DOOR_X)
		xpos = wall->ray_wall_dpos[0] - (int)wall->ray_wall_dpos[0];
	else if (wall->wall_dir == WALL_NO)
		xpos = 1 - (wall->ray_wall_dpos[0] - (int)wall->ray_wall_dpos[0]);
	else if (wall->wall_dir == WALL_WE || wall->wall_dir == WALL_DOOR_Y)
		xpos = wall->ray_wall_dpos[1] - (int)wall->ray_wall_dpos[1];
	else if (wall->wall_dir == WALL_EA)
		xpos = 1 - (wall->ray_wall_dpos[1] - (int)wall->ray_wall_dpos[1]);
	if (wall->wall_dir == WALL_DOOR_X || wall->wall_dir == WALL_DOOR_Y)
		wall->wall_dir = WALL_DOOR;
	xpm = &p_data->xpm_data[wall->wall_dir];
	i = -1;
	while (++i < wall->vertical_len && i < WIN_HEIGHT)
	{
		mlx_pixel_to_image(&p_data->mlx.img[idx], \
			pos[0], (pos[1] >= 0) * pos[1] + i, \
			get_color_in_texture(xpm, xpos, \
			(double)(i + ((pos[1] < 0) * pos[1] * -1)) / wall->vertical_len));
	}
}

static void	draw_door_vertical(t_cub3d *p_data, int *pos,
		t_draw_wall *wall, double unit_len)
{
	t_img			*xpm;
	unsigned int	i;
	double			xpos;
	double			vertical_len;
	double			cut_len;

	vertical_len = unit_len / wall->door_distance;
	cut_len = (vertical_len / 32) * (wall->door_status - TILE_DOOR_C);
	pos[1] = WIN_HEIGHT / 2 - vertical_len / 2 + cut_len;
	if (wall->door_dir == WALL_DOOR_X)
		xpos = wall->ray_door_dpos[0] - (int)wall->ray_door_dpos[0];
	else if (wall->door_dir == WALL_DOOR_Y)
		xpos = wall->ray_door_dpos[1] - (int)wall->ray_door_dpos[1];
	wall->door_dir = WALL_DOOR;
	xpm = &p_data->xpm_data[wall->door_dir];
	i = -1;
	while (++i < vertical_len - cut_len && i < WIN_HEIGHT)
	{
		mlx_pixel_to_image(&p_data->mlx.img[p_data->mlx.img_idx], \
			pos[0], (pos[1] >= 0) * pos[1] + i, \
			get_color_in_texture(xpm, xpos, \
			(double)(i + ((pos[1] < 0) * pos[1] * -1)) / vertical_len));
	}
}

void	draw_background(t_cub3d *p_data)
{
	int	i;
	int	j;
	int	idx;

	idx = p_data->mlx.img_idx;
	i = 0;
	while (i < WIN_HEIGHT / 2)
	{
		j = 0;
		while (j < WIN_WIDTH)
			mlx_pixel_to_image(&p_data->mlx.img[idx], \
				j++, i, p_data->parse_data.c_color);
		i++;
	}
	while (i < WIN_HEIGHT)
	{
		j = 0;
		while (j < WIN_WIDTH)
			mlx_pixel_to_image(&p_data->mlx.img[idx], \
				j++, i, p_data->parse_data.f_color);
		i++;
	}
}

void	draw_screen(t_cub3d *p_data)
{
	t_radian_calc	rad;
	t_draw_wall		wall;
	double			unit_len;
	int				screen_pos[2];

	rad.rad_per_pixel = PI / 180 * WIN_FOV / WIN_WIDTH;
	rad.radian = p_data->player.radian - (PI / 180 * (WIN_FOV / 2));
	unit_len = WIN_WIDTH / (tan(PI / 180 * (WIN_FOV / 2)) * 2);
	screen_pos[0] = 0;
	while (screen_pos[0] < WIN_WIDTH)
	{
		wall.vertical_len = unit_len
			/ ray_cast_distance(p_data, rad.radian, &wall);
		screen_pos[1] = WIN_HEIGHT / 2 - wall.vertical_len / 2;
		draw_texture_vertical(p_data, screen_pos, &wall);
		if (wall.door_status > TILE_DOOR_C
			&& wall.door_status < TILE_DOOR_O)
			draw_door_vertical(p_data, screen_pos, &wall, unit_len);
		rad.radian += rad.rad_per_pixel;
		screen_pos[0]++;
	}
}
