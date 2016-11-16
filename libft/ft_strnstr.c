/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglens <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 20:03:16 by cglens            #+#    #+#             */
/*   Updated: 2015/12/14 16:45:32 by cglens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	if (s2[i] == '\0')
		return ((char *)s1 + i);
	while (s1[i] && n != 0)
	{
		j = i;
		while (s1[j] == s2[k] && n != 0 && s2[k])
		{
			j++;
			k++;
			n--;
		}
		n = n + k;
		if (s2[k] == '\0')
			return ((char *)s1 + i);
		k = 0;
		i++;
		n--;
	}
	return (0);
}
