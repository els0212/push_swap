/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyi <hyi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 10:50:52 by hyi               #+#    #+#             */
/*   Updated: 2020/12/24 02:25:40 by hyi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_is_set(char c, const char *set)
{
	int	st;

	st = 0;
	while (set[st])
	{
		if (set[st] == c)
			return (1);
		st++;
	}
	return (0);
}

int		ft_get_st(const char *s1, const char *set, int st, int incr)
{
	while (s1[st] && ft_is_set(s1[st], set))
		st += incr;
	return (st);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	char	*ret;
	int		st;
	int		ed;

	if (!s1 || !set)
		return (0);
	st = ft_get_st(s1, set, 0, 1);
	ed = ft_strlen(s1);
	if (!s1[st] || ed == 0)
		return (ft_calloc(1, sizeof(char)));
	else
	{
		ed = ft_get_st(s1, set, (int)ft_strlen(s1) - 1, -1);
		if (st >= ed)
			return (ft_calloc(1, sizeof(char)));
		else
		{
			if (!(ret = (char *)malloc(sizeof(char) * (ed - st + 2))))
				return (0);
			ft_strlcpy(ret, &s1[st], ed - st + 2);
		}
	}
	return (ret);
}
