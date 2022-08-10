/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_data.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alee <alee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 00:07:07 by alee              #+#    #+#             */
/*   Updated: 2022/08/10 14:51:07 by dongkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_DATA_H
# define PARSE_DATA_H

# include "../base/cub3d.h"

int		parse_data(t_cub3d *p_data);
t_parse	parse_line(char *line, t_cub3d *p_data);
int		parse_asset(char *line, t_asset type, t_parse ret, t_cub3d *p_data);
int		parse_rgb(char *line, const char *type, t_parse ret, t_cub3d *p_data);

#endif
