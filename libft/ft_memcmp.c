/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyi <hyi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 10:43:35 by hyi               #+#    #+#             */
/*   Updated: 2020/12/21 10:43:35 by hyi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *b1, const void *b2, size_t len)
{
	size_t				st;
	const unsigned char	*b1_uc;
	const unsigned char	*b2_uc;

	st = 0;
	b1_uc = (const unsigned char *)b1;
	b2_uc = (const unsigned char *)b2;
	if ((!b1 && !b2) || !len)
		return (0);
	while (st < len)
	{
		if (b1_uc[st] != b2_uc[st])
			return (b1_uc[st] - b2_uc[st]);
		st++;
	}
	return (0);
}
