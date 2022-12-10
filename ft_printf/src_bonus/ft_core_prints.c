/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_core_prints.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaygisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 10:25:23 by agaygisi          #+#    #+#             */
/*   Updated: 2022/11/09 10:25:23 by agaygisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_print_percent(char *part)
{
	if (part[ft_strlen(part) - 1] == '%')
		write(1, "%", 1);
	return (1);
}

int	ft_print_char(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_print_str(char *s)
{
	size_t	i;
	int		count;

	i = 0;
	count = 0;
	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (s[i])
	{
		write(1, &s[i], 1);
		count++;
		i++;
	}
	return (count);
}

int	ft_print_number(long long n, int base, char *radix)
{
	long long	nbr;

	nbr = ft_abs(n);
	n = ft_abs(n);
	if (n >= base)
	{
		ft_print_number(n / base, base, radix);
		n = n % base;
	}
	if (n < base)
	{
		ft_putchar_fd(radix[n], 1);
	}
	return (ft_c_dgt(nbr, base));
}

int	ft_print_pointer(unsigned long n, int base, char *radix)
{
	unsigned long	nbr;

	nbr = n;
	if (n == 0)
		return (ft_print_str("(nil)"));
	write(1, "0x", 2);
	if (n >= (unsigned long)base)
	{
		ft_print_number(n / base, base, radix);
		n = n % base;
	}
	if (n < (unsigned long)base)
	{
		ft_putchar_fd(radix[n], 1);
	}
	return (ft_count_pointer(nbr, base) + 2);
}
