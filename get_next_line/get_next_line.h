/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alee <alee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 00:05:39 by alee              #+#    #+#             */
/*   Updated: 2022/07/20 20:06:32 by alee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stddef.h>
# define BUFFER_SIZE 1024

int		get_next_line(int fd, char **line);
int		append_buf(char **o_buf, char *n_buf);
int		trim_buf(char **s_buf, char **line);
int		init_buf(char **buf);
int		free_buf(char **buf);

size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);

#endif
