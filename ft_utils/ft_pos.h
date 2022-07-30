/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pos.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alee <alee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 06:13:42 by alee              #+#    #+#             */
/*   Updated: 2022/07/30 06:16:19 by alee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_POS_H
# define FT_POS_H

typedef struct s_pos
{
	double	x;
	double	y;
}				t_pos;

void	ft_set_pos(t_pos *p_pos, double x, double y);

#endif
