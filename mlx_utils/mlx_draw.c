/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongkim <dongkim@student.42seoul.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 18:06:41 by dongkim           #+#    #+#             */
/*   Updated: 2022/07/25 23:44:04 by dongkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_draw.h"

void	mlx_pixel_to_image(t_img *img,
		unsigned int x, unsigned int y, unsigned int color)
{
	char			*dst;
	unsigned int	bitmask;

	if (x < img->width && y < img->height)
	{
		bitmask = 0xFFFFFFFF >> (32 - img->bits_per_pixel);
		dst = img->addr
			+ (y * img->line_length + x * (img->bits_per_pixel / 8));
		*(unsigned int *)dst = color & bitmask;
	}
}

void	mlx_draw_square(t_img *img, unsigned int *pos,
		unsigned int size, unsigned int color)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			mlx_pixel_to_image(img, pos[0] + j, pos[1] + i, color);
			j++;
		}
		i++;
	}
}

#include <stdio.h>
void	mlx_draw_line(t_img *img,
		unsigned int *s_pos, unsigned int *d_pos, unsigned int color)
{
	int	x;
	int	y;
	int	x_diff;
	int	y_diff;

	// TODO
	x = s_pos[0];
	y = s_pos[1];
	x_diff = d_pos[0] - s_pos[0];
	y_diff = d_pos[1] - s_pos[1];

	if (x_diff > y_diff)
	{
		while (x <= (int)d_pos[0])
		{
			mlx_pixel_to_image(img, x, y, color);
			x++;
			if (0 <= (y_diff * (x - (int)s_pos[0]) - x_diff * ((y + 1) - (int)s_pos[1])))
				y++;
		}
	}
	else
	{
		while (y <= (int)d_pos[1])
		{
			mlx_pixel_to_image(img, x, y, color);
			y++;
			if (0 >= (y_diff * (x + 1 - (int)s_pos[0]) - x_diff * (y - (int)s_pos[1])))
				x++;
		}

	}
}
