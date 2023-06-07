/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntairatt <ntairatt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 14:36:36 by ntairatt          #+#    #+#             */
/*   Updated: 2023/06/07 17:06:42 by ntairatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "libft.h"
#include "ft_printf.h"

void	error(char *str)
{
	ft_printf("%s\n", str);
	exit(EXIT_FAILURE);
}

void	message_error(char *str, char *var)
{
	ft_printf("%s", str);
	ft_printf("%s\n", var);
	exit(EXIT_FAILURE);
}
