/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_draw.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alee <alee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 18:45:56 by dongkim           #+#    #+#             */
/*   Updated: 2022/08/10 14:50:17 by dongkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_DRAW_H
# define MLX_DRAW_H

# include "../base/cub3d.h"

typedef struct s_drawline
{
	int	x;
	int	y;
	int	width;
	int	height;
	int	grad_less_one;
	int	grad_neg;
	int	*pos[2];
}				t_drawline;

void	mlx_pixel_to_image(t_img *img, \
		unsigned int x, unsigned int y, unsigned int color);
void	mlx_draw_square(t_img *img, unsigned int *pos, \
		unsigned int size, unsigned int color);
void	mlx_draw_line(t_img *img, unsigned int *s_pos, unsigned int *d_pos, \
		unsigned int color);
void	mlx_draw_vertical(t_img *img, unsigned int *s_pos, unsigned int size, \
		unsigned int color);
void	mlx_draw_horizon(t_img *img, unsigned int *s_pos, unsigned int size, \
		unsigned int color);
void	mlx_draw_border(t_img *img, unsigned int color);
void	mlx_draw_rectangle(t_img *img, unsigned int *s_pos, \
		unsigned int *e_pos, unsigned int color);
void	mlx_put_image_to_image(t_img *d_img, t_img *s_img, unsigned int *pos);

#endif
