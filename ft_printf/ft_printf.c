/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaygisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 10:22:28 by agaygisi          #+#    #+#             */
/*   Updated: 2022/11/10 00:13:26 by agaygisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	int		i;
	int		count;
	char	**parts;
	va_list	args;

	i = 0;
	count = 0;
	parts = ft_split_parts(str);
	va_start(args, str);
	while (parts[i])
	{
		count += ft_print_str(parts[i++]);
		if (parts[i])
		{
			if (parts[i][ft_strlen(parts[i]) - 1] == '%')
				count += ft_print_percent(parts[i++]);
			else if (ft_strchr("cspdiuxX", parts[i][ft_strlen(parts[i]) - 1]))
				count += ft_eval_arg(parts[i++], args);
		}
	}
	ft_free_all(parts);
	return (count);
}
