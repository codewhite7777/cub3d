/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_02.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alee <alee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 15:12:33 by alee              #+#    #+#             */
/*   Updated: 2022/07/22 15:12:53 by alee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UTILS_02_H
# define FT_UTILS_02_H

int		ft_isin_line(const char *line, const char *del);
int		ft_isin(char c, const char *del);
void	ft_dptr_free(char **dptr, int len);

#endif
