/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyi <hyi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 10:46:33 by hyi               #+#    #+#             */
/*   Updated: 2020/12/21 10:46:34 by hyi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dest, int c, size_t len)
{
	size_t			st;
	unsigned char	*dest_uc;

	st = 0;
	dest_uc = (unsigned char *)dest;
	while (st < len)
		*(dest_uc + st++) = (unsigned char)c;
	return (dest);
}
