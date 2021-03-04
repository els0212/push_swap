/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyi <hyi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 01:05:49 by hyi               #+#    #+#             */
/*   Updated: 2020/12/21 10:42:56 by hyi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t len)
{
	size_t				st;
	unsigned char		*dst_uc;
	const unsigned char	*src_uc;

	st = 0;
	dst_uc = (unsigned char *)dst;
	src_uc = (const unsigned char *)src;
	while (st < len)
	{
		dst_uc[st] = src_uc[st];
		if (dst_uc[st] == (unsigned char)c)
			return (dst + st + 1);
		st++;
	}
	return (0);
}
