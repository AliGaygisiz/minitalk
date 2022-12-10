/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaygisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 17:16:07 by agaygisi          #+#    #+#             */
/*   Updated: 2022/10/18 17:17:36 by agaygisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return ((unsigned char)c + 32);
	else
		return ((unsigned char)c);
}

// int main (int argc, char *argv[])
// {
//     printf("%c\n",ft_tolower('A'));
//     printf("%c\n",tolower('A'));
//     return (0);
// }
