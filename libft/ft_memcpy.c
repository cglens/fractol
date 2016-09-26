/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglens <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 16:29:55 by cglens            #+#    #+#             */
/*   Updated: 2015/12/14 16:31:31 by cglens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*s1;
	const char	*s2;
	size_t		i;

	s1 = (char *)dst;
	s2 = (const char *)src;
	i = 0;
	while (i != n)
	{
		s1[i] = s2[i];
		i++;
	}
	return (dst);
}
