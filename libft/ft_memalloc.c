/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglens <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 16:48:52 by cglens            #+#    #+#             */
/*   Updated: 2016/01/22 20:50:24 by noxx             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*s;

	if (size == 0)
		return (NULL);
	if (!(s = (void *)malloc(size)))
		return (NULL);
	ft_bzero(s, size);
	return (s);
}
