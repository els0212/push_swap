/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyi <hyi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 17:12:31 by hyi               #+#    #+#             */
/*   Updated: 2020/12/24 17:12:32 by hyi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char			s[11];
	unsigned int	n_u;
	unsigned int	div;
	int				st;

	st = 0;
	if (n < 0)
		n_u = (unsigned int)(n * -1);
	else
		n_u = (unsigned int)n;
	while ((div = n_u / DIVISOR))
	{
		s[st++] = n_u % DIVISOR + '0';
		n_u = div;
	}
	s[st++] = n_u + '0';
	if (n < 0)
		s[st++] = '-';
	while (--st >= 0)
		write(fd, &s[st], 1);
}
