/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglens <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 17:16:17 by cglens            #+#    #+#             */
/*   Updated: 2015/12/14 16:41:31 by cglens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	int		i;
	int		len;
	size_t	n;
	int		j;

	i = 0;
	j = -1;
	n = size;
	while (dst[i] && n != 0)
	{
		i++;
		n--;
	}
	len = i;
	if (n == 0)
		return (len + ft_strlen(src));
	while (src[++j])
		if (n > 1)
		{
			dst[i] = src[j];
			i++;
			n--;
		}
	dst[i] = '\0';
	return (len + j);
}
