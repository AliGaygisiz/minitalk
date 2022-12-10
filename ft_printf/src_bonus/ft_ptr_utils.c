/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaygisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 10:25:24 by agaygisi          #+#    #+#             */
/*   Updated: 2022/11/09 10:25:24 by agaygisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_left_padding_ptr(char *arg, unsigned long nbr, int base)
{
	if (!ft_minus_flag(arg))
		if (ft_wm(arg) > ft_ptr_sz(nbr, base))
			return (ft_cc(' ', ft_wm(arg) - ft_ptr_sz(nbr, base)));
	return (0);
}

int	ft_right_padding_ptr(char *arg, unsigned long nbr, int base)
{
	if (ft_minus_flag(arg))
		if (ft_wm(arg) > ft_ptr_sz(nbr, base))
			return (ft_cc(' ', ft_wm(arg) - ft_ptr_sz(nbr, base)));
	return (0);
}
