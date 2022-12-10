/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaygisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 10:20:04 by agaygisi          #+#    #+#             */
/*   Updated: 2022/11/09 10:21:04 by agaygisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*nback;
	void	*data;

	nback = NULL;
	if (!lst || !f | !del)
		return (nback);
	while (lst != NULL)
	{
		data = (*f)(lst->content);
		if (!data)
		{
			del(data);
			ft_lstdelone(nback, del);
			return (NULL);
		}
		ft_lstadd_back(&nback, ft_lstnew(data));
		lst = lst->next;
	}
	return (nback);
}
