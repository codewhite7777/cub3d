/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongkim <dongkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 22:51:26 by dongkim           #+#    #+#             */
/*   Updated: 2022/08/01 02:24:36 by dongkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_cast.h"

static void	set_ray_dir(t_raycast *rc)
{	
	if (rc->x_asix_near_rdist < rc->y_asix_near_rdist)
	{
		rc->x_asix_near_rdist += rc->y_one_move_rdist;
		rc->dir = 1;
		rc->y_step++;
	}
	else
	{
		rc->y_asix_near_rdist += rc->x_one_move_rdist;
		rc->dir = 0;
		rc->x_step++;
	}
}

static void	init_rc(t_raycast *rc, t_player_data *player, double radian)
{
	rc->radian = radian;
	if (rc->radian < 0)
		rc->radian += PI * 2;
	if (rc->radian > PI * 2)
		rc->radian -= PI * 2;
	rc->x_len = player->pos.x - (int)player->pos.x;
	rc->y_len = player->pos.y - (int)player->pos.y;
	rc->x_step = 0;
	rc->y_step = 0;
	rc->x_dir = -1;
	rc->y_dir = -1;
	if (PI / 2 > rc->radian || rc->radian > (PI / 2) * 3)
	{
		rc->x_len = 1 - rc->x_len;
		rc->x_dir = 1;
	}
	if (rc->radian < PI)
	{
		rc->y_len = 1 - rc->y_len;
		rc->y_dir = 1;
	}
	rc->x_asix_near_rdist = 1 / sin(rc->radian) * rc->y_len * rc->y_dir;
	rc->y_asix_near_rdist = 1 / cos(rc->radian) * rc->x_len * rc->x_dir;
	rc->x_one_move_rdist = 1 / cos(rc->radian) * 1 * rc->x_dir;
	rc->y_one_move_rdist = 1 / sin(rc->radian) * 1 * rc->y_dir;
}

static void	set_rpos(t_player_data *player, t_raycast *rc, double *rpos,
		double max_distance)
{
	if (rc->dir == 0)
		rc->distance = rc->y_asix_near_rdist - rc->x_one_move_rdist;
	else
		rc->distance = rc->x_asix_near_rdist - rc->y_one_move_rdist;
	if (max_distance >= 0 && rc->distance > max_distance)
		rc->distance = max_distance;
	if (rpos)
	{
		rpos[0] = player->pos.x + cos(rc->radian) * rc->distance;
		rpos[1] = player->pos.y + sin(rc->radian) * rc->distance;
	}
}

double	ray_cast_distance(t_cub3d *p_data, double radian, double *rpos,
		double max_distance)
{
	t_raycast		rc;
	char			**content;
	t_player_data	*player;

	player = &p_data->player;
	content = p_data->content_data.content_ptr;
	init_rc(&rc, player, radian);
	while (content[(int)(player->pos.y + (rc.y_step) * rc.y_dir)] \
				[(int)(player->pos.x + (rc.x_step) * rc.x_dir)] != 1)
	{
		set_ray_dir(&rc);
	}
	set_rpos(player, &rc, rpos, max_distance);
	return (rc.distance);
}
