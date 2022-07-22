/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alee <alee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 19:57:00 by alee              #+#    #+#             */
/*   Updated: 2022/07/22 15:05:53 by alee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "utils/ft_utils_01.h"
#include "cub3d.h"
#include <mlx.h>

int	main(int argc, char *argv[])
{
	t_cub3d	data;

	ft_bzero(&data, sizeof(data));
	init_data(argc, argv, &data);
	mlx_loop(data.mlx.mlx);
	system("leaks cub3D");
	return (0);
}
