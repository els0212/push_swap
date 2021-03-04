/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyi <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 21:53:40 by hyi               #+#    #+#             */
/*   Updated: 2020/12/26 21:55:10 by hyi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*root;
	t_list	*new_node;
	t_list	*curr;

	if (!lst || !f)
		return (NULL);
	curr = lst;
	root = 0;
	while (curr)
	{
		if (!(new_node = ft_lstnew(f(curr->content))))
		{
			ft_lstclear(&root, del);
			ft_lstclear(&lst, del);
			return (NULL);
		}
		if (!root)
			root = new_node;
		else
			ft_lstadd_back(&root, new_node);
		curr = curr->next;
	}
	return (root);
}
