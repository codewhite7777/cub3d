/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_loader.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alee <alee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 20:38:46 by alee              #+#    #+#             */
/*   Updated: 2022/07/20 22:34:11 by alee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_LOADER_H
# define FILE_LOADER_H
# include "../cub3d.h"

int	file_check(const char *file_name);
int	file_info(const char *file_name, t_cub3d *p_data);
int	file_alloc(const char *file_name, t_cub3d *p_data);

#endif
