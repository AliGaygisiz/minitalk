/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaygisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 17:15:56 by agaygisi          #+#    #+#             */
/*   Updated: 2022/10/18 17:17:15 by agaygisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char) c)
			return (((char *) s + i));
		i++;
	}
	if (c == '\0')
		return ((char *)s + i);
	else
		return ((char *) NULL);
}

// int	main(int argc, char *argv[])
// {
// 	char	*p;
//
// 	char a[] = "deneme";
// 	p = ft_strchr(a, 'e');
// 	printf("%s\n", a);
// 	*p = 'a';
// 	printf("%s\n", a);
// 	return (0);
// }
