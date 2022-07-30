/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alee <alee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 23:09:32 by alee              #+#    #+#             */
/*   Updated: 2022/07/30 19:27:05 by alee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "libft/libft.h"
#include <mlx.h>

int	main(int argc, char *argv[])
{
	t_cub3d	data;

	ft_bzero(&data, sizeof(data));
	init_cub3d(argc, argv, &data);
	mlx_loop(data.mlx.mlx);
	return (0);
}
