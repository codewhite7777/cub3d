/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_01.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alee <alee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 20:51:11 by alee              #+#    #+#             */
/*   Updated: 2022/07/22 15:13:12 by alee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../cub3d.h"

void	ft_exit(const char *msg, int exit_code)
{
	if (msg)
		ft_putstr_fd((char *)msg, STDERR_FILENO);
	exit(exit_code);
	return ;
}

int	split_count(char ***buf)
{
	int	count;

	count = 0;
	while ((*buf)[count])
		count++;
	return (count);
}

void	split_free(char **buf)
{
	int	idx;

	idx = 0;
	while (buf[idx])
	{
		free(buf[idx]);
		idx++;
	}
	free(buf);
}