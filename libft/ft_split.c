/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyi <hyi@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 10:59:43 by hyi               #+#    #+#             */
/*   Updated: 2020/12/26 22:28:30 by hyi              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_next_idx(const char *s, char c, int st)
{
	while (s[st] && s[st] != c)
		st++;
	return (st);
}

int		ft_cnt_lines(const char *s, char c)
{
	int	st;
	int	cnt;

	st = 0;
	cnt = 0;
	while (s[st] && s[st] == c)
		st++;
	while (s[st])
	{
		st = ft_next_idx(s, c, st);
		cnt++;
		while (s[st] && s[st] == c)
			st++;
	}
	return (cnt);
}

void	ft_free(char **ret, int ret_st)
{
	int	st;

	st = 0;
	while (st < ret_st)
		free(ret[st]);
	free(ret);
}

char	**ft_split(const char *s, char c)
{
	char	**ret;
	int		ret_st;
	int		st;

	if (!s)
		return (0);
	if (!(ret = (char **)malloc(sizeof(char *) * (ft_cnt_lines(s, c) + 1))))
		return (0);
	ret_st = 0;
	st = 0;
	while (s[st] && s[st] == c)
		st++;
	while (s[st] && ret_st < ft_cnt_lines(s, c))
	{
		if (!(ret[ret_st++] = ft_substr(s, st, ft_next_idx(s, c, st) - st)))
		{
			ft_free(ret, ret_st);
			return (0);
		}
		st = ft_next_idx(s, c, st);
		while (s[st] && s[st] == c)
			st++;
	}
	ret[ret_st] = 0;
	return (ret);
}
