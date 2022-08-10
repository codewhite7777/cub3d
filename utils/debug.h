/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alee <alee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 14:44:28 by alee              #+#    #+#             */
/*   Updated: 2022/08/10 14:51:16 by dongkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUG_H
# define DEBUG_H

# include "../base/cub3d.h"

void	debug_print_dptr_toint(const char *msg, char **dptr, \
								int ylen, int xlen);
void	debug_parse_data(t_cub3d *p_data);

#endif
