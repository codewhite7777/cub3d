/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_data_utils.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alee <alee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 00:37:14 by alee              #+#    #+#             */
/*   Updated: 2022/07/30 00:38:58 by alee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_DATA_UTILS_H
# define PARSE_DATA_UTILS_H

int		split_count(char ***buf);
void	split_free(char **buf);
char	*line_convert(char *line);
int		insert_rgb(int r, int g, int b);

#endif
