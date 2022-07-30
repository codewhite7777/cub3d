/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alee <alee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 04:20:59 by alee              #+#    #+#             */
/*   Updated: 2022/07/30 17:32:47 by alee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include <mlx.h>
#include "../engine/calculate.h"
#include "../engine/draw.h"
#include "../engine/move.h"

int	loop_main(t_cub3d *p_data)
{
	calculate(p_data);
	move(p_data);
	draw_screen(p_data);
	return (0);
}
