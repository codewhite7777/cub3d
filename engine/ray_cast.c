/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongkim <dongkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 22:51:26 by dongkim           #+#    #+#             */
/*   Updated: 2022/08/06 20:24:57 by dongkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_cast.h"
#include "engine_utils.h"

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
	rc->radian = radian_correction(radian);
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

static void	set_return(t_player_data *player, t_raycast *rc, t_draw_wall *wall,
		int is_wall)
{
	if (rc->dir == 0)
	{
		if (is_wall)
			wall->wall_dir = WALL_DOOR_Y;
		else if (rc->x_dir == 1)
			wall->wall_dir = WALL_WE;
		else
			wall->wall_dir = WALL_EA;
		rc->distance = rc->y_asix_near_rdist - rc->x_one_move_rdist;
	}
	else
	{
		if (is_wall)
			wall->wall_dir = WALL_DOOR_X;
		else if (rc->y_dir == 1)
			wall->wall_dir = WALL_NO;
		else
			wall->wall_dir = WALL_SO;
		rc->distance = rc->x_asix_near_rdist - rc->y_one_move_rdist;
	}
	wall->ray_wall_dpos[0] = player->pos.x + cos(rc->radian) * rc->distance;
	wall->ray_wall_dpos[1] = player->pos.y + sin(rc->radian) * rc->distance;
	rc->radian = radian_correction(player->radian - rc->radian);
	rc->distance *= cos(rc->radian);
}

static void	set_door(t_draw_wall *wall, t_cub3d *p_data,
		t_raycast *rc, int *map_pos)
{
	double	radian;

	radian = rc->radian;
	wall->door_pos[0] = map_pos[0];
	wall->door_pos[1] = map_pos[1];
	wall->door_status = p_data->content_data.content_ptr \
						[wall->door_pos[1]][wall->door_pos[0]];
	if (rc->dir == 0)
	{
		wall->door_distance = rc->y_asix_near_rdist - rc->x_one_move_rdist;
		wall->door_dir = WALL_DOOR_Y;
	}
	else
	{
		wall->door_distance = rc->x_asix_near_rdist - rc->y_one_move_rdist;
		wall->door_dir = WALL_DOOR_X;
	}
	wall->ray_door_dpos[0]
		= p_data->player.pos.x + cos(radian) * wall->door_distance;
	wall->ray_door_dpos[1]
		= p_data->player.pos.y + sin(radian) * wall->door_distance;
	radian = radian_correction(p_data->player.radian - radian);
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
			&& content[map_pos[1]][map_pos[0]] >= TILE_DOOR_C
			&& content[map_pos[1]][map_pos[0]] <= TILE_DOOR_O)
			set_door(wall, p_data, &rc, map_pos);
	}
	set_return(player, &rc, wall,
		content[map_pos[1]][map_pos[0]] == TILE_DOOR_C);
	return (rc.distance);
}
