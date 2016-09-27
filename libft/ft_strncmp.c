/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglens <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 16:08:18 by cglens            #+#    #+#             */
/*   Updated: 2015/12/14 16:44:07 by cglens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	const unsigned char	*src;
	const unsigned char	*dst;
	size_t				i;

	src = (const unsigned char *)s1;
	dst = (const unsigned char *)s2;
	i = 0;
	while (s1[i] && s2[i] && i != n && s1[i] == s2[i])
		i++;
	if (i == n)
		i--;
	return (src[i] - dst[i]);
}
