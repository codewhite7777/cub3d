/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_01.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alee <alee@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 23:14:17 by alee              #+#    #+#             */
/*   Updated: 2022/07/29 23:23:14 by alee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <unistd.h>
#include <stdlib.h>

void	ft_exit(const char *msg, int exit_code)
{
	if (msg)
		ft_putstr_fd((char *)msg, STDERR_FILENO);
	exit(exit_code);
	return ;
}

void	ft_dptr_free(char **dptr, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		free(dptr[i]);
		i++;
	}
	free(dptr);
}
