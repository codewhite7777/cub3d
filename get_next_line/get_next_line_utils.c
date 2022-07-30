/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alee <alee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 22:39:28 by alee              #+#    #+#             */
/*   Updated: 2022/03/14 21:20:27 by alee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stddef.h>
#include <stdlib.h>

size_t	ft_strlen(const char *s)
{
	size_t	cur_idx;

	cur_idx = 0;
	if (!s)
		return (cur_idx);
	while (*(s + cur_idx) != '\0')
		cur_idx++;
	return (cur_idx);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	cur_idx;
	size_t	search_idx;

	cur_idx = 0;
	search_idx = ft_strlen(s) + 1;
	while (cur_idx < search_idx)
	{
		if (*((char *)s + cur_idx) == (char)c)
			return ((char *)s + cur_idx);
		cur_idx++;
	}
	return ((char *)(0));
}

char	*ft_strdup(const char *s1)
{
	char	*str;
	size_t	cpy_len;
	size_t	cur_idx;

	cpy_len = ft_strlen(s1) + 1;
	str = (char *)malloc(sizeof(char) * cpy_len);
	if (!str)
		return ((char *)(0));
	cur_idx = 0;
	while (cur_idx < cpy_len)
	{
		*(str + cur_idx) = *(s1 + cur_idx);
		cur_idx++;
	}
	return (str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	cur_idx;
	size_t	str_idx;

	if (!s1 || !s2)
		return ((char *)(0));
	str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return ((char *)(0));
	cur_idx = 0;
	str_idx = 0;
	while (*(s1 + cur_idx) != '\0')
		*(str + str_idx++) = *(s1 + cur_idx++);
	cur_idx = 0;
	while (*(s2 + cur_idx) != '\0')
		*(str + str_idx++) = *(s2 + cur_idx++);
	*(str + str_idx) = '\0';
	return (str);
}
