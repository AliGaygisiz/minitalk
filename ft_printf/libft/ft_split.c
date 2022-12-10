/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaygisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 10:17:55 by agaygisi          #+#    #+#             */
/*   Updated: 2022/11/09 10:17:58 by agaygisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_count_parts(char const *s, char c)
{
	size_t	i;
	size_t	rtn;

	i = 0;
	rtn = 0;
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1] != 0)
			rtn++;
		i++;
	}
	if (s[0] != c)
		rtn++;
	return (rtn);
}

char	**protect(void)
{
	char	**rtn;

	rtn = ft_calloc(1, sizeof(char *));
	rtn[0] = NULL;
	return (rtn);
}

char	**ft_split(char const *s, char c)
{
	char	**rtn;
	size_t	i;
	size_t	index;
	size_t	save;

	i = 0;
	index = 0;
	if (!s || s[0] == 0)
		return (protect());
	rtn = ft_calloc(ft_count_parts(s, c) + 1, sizeof(char *));
	if (!rtn)
		return (NULL);
	while (index < ft_count_parts(s, c))
	{
		while (s[i] == c)
			i++;
		save = i;
		while (s[i] != c && s[i])
			i++;
		rtn[index++] = ft_substr(s, save, i - save);
	}
	rtn[index] = NULL;
	return (rtn);
}
