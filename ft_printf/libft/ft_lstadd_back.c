/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaygisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 10:19:47 by agaygisi          #+#    #+#             */
/*   Updated: 2022/11/09 10:23:53 by agaygisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *newarg)
{
	if (!lst || !newarg)
		return ;
	if (*lst == 0)
		*lst = newarg;
	else
		(ft_lstlast(*lst))->next = newarg;
}
