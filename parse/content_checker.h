/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   content_checker.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alee <alee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 14:41:27 by dongkim           #+#    #+#             */
/*   Updated: 2022/07/24 06:22:08 by dongkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTENT_CHECKER_H
# define CONTENT_CHECKER_H

# include "../cub3d.h"
# include "../libft/libft.h"
# include "../utils/ft_utils_01.h"
# include "../utils/ft_utils_02.h"
# include "../utils/debug.h"

void	content_checker(t_cub3d *p_data);
void	dfs_content_check(t_cub3d *p_data, char **visit_ptr, int y, int x);
char	**content_malloc(t_cub3d *p_data, char setval);
double	trans_radian(unsigned char direction);

#endif
