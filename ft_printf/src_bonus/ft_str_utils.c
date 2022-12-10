/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaygisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 10:25:30 by agaygisi          #+#    #+#             */
/*   Updated: 2022/11/09 10:25:30 by agaygisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_left_padding_str(char *arg, char *str)
{
	if (!ft_minus_flag(arg))
		if (ft_wm(arg) > ft_t_str_sz(arg, str))
			return (ft_cc(' ', ft_wm(arg) - ft_t_str_sz(arg, str)));
	return (0);
}

int	ft_print_str_core(char *arg, char *str)
{
	if (str == 0 && (ft_pm(arg) >= 6 || !ft_is_pm(arg)))
		return (ft_print_str("(null)"));
	if (str == 0 && ft_pm(arg) < 6)
		return (ft_print_str(""));
	if (ft_is_pm(arg))
	{
		if (ft_pm(arg) < (int)ft_strlen(str))
		{
			write(1, str, ft_pm(arg));
			return (ft_pm(arg));
		}
	}
	return (ft_print_str(str));
}

int	ft_right_padding_str(char *arg, char *str)
{
	if (ft_minus_flag(arg))
		if (ft_wm(arg) > ft_t_str_sz(arg, str))
			return (ft_cc(' ', ft_wm(arg) - ft_t_str_sz(arg, str)));
	return (0);
}
