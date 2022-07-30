/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_data.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alee <alee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 23:30:42 by alee              #+#    #+#             */
/*   Updated: 2022/07/30 01:59:19 by alee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_DATA_H
# define PARSE_DATA_H
# include "../cub3d.h"
# include "../assets/assets.h"

typedef struct s_cub3d	t_cub3d;

int		parse_data(t_cub3d *p_data);
t_parse	parse_line(char *line, t_cub3d *p_data);
int		parse_asset(char *line, t_asset type, t_parse ret, t_cub3d *p_data);
int		parse_rgb(char *line, const char *type, t_parse ret, t_cub3d *p_data);

#endif
