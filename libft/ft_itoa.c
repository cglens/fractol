/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglens <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 17:05:02 by cglens            #+#    #+#             */
/*   Updated: 2016/01/22 20:50:37 by noxx             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_cmp(int n)
{
	int				i;
	unsigned int	nb;

	i = 0;
	nb = (unsigned int)n;
	if (n < 0)
	{
		nb *= -1;
		i++;
	}
	while (nb >= 10)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

char		*ft_itoa(int n)
{
	char			*str;
	int				i;
	int				len;
	unsigned int	nb;

	i = 0;
	nb = (unsigned int)n;
	len = ft_cmp(n) + 1;
	str = (char *)malloc(sizeof(char) * len + 1);
	if (str == NULL)
		return (NULL);
	if (n < 0)
	{
		str[0] = '-';
		i++;
		nb *= -1;
	}
	str[len] = '\0';
	while (i < len--)
	{
		str[len] = nb % 10 + '0';
		nb = nb / 10;
	}
	return (str);
}
