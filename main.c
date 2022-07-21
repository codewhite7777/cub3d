/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alee <alee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 19:57:00 by alee              #+#    #+#             */
/*   Updated: 2022/07/21 13:49:14 by alee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "utils/ft_utils_01.h"
#include "cub3d.h"

//debug
#include <stdlib.h>
#include <stdio.h>
#include "parse/parse_data.h"

int	main(int argc, char *argv[])
{
	t_cub3d	data;

	ft_bzero(&data, sizeof(data));
	init_data(argc, argv, &data);
	system("leaks cub3D");

	return (0);
}
