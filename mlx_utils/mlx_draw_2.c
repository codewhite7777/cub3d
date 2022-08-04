/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_draw_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongkim <dongkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 15:54:31 by dongkim           #+#    #+#             */
/*   Updated: 2022/08/05 00:16:50 by dongkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_draw.h"

void	mlx_draw_rectangle(t_img *img, unsigned int *s_pos,
		unsigned int *e_pos, unsigned int color)
{
	unsigned int	x;
	unsigned int	y;

	y = s_pos[1];
	while (y < e_pos[1])
	{
		x = s_pos[0];
		while (x < e_pos[0])
		{
			mlx_pixel_to_image(img, x, y, color);
			x++;
		}
		y++;
	}
}

void	mlx_put_image_to_image(t_img *d_img, t_img *s_img,
		unsigned int *pos)
{
	unsigned int	x;
	unsigned int	y;
	char			*dst;
	char			*src;

	y = 0;
	while (y < s_img->height)
	{
		x = 0;
		while (x < s_img->width)
		{
			if (x + pos[0] < d_img->width && y + pos[1] < d_img->height)
			{
				src = s_img->addr + y * s_img->line_length
					+ x * (s_img->bits_per_pixel / 8);
				dst = d_img->addr + (y + pos[1]) * d_img->line_length
					+ (x + pos[0]) * (d_img->bits_per_pixel / 8);
				*(unsigned int *)dst = *(unsigned int *)src;
			}
			x++;
		}
		y++;
	}
}

void	mlx_draw_vertical(t_img *img, unsigned int *s_pos, unsigned int size,
        unsigned int color)
{
	unsigned int	y;

	y = 0;
	while (y < size)
	{
		mlx_pixel_to_image(img, s_pos[0], s_pos[1] + y, color);
		y++;
	}
}

void	mlx_draw_horizon(t_img *img, unsigned int *s_pos, unsigned int size,
		unsigned int color)
{
	unsigned int	x;

	x = 0;
	while (x < size)
	{
		mlx_pixel_to_image(img, s_pos[0] + x, s_pos[1], color);
		x++;
	}
}

void	mlx_draw_border(t_img *img,	unsigned int color)
{
	unsigned int	pos[2];

	pos[0] = 0;
	pos[1] = 0;
	mlx_draw_horizon(img, pos, img->width, color);
	mlx_draw_vertical(img, pos, img->height, color);
	pos[1] = img->height - 1;
	mlx_draw_horizon(img, pos, img->width, color);
	pos[0] = img->width - 1;
	pos[1] = 0;
	mlx_draw_vertical(img, pos, img->height, color);
}
