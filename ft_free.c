/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntairatt <ntairatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 11:02:10 by ntairatt          #+#    #+#             */
/*   Updated: 2023/06/04 12:16:19 by ntairatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/pipex.h"
#include "libft/include/libft.h"

void	free_2(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i]);
	free(str);
}
