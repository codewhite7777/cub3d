/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alee <alee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 20:58:15 by alee              #+#    #+#             */
/*   Updated: 2022/07/21 13:48:22 by alee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "utils/ft_utils_01.h"
#include "parse/file_loader.h"
#include "parse/parse_data.h"
#include "parse/content_checker.h"


//debug
#include <stdio.h>

void	init_data(int argc, char* argv[], t_cub3d *p_data)
{
	if (argc != 2)
		ft_exit("Error\nInvalid arguments", 1);
	if (file_check(argv[1]) == 0)
		ft_exit("Error\nInvalid map type", 1);
	file_info(argv[1], p_data);
	file_alloc(argv[1], p_data);
	parse_data(p_data);
	printf("no : [%s] \n", p_data->parse_data.asset_file[0]);
	printf("so : [%s] \n", p_data->parse_data.asset_file[1]);
	printf("we : [%s] \n", p_data->parse_data.asset_file[2]);
	printf("ea : [%s] \n", p_data->parse_data.asset_file[3]);
	printf("c : [0x%06x] \n", p_data->parse_data.c_color);
	printf("f : [0x%06x] \n", p_data->parse_data.f_color);

	printf("map(%d) : [%p] \n", p_data->map_line, p_data->map_ptr);
	content_checker(p_data);

	printf("content_idx: %d, content_len: %d, content_line: %d\n", p_data->content_data.content_idx, p_data->content_data.content_len, p_data->content_data.content_line);

	printf("content(%d) : [%p] \n", p_data->content_data.content_line, p_data->content_data.content_ptr);
	for(int i = 0; i < p_data->content_data.content_line; i++) {
		printf("%d: %s\n", i, p_data->map_ptr[i + p_data->content_data.content_idx]);
	}
	return ;
}
