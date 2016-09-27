/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglens <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 16:57:49 by cglens            #+#    #+#             */
/*   Updated: 2015/12/15 19:54:43 by cglens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*src;
	const unsigned char	*dst;
	size_t				i;

	src = (const unsigned char *)s1;
	dst = (const unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (src[i] && dst[i] && i != n && src[i] == dst[i])
		i++;
	if (i == n)
		i--;
	return (src[i] - dst[i]);
}
