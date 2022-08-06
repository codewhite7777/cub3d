/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongkim <dongkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 17:48:15 by dongkim           #+#    #+#             */
/*   Updated: 2022/08/06 17:48:16 by dongkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine_utils.h"

double	radian_correction(double radian)
{
	while (radian < 0)
		radian += 2 * PI;
	while (radian > 2 * PI)
		radian -= 2 * PI;
	return (radian);
}
