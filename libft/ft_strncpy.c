/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglens <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 19:42:15 by cglens            #+#    #+#             */
/*   Updated: 2015/12/15 16:48:18 by cglens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (src[i] && i != n)
	{
		dst[i] = src[i];
		i++;
	}
	if (i == n - 1)
		dst[i] = '\0';
	while (i != n)
	{
		dst[i] = '\0';
		i++;
	}
	return (dst);
}
