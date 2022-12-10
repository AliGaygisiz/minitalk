/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_send_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaygisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 10:25:30 by agaygisi          #+#    #+#             */
/*   Updated: 2022/11/09 10:25:30 by agaygisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_eval_arg(char *p, va_list args)
{
	if (p[ft_strlen(p) - 1] == 's')
		return (ft_b_s(p, va_arg(args, char *)));
	else if (p[ft_strlen(p) - 1] == 'd' || p[ft_strlen(p) - 1] == 'i')
		return (ft_b_n(p, va_arg(args, int), 10, "0123456789"));
	else if (p[ft_strlen(p) - 1] == 'c')
		return (ft_b_c(p, va_arg(args, int)));
	else if (p[ft_strlen(p) - 1] == 'u')
		return (ft_b_n(p, va_arg(args, unsigned int), 10, "0123456789"));
	else if (p[ft_strlen(p) - 1] == 'x')
		return (ft_b_n(p, va_arg(args, unsigned int), 16, "0123456789abcdef"));
	else if (p[ft_strlen(p) - 1] == 'X')
		return (ft_b_n(p, va_arg(args, unsigned int), 16, "0123456789ABCDEF"));
	else if (p[ft_strlen(p) - 1] == 'p')
		return (ft_b_p(p, va_arg(args, unsigned long)));
	return (0);
}
