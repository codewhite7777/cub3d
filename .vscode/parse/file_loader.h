/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_loader.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alee <alee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 23:16:02 by alee              #+#    #+#             */
/*   Updated: 2022/07/29 23:17:49 by alee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_LOADER_H
# define FILE_LOADER_H

int	file_check(const char *file_name);
int	file_info(const char *file_name, t_cub3d *p_data);
int	file_alloc(const char *file_name, t_cub3d *p_data);

#endif
