/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaygisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 17:15:56 by agaygisi          #+#    #+#             */
/*   Updated: 2022/10/18 17:17:16 by agaygisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dup;

	dup = malloc(ft_strlen(s1) * sizeof(char) + 1);
	if (!dup)
		return (0);
	ft_memcpy(dup, s1, ft_strlen(s1));
	dup[ft_strlen(s1)] = '\0';
	return (dup);
}
