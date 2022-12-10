/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chr_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaygisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 10:25:23 by agaygisi          #+#    #+#             */
/*   Updated: 2022/11/09 10:25:23 by agaygisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_left_padding_chr(char *arg)
{
	if (!ft_minus_flag(arg))
		if (ft_wm(arg) > 1)
			return (ft_cc(' ', ft_wm(arg) - 1));
	return (0);
}

int	ft_right_padding_chr(char *arg)
{
	if (ft_minus_flag(arg))
		if (ft_wm(arg) > 1)
			return (ft_cc(' ', ft_wm(arg) - 1));
	return (0);
}
