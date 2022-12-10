/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaygisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 17:16:05 by agaygisi          #+#    #+#             */
/*   Updated: 2022/10/18 17:17:30 by agaygisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	save;

	i = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	else if (len == 0 || !haystack[0])
		return (0);
	while (i < len)
	{
		if (haystack[i] == needle[0])
		{
			save = i;
			while (haystack[i] == needle[i - save] && needle[i - save] != '\0'
				&& i < len)
				i++;
			if ((i - save) == ft_strlen(needle))
				return ((char *)(haystack + save));
			i = save;
		}
		i++;
	}
	return (0);
}
