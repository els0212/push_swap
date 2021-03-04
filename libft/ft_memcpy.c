/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyi <hyi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 10:44:07 by hyi               #+#    #+#             */
/*   Updated: 2020/12/26 20:13:19 by hyi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t len)
{
	size_t				st;
	unsigned char		*dst_uc;
	const unsigned char	*src_uc;

	st = 0;
	dst_uc = (unsigned char *)dst;
	src_uc = (const unsigned char *)src;
	if (!dst && !src)
		return (0);
	while (st < len)
	{
		dst_uc[st] = src_uc[st];
		st++;
	}
	return (dst);
}
