/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongkim <dongkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 22:51:26 by dongkim           #+#    #+#             */
/*   Updated: 2022/08/06 06:45:20 by dongkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_cast.h"

static void	set_ray_dir(t_raycast *rc, int *map_pos)
{	
	if (rc->x_asix_near_rdist < rc->y_asix_near_rdist)
	{
		rc->x_asix_near_rdist += rc->y_one_move_rdist;
		rc->dir = 1;
		map_pos[1] += rc->y_dir;
	}
	else
	{
		rc->y_asix_near_rdist += rc->x_one_move_rdist;
		rc->dir = 0;
		map_pos[0] += rc->x_dir;
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

static void	set_rpos(t_player_data *player, t_raycast *rc, double *rpos)
{
	if (rc->dir == 0)
		rc->distance = rc->y_asix_near_rdist - rc->x_one_move_rdist;
	else
		rc->distance = rc->x_asix_near_rdist - rc->y_one_move_rdist;
	if (rpos)
	{
		rpos[0] = player->pos.x + cos(rc->radian) * rc->distance;
		rpos[1] = player->pos.y + sin(rc->radian) * rc->distance;
	}
	rc->radian = player->radian - rc->radian;
	if (rc->radian < 0)
		rc->radian += 2 * PI;
	if (rc->radian > 2 * PI)
		rc->radian -= 2 * PI;
	rc->distance *= cos(rc->radian);
}

static void	set_wall_type(t_raycast *rc, int *wall_type, int is_door)
{
	if (rc->dir == 1)
	{
		if (is_door)
			*wall_type = WALL_DOOR_X;
		else if (rc->y_dir == 1)
			*wall_type = WALL_NO;
		else
			*wall_type = WALL_SO;
	}
	else
	{
		if (is_door)
			*wall_type = WALL_DOOR_Y;
		else if (rc->x_dir == 1)
			*wall_type = WALL_WE;
		else
			*wall_type = WALL_EA;
	}
}

static void set_door(t_draw_wall *wall, t_player_data *player,
		t_raycast *rc, char door_status)
{
	double	radian;

	radian = rc->radian;
	wall->door_status = door_status;
	if (rc->dir == 0)
	{
		wall->door_distance = rc->y_asix_near_rdist - rc->x_one_move_rdist;
		wall->door_type = WALL_DOOR_Y;
	}
	else
	{
		wall->door_distance = rc->x_asix_near_rdist - rc->y_one_move_rdist;
		wall->door_type = WALL_DOOR_X;
	}
	wall->ray_door_dpos[0]
		= player->pos.x + cos(radian) * wall->door_distance;
	wall->ray_door_dpos[1]
		= player->pos.y + sin(radian) * wall->door_distance;
	radian = player->radian - radian;
	if (radian < 0)
		radian += 2 * PI;
	if (radian > 2 * PI)
		radian -= 2 * PI;
	wall->door_distance *= cos(radian);
}

double	ray_cast_distance(t_cub3d *p_data, double radian, t_draw_wall *wall)
{
	t_raycast		rc;
	char			**content;
	t_player_data	*player;
	int				map_pos[2];

	player = &p_data->player;
	content = p_data->content_data.content_ptr;
	init_rc(&rc, player, radian);
	map_pos[0] = (int)player->pos.x;
	map_pos[1] = (int)player->pos.y;
	wall->door_status = -1;
	while (content[map_pos[1]][map_pos[0]] != TILE_WALL
			&& content[map_pos[1]][map_pos[0]] != TILE_DOOR_C)
	{
		set_ray_dir(&rc, map_pos);
		if (wall->door_status == -1
			&& content[map_pos[1]][map_pos[0]] > TILE_DOOR_C
			&& content[map_pos[1]][map_pos[0]] < TILE_DOOR_O)
			set_door(wall, player, &rc, content[map_pos[1]][map_pos[0]]);
	}
	set_rpos(player, &rc, wall->ray_wall_dpos);
	set_wall_type(&rc, &wall->wall_dir,
		content[map_pos[1]][map_pos[0]] == TILE_DOOR_C);
	return (rc.distance);
}
