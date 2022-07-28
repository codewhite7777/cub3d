/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongkim <dongkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 22:51:26 by dongkim           #+#    #+#             */
/*   Updated: 2022/07/29 00:48:08 by dongkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_cast.h"

static void	set_ray_dir(t_raycast *rc, double radian)
{	
	rc->dir = 0;
	if (rc->x_dir == rc->y_dir)
		rc->x_tan_len = tan(radian) * (rc->x_len + rc->x_step);
	else
		rc->x_tan_len = tan(2 * PI - radian) * (rc->x_len + rc->x_step);
	if (rc->x_tan_len < 0)
		rc->x_tan_len *= -1;
	if (rc->y_len + rc->y_step < rc->x_tan_len)
		rc->dir = 1;
}

static void	init_rc(t_raycast *rc, t_player_data *player, double *radian)
{
	if (*radian < 0)
		*radian += PI * 2;
	if (*radian > PI * 2)
		*radian -= PI * 2;
	rc->x_len = player->pos.x - (int)player->pos.x;
	rc->y_len = player->pos.y - (int)player->pos.y;
	rc->x_step = 0;
	rc->y_step = 0;
	rc->x_dir = -1;
	rc->y_dir = -1;
	if (PI / 2 > *radian || *radian > (PI / 2) * 3)
	{
		rc->x_len = 1 - rc->x_len;
		rc->x_dir = 1;
	}
	if (*radian < PI)
	{
		rc->y_len = 1 - rc->y_len;
		rc->y_dir = 1;
	}
	rc->x_asix_near_rdist = 1 / sin(*radian) * rc->y_len * rc->y_dir;
	rc->y_asix_near_rdist = 1 / cos(*radian) * rc->x_len * rc->x_dir;
	rc->x_one_move_rdist = 1 / cos(*radian) * 1 * rc->x_dir;
	rc->y_one_move_rdist = 1 / sin(*radian) * 1 * rc->y_dir;
}

static void	set_rpos(t_player_data *player, t_raycast *rc, double radian, double *rpos)
{
	rpos[0] = player->pos.x + cos(radian) * rc->distance;
	rpos[1] = player->pos.y + sin(radian) * rc->distance;
}

double	ray_cast_distance(t_cub3d *p_data, double radian, double *rpos)
{
	t_raycast		rc;
	char			**content;
	t_player_data	*player;

	player = &p_data->player;
	content = p_data->content_data.content_ptr;
	init_rc(&rc, player, &radian);
	while (content[(int)(player->pos.y + (rc.y_step) * rc.y_dir)] \
				[(int)(player->pos.x + (rc.x_step) * rc.x_dir)] != 1)
	{
		set_ray_dir(&rc, radian);
		if (rc.dir == 0)
			rc.x_step++;
		else
			rc.y_step++;
	}
	if (rc.dir == 0)
		rc.distance = rc.y_asix_near_rdist + (rc.x_one_move_rdist)
			* (rc.x_step - 1);
	else
		rc.distance = rc.x_asix_near_rdist + (rc.y_one_move_rdist)
			* (rc.y_step - 1);
	if (rpos)
		set_rpos(player, &rc, radian, rpos);
	return (rc.distance);
}
