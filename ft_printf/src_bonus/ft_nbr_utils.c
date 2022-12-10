/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbr_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaygisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 10:25:23 by agaygisi          #+#    #+#             */
/*   Updated: 2022/11/09 10:25:23 by agaygisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_left_padding_nbr(char *arg, long long nbr, int base)
{
	if (ft_zero_flag(arg) && !ft_is_pm(arg))
		return (0);
	if (ft_minus_flag(arg))
	{
		if (ft_space_flag(arg))
			if (nbr >= 0)
				return (ft_print_str(" "));
	}
	else if (ft_wm(arg) > ft_t_nbr_sz(arg, nbr, base))
		return (ft_cc(' ', ft_wm(arg) - ft_t_nbr_sz(arg, nbr, base)));
	else if (ft_space_flag(arg))
		if (nbr >= 0)
			return (ft_print_str(" "));
	return (0);
}

int	ft_print_number_core(char *arg, long long nbr, int base, char *radix)
{
	int	i;

	i = 0;
	if (ft_plus_flag(arg) && nbr >= 0)
		i += ft_print_str("+");
	if (nbr < 0)
		i += ft_print_str("-");
	if (ft_hash_flag(arg) && arg[ft_strlen(arg) - 1] == 'X' && nbr != 0)
		i += ft_print_str("0X");
	if (ft_hash_flag(arg) && arg[ft_strlen(arg) - 1] == 'x' && nbr != 0)
		i += ft_print_str("0x");
	if (ft_zero_flag(arg) && !ft_is_pm(arg))
	{
		if (ft_wm(arg) > ft_t_nbr_sz(arg, nbr, base))
			i += ft_cc('0', ft_wm(arg) - ft_t_nbr_sz(arg, nbr, base));
	}
	else if (ft_is_pm(arg))
		if (ft_pm(arg) > ft_c_dgt(nbr, base))
			i += ft_cc('0', ft_pm(arg) - ft_c_dgt(nbr, base));
	if (ft_is_pm(arg) && ft_pm(arg) == 0 && nbr == 0)
		i += ft_print_str("");
	else
		i += ft_print_number(nbr, base, radix);
	return (i);
}

int	ft_right_padding_nbr(char *a, long long n, int base)
{
	if (ft_minus_flag(a))
		if (ft_wm(a) > ft_t_nbr_sz(a, n, base))
			return (ft_cc(' ', ft_wm(a) - ft_t_nbr_sz(a, n, base)));
	return (0);
}
