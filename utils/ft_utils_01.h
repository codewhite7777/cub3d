/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_01.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alee <alee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 20:07:49 by alee              #+#    #+#             */
/*   Updated: 2022/07/21 02:21:13 by alee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UTILS_01_H
# define FT_UTILS_01_H
# include "../cub3d.h"

void	ft_exit(const char *msg, int exit_code);
void	ft_map_free(t_cub3d *p_data, int idx);
int		split_count(char ***buf);
void	split_free(char **buf);

#endif
