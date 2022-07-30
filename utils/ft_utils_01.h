/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_01.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alee <alee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 20:07:49 by alee              #+#    #+#             */
/*   Updated: 2022/07/22 15:12:51 by alee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UTILS_01_H
# define FT_UTILS_01_H
# include "../cub3d.h"

void	ft_exit(const char *msg, int exit_code);
int		split_count(char ***buf);
void	split_free(char **buf);

#endif