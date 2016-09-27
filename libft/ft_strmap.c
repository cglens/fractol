/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglens <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 16:41:27 by cglens            #+#    #+#             */
/*   Updated: 2015/12/15 15:49:53 by cglens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmap(const char *s, char (*f)(char))
{
	char	*str;
	int		i;

	str = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (s == NULL || f == NULL || str == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		str[i] = f(s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
