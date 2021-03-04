/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyi <hyi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 10:44:43 by hyi               #+#    #+#             */
/*   Updated: 2020/12/21 10:44:45 by hyi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_dst_lt_src(unsigned char *dst, const unsigned char *src, size_t len)
{
	size_t	st;

	st = 0;
	while (st < len)
	{
		dst[st] = src[st];
		st++;
	}
	return (dst);
}

void	*ft_dst_gt_src(unsigned char *dst, const unsigned char *src, size_t len)
{
	size_t	st;

	st = len;
	while (st > 0)
	{
		dst[st - 1] = src[st - 1];
		st--;
	}
	return (dst);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*dst_uc;
	const unsigned char	*src_uc;

	dst_uc = (unsigned char *)dst;
	src_uc = (const unsigned char *)src;
	if (dst_uc > src_uc)
		dst_uc = ft_dst_gt_src(dst_uc, src_uc, len);
	else if (dst_uc < src_uc)
		dst_uc = ft_dst_lt_src(dst_uc, src_uc, len);
	return (dst);
}
