/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglens <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 16:44:37 by cglens            #+#    #+#             */
/*   Updated: 2015/12/15 20:03:02 by cglens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	const char		cpysrc[len];

	ft_memcpy((void *)cpysrc, src, len);
	ft_memcpy(dst, (void *)cpysrc, len);
	return (dst);
}
