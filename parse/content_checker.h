/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   content_checker.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alee <alee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 02:16:31 by alee              #+#    #+#             */
/*   Updated: 2022/07/30 04:14:25 by alee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTENT_CHECKER_H
# define CONTENT_CHECKER_H
# include "../cub3d.h"

void	content_checker(t_cub3d *p_data);
int		set_content_data(t_cub3d *p_data);
void	set_content(t_cub3d *p_data);
void	content_map_check(t_cub3d *p_data);

#endif
