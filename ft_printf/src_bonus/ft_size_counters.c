/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_size_counters.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaygisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 10:25:30 by agaygisi          #+#    #+#             */
/*   Updated: 2022/11/09 10:25:30 by agaygisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_p_nbr_sz(char *arg, long long nbr, int base)
{
	if (ft_is_pm(arg))
	{
		if (ft_pm(arg) == 0 && nbr == 0)
			return (0);
		if (ft_pm(arg) > ft_c_dgt(nbr, base))
			return (ft_pm(arg));
	}
	return (ft_c_dgt(nbr, base));
}

int	ft_t_nbr_sz(char *arg, long long nbr, int base)
{
	int	number_size;
	int	sign;

	number_size = ft_p_nbr_sz(arg, nbr, base);
	sign = 0;
	if (ft_signed(arg, nbr))
		sign = 1;
	if (ft_hash_flag(arg) && nbr != 0)
		sign = 2;
	return (number_size + sign);
}

int	ft_t_str_sz(char *arg, char *str)
{
	if (str == 0 && (ft_pm(arg) >= 6 || !ft_is_pm(arg)))
		return (ft_strlen("(null)"));
	if (str == 0 && ft_pm(arg) < 6)
		return (0);
	if (ft_is_pm(arg))
		if (ft_pm(arg) < (int)ft_strlen(str))
			return (ft_pm(arg));
	return (ft_strlen(str));
}

int	ft_ptr_sz(unsigned long nbr, int base)
{
	int	size;

	size = 0;
	if (nbr == 0)
		return (ft_strlen("(nil)"));
	while (nbr)
	{
		nbr = nbr / base;
		size++;
	}
	return (size + 2);
}
