/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyi <hyi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 21:15:28 by hyi               #+#    #+#             */
/*   Updated: 2020/12/26 22:07:25 by hyi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*del_node;

	if (!lst)
		return ;
	while (*lst)
	{
		del_node = *lst;
		*lst = (*lst)->next;
		ft_lstdelone(del_node, del);
	}
}
