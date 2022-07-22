/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alee <alee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 14:44:09 by alee              #+#    #+#             */
/*   Updated: 2022/07/22 15:16:25 by alee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h"
#include <stdio.h>
#include "../cub3d.h"

void	debug_print_dptr_toint(const char *msg, char **dptr, int ylen, int xlen)
{
	int	i;
	int	j;

	printf("%s\n", msg);
	i = 0;
	while (i < ylen)
	{
		printf("%d: ", i);
		j = 0;
		while (j < xlen)
		{
			printf("%4d ", dptr[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	printf("\n");
}

void	debug_parse_data(t_cub3d *p_data)
{
	int	idx;

	idx = 0;
	printf("no : [%s] \n", p_data->parse_data.asset_file[0]);
	printf("so : [%s] \n", p_data->parse_data.asset_file[1]);
	printf("we : [%s] \n", p_data->parse_data.asset_file[2]);
	printf("ea : [%s] \n", p_data->parse_data.asset_file[3]);
	printf("c : [0x%06x] \n", p_data->parse_data.c_color);
	printf("f : [0x%06x] \n", p_data->parse_data.f_color);
	printf("map(%d) : [%p] \n", p_data->file_line, p_data->file_ptr);
	printf("content_idx: %d, content_len: %d, content_line: %d\n", \
	p_data->content_data.content_idx, p_data->content_data.content_len, \
	p_data->content_data.content_line);
	printf("content(%d) : [%p] \n", p_data->content_data.content_line, \
	p_data->content_data.content_ptr);
	while (idx < p_data->content_data.content_line)
	{
		printf("%d: %s\n", idx, \
		p_data->file_ptr[idx + p_data->content_data.content_idx]);
		idx++;
	}
	return ;
}
