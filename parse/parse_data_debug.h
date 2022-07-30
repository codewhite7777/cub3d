/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_data_debug.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alee <alee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 02:13:06 by alee              #+#    #+#             */
/*   Updated: 2022/07/30 05:06:56 by alee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_DATA_DEBUG_H
# define PARSE_DATA_DEBUG_H
# include "../cub3d.h"

void	debug_print_dptr_toint(const char *msg, char **dptr, \
								int ylen, int xlen);
void	debug_parse_data(t_cub3d *p_data);
void	debug_player_data(t_cub3d *p_data);

#endif
