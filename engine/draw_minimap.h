/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alee <alee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 01:21:24 by dongkim           #+#    #+#             */
/*   Updated: 2022/08/05 00:05:58 by dongkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_MINIMAP_H
# define DRAW_MINIMAP_H

# include <mlx.h>
# include "../mlx_utils/mlx_draw.h"
# include "../cub3d.h"

# define COLOR_PLAYER	0x00FF0000
# define COLOR_RAY		0x99FF7F7F
# define COLOR_BORDER	0x0000FFFF
# define COLOR_WALL		0x00000000
# define COLOR_FLOOR	0x00FFFFFF
# define COLOR_NONE		0x00AAAAAA

typedef struct s_minimap_setting
{
	unsigned int	pos[2];
	unsigned int	tile_size;
}				t_minimap_setting;

void	init_minimap(t_cub3d *p_data);
void	draw_minimap(t_cub3d *p_data);
void	draw_minimap_2(t_cub3d *p_data);

#endif
