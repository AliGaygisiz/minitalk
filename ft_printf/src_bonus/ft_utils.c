/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaygisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 10:25:34 by agaygisi          #+#    #+#             */
/*   Updated: 2022/11/09 10:25:35 by agaygisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

long long	ft_abs(long long n)
{
	if (n < 0)
		return (-n);
	return (n);
}

int	ft_isnegative(long long nbr)
{
	if (nbr < 0)
		return (1);
	return (0);
}

int	ft_cc(char c, int repeat)
{
	int	i;

	i = 0;
	while (i < repeat)
	{
		ft_putchar_fd(c, 1);
		i++;
	}
	return (repeat);
}

int	ft_signed(char *arg, long long nbr)
{
	if (nbr < 0)
		return (1);
	else if (ft_plus_flag(arg))
		return (1);
	return (0);
}
