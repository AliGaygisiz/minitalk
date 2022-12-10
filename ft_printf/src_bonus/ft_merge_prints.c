/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_merge_prints.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaygisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 10:25:23 by agaygisi          #+#    #+#             */
/*   Updated: 2022/11/09 10:25:23 by agaygisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_b_c(char *arg, char c)
{
	int	size;

	size = 0;
	size += ft_left_padding_chr(arg);
	size += ft_print_char(c);
	size += ft_right_padding_chr(arg);
	return (size);
}

int	ft_b_s(char *arg, char *str)
{
	int	size;

	size = 0;
	size += ft_left_padding_str(arg, str);
	size += ft_print_str_core(arg, str);
	size += ft_right_padding_str(arg, str);
	return (size);
}

int	ft_b_n(char *arg, long long nbr, int base, char *radix)
{
	int	size;

	size = 0;
	size += ft_left_padding_nbr(arg, nbr, base);
	size += ft_print_number_core(arg, nbr, base, radix);
	size += ft_right_padding_nbr(arg, nbr, base);
	return (size);
}

int	ft_b_p(char *arg, unsigned long nbr)
{
	int	size;

	size = 0;
	size += ft_left_padding_ptr(arg, nbr, 16);
	size += ft_print_pointer(nbr, 16, "0123456789abcdef");
	size += ft_right_padding_ptr(arg, nbr, 16);
	return (size);
}
