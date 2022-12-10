/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_parts.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaygisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 10:25:23 by agaygisi          #+#    #+#             */
/*   Updated: 2022/11/09 10:25:23 by agaygisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

size_t	ft_count_arg_len(const char *s, size_t i)
{
	size_t	j;

	j = 1;
	if (s[i + j] == '\0')
		return (0);
	while (!ft_strchr("cspdiuxX%", s[i + j]))
		j++;
	return (j + 1);
}

size_t	ft_count_str_len(const char *s, size_t i)
{
	size_t	j;

	j = 0;
	while (s[i + j] != '%' && s[i + j] != '\0')
		j++;
	return (j);
}

int	ft_count_parts(const char *s)
{
	int		parts;
	size_t	loc;

	parts = 0;
	loc = 0;
	while (loc < ft_strlen(s))
	{
		parts++;
		loc = loc + ft_count_str_len(s, loc);
		if (loc < ft_strlen(s))
		{
			parts++;
			loc = loc + ft_count_arg_len(s, loc);
		}
	}
	return (parts);
}

char	**ft_split_parts(const char *s)
{
	char	**parts;
	size_t	loc;
	int		index;

	index = 0;
	loc = 0;
	parts = malloc((ft_count_parts(s) + 1) * sizeof(char *));
	if (!parts)
		return (NULL);
	while (index < ft_count_parts(s))
	{
		parts[index] = ft_substr(s, loc, ft_count_str_len(s, loc));
		index++;
		loc = loc + ft_count_str_len(s, loc);
		if (loc < ft_strlen(s))
		{
			parts[index] = ft_substr(s, loc, ft_count_arg_len(s, loc));
			index++;
			loc = loc + ft_count_arg_len(s, loc);
		}
	}
	parts[index] = NULL;
	return (parts);
}

void	ft_free_all(char **parts)
{
	int	i;

	i = 0;
	while (parts[i])
		free(parts[i++]);
	free(parts);
}
