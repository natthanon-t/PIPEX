/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntairatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 14:39:05 by ntairatt          #+#    #+#             */
/*   Updated: 2023/03/30 13:00:12 by ntairatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	format_p(unsigned long int nbr, int *len)
{
	if (nbr >= 16)
	{
		format_p(nbr / 16, len);
		format_p(nbr % 16, len);
	}
	else
	{
		if (nbr >= 0 && nbr <= 9)
			format_c(nbr + '0', len);
		else if (nbr >= 10 && nbr <= 16)
			format_c((nbr - 10) + 'a', len);
	}
}
