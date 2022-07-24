/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_draw.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alee <alee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 18:45:56 by dongkim           #+#    #+#             */
/*   Updated: 2022/07/25 04:22:30 by alee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_DRAW_H
# define MLX_DRAW_H

# include "../cub3d.h"

void	mlx_pixel_to_image(t_img *img, \
		unsigned int x, unsigned int y, unsigned int color);
void	mlx_draw_square(t_img *img, unsigned int *pos, \
		unsigned int size, unsigned int color);

#endif
