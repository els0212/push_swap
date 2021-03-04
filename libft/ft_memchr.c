/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyi <hyi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 10:43:13 by hyi               #+#    #+#             */
/*   Updated: 2020/12/21 10:52:46 by hyi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(void *b, int c, size_t len)
{
	size_t			st;
	unsigned char	*b_uc;

	st = 0;
	b_uc = (unsigned char *)b;
	while (st < len)
	{
		if (b_uc[st] == (unsigned char)c)
			return (b + st);
		st++;
	}
	return (0);
}
