/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   content_checker_utils.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alee <alee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 03:52:13 by alee              #+#    #+#             */
/*   Updated: 2022/07/30 04:28:32 by alee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTENT_CHECKER_UTILS_H
# define CONTENT_CHECKER_UTILS_H
# include "../cub3d.h"

char	**content_malloc(t_cub3d *p_data, char setval);
void	dfs_content_check(t_cub3d *p_data, char **visit_ptr, int y, int x);

#endif
