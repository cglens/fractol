/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglens <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 16:38:20 by cglens            #+#    #+#             */
/*   Updated: 2015/12/14 16:30:07 by cglens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*s1;
	unsigned char		*s2;
	size_t				i;
	unsigned char		a;

	s1 = (unsigned char *)dst;
	s2 = (unsigned char *)src;
	i = 0;
	a = (unsigned char)c;
	while (i < n && s2[i] != a)
	{
		s1[i] = s2[i];
		i++;
	}
	if (s2[i] == a)
	{
		s1[i] = s2[i];
		return (dst + i + 1);
	}
	return (0);
}
