/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyi <hyi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 10:47:04 by hyi               #+#    #+#             */
/*   Updated: 2020/12/26 18:45:28 by hyi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	st;

	st = 0;
	while (*(s + st))
	{
		if (*(s + st) == (char)c)
			return ((char *)(s + st));
		st++;
	}
	if (c == '\0')
		return ((char *)(s + st));
	return (0);
}
