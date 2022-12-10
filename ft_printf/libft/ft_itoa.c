/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaygisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 17:15:49 by agaygisi          #+#    #+#             */
/*   Updated: 2022/10/18 17:16:56 by agaygisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_countdigit(long n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		i++;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*ascii;
	long	nbr;

	nbr = n;
	len = ft_countdigit(nbr);
	ascii = malloc(len + 1);
	if (!ascii)
		return (0);
	if (nbr < 0)
	{
		ascii[0] = '-';
		nbr = nbr * -1;
	}
	ascii[len] = '\0';
	len--;
	while (len >= (n < 0))
	{
		ascii[len] = (nbr % 10) + '0';
		nbr = nbr / 10;
		len--;
	}
	return (ascii);
}
