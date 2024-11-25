/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naomi <naomi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 16:19:31 by nleandro          #+#    #+#             */
/*   Updated: 2024/11/22 13:21:01 by naomi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*res;
	void	*stp;

	res = 0;
	while (lst && f && del)
	{
		stp = f(lst->content);
		if (!stp)
		{
			ft_lstclear(&res, del);
			return (0);
		}
		new = ft_lstnew(stp);
		if (!new)
		{
			ft_lstclear(&res, del);
			del(stp);
			return (0);
		}
		ft_lstadd_back(&res, new);
		lst = lst->next;
	}
	return (res);
}
