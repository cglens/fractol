/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglens <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 17:02:06 by cglens            #+#    #+#             */
/*   Updated: 2015/12/14 16:46:25 by cglens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	ft_nbword(const char *s, char c)
{
	int		i;
	int		j;
	int		cmp;

	i = 0;
	cmp = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c)
			j++;
		else if ((s[i] == c || s[i] == '\0') && j != 0)
		{
			cmp++;
			j = 0;
		}
		i++;
	}
	if (s[i] == '\0' && j != 0)
		cmp++;
	return (cmp);
}

static char	**ft_nowminette(char **str, const char *s, char c)
{
	int		i;
	int		j;
	int		cmp;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		cmp = 0;
		if (s[i] == c)
			i++;
		if (s[i] != '\0' && s[i] != c)
		{
			i--;
			while (s[++i] != '\0' && s[i] != c)
				cmp++;
			str[j] = ft_strsub(s, i - cmp, cmp);
			j++;
		}
	}
	str[j] = 0;
	return (str);
}

char		**ft_strsplit(const char *s, char c)
{
	char	**str;
	int		i;

	i = ft_nbword(s, c) + 1;
	if (!(str = (char **)malloc(sizeof(char *) * i)))
		return (NULL);
	str = ft_nowminette(str, s, c);
	return (str);
}
