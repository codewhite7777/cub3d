/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpm_loader.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alee <alee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 13:42:22 by alee              #+#    #+#             */
/*   Updated: 2022/07/30 03:32:50 by alee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef XPM_LOADER_H
# define XPM_LOADER_H
# include "../cub3d.h"

typedef struct s_xpm
{
	void	*img;
	int		width;
	int		height;
}				t_xpm;

int		xpm_load(t_cub3d *p_data);
void	xpm_buf_free(int index, t_cub3d *p_data);

#endif
