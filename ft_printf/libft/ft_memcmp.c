/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaygisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 17:15:51 by agaygisi          #+#    #+#             */
/*   Updated: 2022/10/18 17:17:00 by agaygisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if ((*(unsigned char *)(s1 + i) - (*(unsigned char *)(s2 + i)) == 0))
			i++;
		else
			return ((*(unsigned char *)(s1 + i) - (*(unsigned char *)(s2
					+ i))));
	}
	return (0);
}
