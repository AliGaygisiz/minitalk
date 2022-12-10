/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaygisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 10:25:23 by agaygisi          #+#    #+#             */
/*   Updated: 2022/11/09 10:25:23 by agaygisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_count_pointer(unsigned long nbr, int base)
{
	int	size;

	size = 0;
	if (nbr == 0)
		return (1);
	while (nbr)
	{
		nbr = nbr / base;
		size++;
	}
	return (size);
}

int	ft_c_dgt(long long nbr, int base)
{
	int	size;

	size = 0;
	if (nbr == 0)
		return (1);
	nbr = ft_abs(nbr);
	while (nbr)
	{
		nbr = nbr / base;
		size++;
	}
	return (size);
}
