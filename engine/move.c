/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alee <alee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 16:29:59 by alee              #+#    #+#             */
/*   Updated: 2022/07/30 17:36:43 by alee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include "move.h"
#include <math.h>

#if (DEBUG == 1)
	#include <stdio.h>
#endif

int	move(t_cub3d *p_data)
{
	int	ret;

	ret = 0;
	if (p_data->key_w)
		move_front(p_data);
	if (p_data->key_s)
		move_back(p_data);
	if (p_data->key_a)
		move_left(p_data);
	if (p_data->key_d)
		move_right(p_data);
	return (ret);
}

void	move_front(t_cub3d *p_data)
{
	char	**map;
	double	move_speed;
	int		x;
	int		y;

	map = p_data->content_data.content_ptr;
	move_speed = p_data->player.move_speed;
	x = (int)(p_data->player.pos.x + p_data->player.dir.x * move_speed);
	y = (int)(p_data->player.pos.y);
	if (map[y][x] == 0)
		p_data->player.pos.x += p_data->player.dir.x * move_speed;
	x = (int)(p_data->player.pos.x);
	y = (int)(p_data->player.pos.y + p_data->player.dir.y * move_speed);
	if (map[y][x] == 0)
		p_data->player.pos.y += p_data->player.dir.y * move_speed;
#if (DEBUG == 1)
	printf("move front -> pos   [%lf, %lf] \n", p_data->player.pos.x, p_data->player.pos.y);
#endif
	return ;
}

void	move_back(t_cub3d *p_data)
{
	char	**map;
	double	move_speed;
	int		x;
	int		y;

	map = p_data->content_data.content_ptr;
	move_speed = p_data->player.move_speed;
	x = (int)(p_data->player.pos.x - p_data->player.dir.x * move_speed);
	y = (int)(p_data->player.pos.y);
	if (map[y][x] == 0)
		p_data->player.pos.x -= p_data->player.dir.x * move_speed;
	x = (int)(p_data->player.pos.x);
	y = (int)(p_data->player.pos.y - p_data->player.dir.y * move_speed);
	if (map[y][x] == 0)
		p_data->player.pos.y -= p_data->player.dir.y * move_speed;
#if (DEBUG == 1)
	printf("move back  -> pos   [%lf, %lf] \n", p_data->player.pos.x, p_data->player.pos.y);
#endif
	return ;
}

void	move_left(t_cub3d *p_data)
{
	double	pre_dir_x;
	double	pre_plane_x;
	double	rot_speed;

	pre_dir_x = p_data->player.dir.x;
	pre_plane_x = p_data->player.plane.x;
	rot_speed = p_data->player.rotate_speed;
	p_data->player.dir.x = p_data->player.dir.x * cos(rot_speed) - p_data->player.dir.y * sin(rot_speed);
	p_data->player.dir.y = pre_dir_x * sin(rot_speed) + p_data->player.dir.y * cos(rot_speed);
	p_data->player.plane.x = p_data->player.plane.x * cos(rot_speed) - p_data->player.plane.y * sin(rot_speed);
	p_data->player.plane.y = pre_plane_x * sin(rot_speed) + p_data->player.plane.y * cos(rot_speed);
#if (DEBUG == 1)
	printf("move left  -> pos   [%lf, %lf] \n", p_data->player.pos.x, p_data->player.pos.y);
	printf("move left  -> pos   [%lf, %lf] \n", p_data->player.dir.x, p_data->player.dir.y);
	printf("move left  -> plane [%lf, %lf] \n", p_data->player.plane.x, p_data->player.plane.y);
#endif
	return ;
}

void	move_right(t_cub3d *p_data)
{
	double	pre_dir_x;
	double	pre_plane_x;
	double	rot_speed;

	pre_dir_x = p_data->player.dir.x;
	pre_plane_x = p_data->player.plane.x;
	rot_speed = p_data->player.rotate_speed;

	p_data->player.dir.x = p_data->player.dir.x * cos(rot_speed) - p_data->player.dir.y * sin(-rot_speed);
	p_data->player.dir.y = pre_dir_x * sin(-rot_speed) + p_data->player.dir.y * cos(-rot_speed);
	p_data->player.plane.x = p_data->player.plane.x * cos(-rot_speed) - p_data->player.plane.y * sin(-rot_speed);
	p_data->player.plane.y = pre_plane_x * sin(-rot_speed) + p_data->player.plane.y * cos(-rot_speed);
#if (DEBUG == 1)
	printf("move rigtht-> pos   [%lf, %lf] \n", p_data->player.pos.x, p_data->player.pos.y);
	printf("move rigtht-> pos   [%lf, %lf] \n", p_data->player.dir.x, p_data->player.dir.y);
	printf("move rigtht-> plane [%lf, %lf] \n", p_data->player.plane.x, p_data->player.plane.y);
#endif
	return ;
}
