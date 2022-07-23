/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongkim <dongkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 01:21:24 by dongkim           #+#    #+#             */
/*   Updated: 2022/07/24 01:21:25 by dongkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_MINIMAP_H
# define DRAW_MINIMAP_H

# include <mlx.h>
# include "../mlx_utils/mlx_draw.h"
# include "../cub3d.h"

typedef struct s_minimap
{
	unsigned int width;
	unsigned int height;
}				t_minimap;

void	draw_minimap(t_cub3d *p_data, unsigned int x, unsigned int y,
		unsigned int tile_size);

#endif
