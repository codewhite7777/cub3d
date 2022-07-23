/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongkim <dongkim@student.42seoul.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 18:06:41 by dongkim           #+#    #+#             */
/*   Updated: 2022/07/23 20:12:43 by dongkim          ###   ########.fr       */
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
