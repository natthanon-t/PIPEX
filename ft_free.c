/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntairatt <ntairatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 11:02:10 by ntairatt          #+#    #+#             */
/*   Updated: 2023/06/04 17:50:07 by ntairatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/pipex.h"
#include "libft/include/libft.h"

void	free_2(char **str)
{
	int	i;

	i = ft_2dlen(str);
	while (i)
		free(str[i--]);
	free(str);
}

int	ft_2dlen(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
