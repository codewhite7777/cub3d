/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongkim <dongkim@student.42seoul.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 18:06:41 by dongkim           #+#    #+#             */
/*   Updated: 2022/08/04 23:50:42 by dongkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_draw.h"
#include "../utils/ft_utils_02.h"

void	mlx_pixel_to_image(t_img *img, unsigned int x, unsigned int y,
		unsigned int color)
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

static void	mlx_draw_line_sub(t_img *img, t_drawline *dl,
	int idx, unsigned int color)
{
	while (dl->grad_less_one == 1 && dl->x != dl->pos[1][0])
	{
		mlx_pixel_to_image(img, dl->x, dl->y, color);
		dl->x++;
		if (0 <= (dl->height * (dl->x - dl->pos[0][0])
			- dl->width * (dl->y + idx - dl->pos[0][1])) * idx)
			dl->y += idx;
	}
	while (dl->grad_less_one == 0 && dl->y != dl->pos[1][1])
	{
		mlx_pixel_to_image(img, dl->x, dl->y, color);
		dl->y += idx;
		if (0 >= (dl->height * (dl->x + 1 - dl->pos[0][0])
			- dl->width * (dl->y - dl->pos[0][1])) * idx)
			dl->x++;
	}
}

void	mlx_draw_line(t_img *img,
		unsigned int *s_pos, unsigned int *d_pos, unsigned int color)
{
	t_drawline	dl;

	dl.pos[0] = (int *)s_pos;
	dl.pos[1] = (int *)d_pos;
	if (s_pos[0] > d_pos[0])
	{
		dl.pos[0] = (int *)d_pos;
		dl.pos[1] = (int *)s_pos;
	}
	dl.x = dl.pos[0][0];
	dl.y = dl.pos[0][1];
	dl.width = dl.pos[1][0] - dl.pos[0][0];
	dl.height = dl.pos[1][1] - dl.pos[0][1];
	dl.grad_less_one = ft_abs(dl.height) < ft_abs(dl.width);
	dl.grad_neg = dl.pos[0][1] > dl.pos[1][1];
	if (dl.grad_neg == 0)
		mlx_draw_line_sub(img, &dl, 1, color);
	else
		mlx_draw_line_sub(img, &dl, -1, color);
}
