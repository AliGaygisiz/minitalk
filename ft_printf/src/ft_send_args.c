/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_send_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaygisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 10:25:23 by agaygisi          #+#    #+#             */
/*   Updated: 2022/11/09 10:25:23 by agaygisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_eval_arg(char *part, va_list args)
{
	if (part[ft_strlen(part) - 1] == 's')
		return (ft_print_str(va_arg(args, char *)));
	else if (part[ft_strlen(part) - 1] == 'd' || part[ft_strlen(part)
			- 1] == 'i')
		return (ft_print_number(va_arg(args, int), 10, "0123456789"));
	else if (part[ft_strlen(part) - 1] == 'c')
		return (ft_print_char(va_arg(args, int)));
	else if (part[ft_strlen(part) - 1] == 'u')
		return (ft_print_number(va_arg(args, unsigned int), 10, "0123456789"));
	else if (part[ft_strlen(part) - 1] == 'x')
		return (ft_print_number(va_arg(args, unsigned int), 16,
				"0123456789abcdef"));
	else if (part[ft_strlen(part) - 1] == 'X')
		return (ft_print_number(va_arg(args, unsigned int), 16,
				"0123456789ABCDEF"));
	else if (part[ft_strlen(part) - 1] == 'p')
		return (ft_print_pointer(va_arg(args, unsigned long), 16,
				"0123456789abcdef"));
	return (0);
}
