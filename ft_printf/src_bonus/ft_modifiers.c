/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_modifiers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaygisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 10:25:23 by agaygisi          #+#    #+#             */
/*   Updated: 2022/11/09 10:25:23 by agaygisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_wm(char *s)
{
	int	i;

	i = 0;
	while (ft_strchr("%# +-", s[i]))
		i++;
	return (ft_atoi(&s[i]));
}

int	ft_is_pm(char *s)
{
	return (!!ft_strchr(s, '.'));
}

int	ft_pm(char *s)
{
	if (!ft_strchr(s, '.'))
		return (-1);
	return (ft_atoi(ft_strchr(s, '.') + 1));
}
