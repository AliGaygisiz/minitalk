/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaygisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 10:25:23 by agaygisi          #+#    #+#             */
/*   Updated: 2022/11/09 10:25:23 by agaygisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_minus_flag(char *s)
{
	return (!!ft_strchr(s, '-'));
}

int	ft_zero_flag(char *s)
{
	int	i;

	i = 0;
	while (ft_strchr("%# +", s[i]))
		i++;
	if (s[i] == '0')
		return (1);
	return (0);
}

int	ft_hash_flag(char *s)
{
	return (!!ft_strchr(s, '#'));
}

int	ft_space_flag(char *s)
{
	return (!!ft_strchr(s, ' '));
}

int	ft_plus_flag(char *s)
{
	return (!!ft_strchr(s, '+'));
}
