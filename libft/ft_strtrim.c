/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglens <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 17:00:22 by cglens            #+#    #+#             */
/*   Updated: 2015/12/15 19:41:31 by cglens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

static int	ft_nbchar(const char *s)
{
	int		i;
	int		len;

	i = ft_strlen(s);
	len = ft_strlen(s);
	while (s[--i] == ' ' || s[i] == '\t' || s[i] == '\n')
		len--;
	return (len);
}

char		*ft_strtrim(const char *s)
{
	char	*str;
	size_t	i;
	size_t	j;
	size_t	len;

	j = 0;
	if (s == NULL)
		return (NULL);
	len = ft_nbchar(s);
	i = -1;
	while (s[++i] == ' ' || s[i] == '\t' || s[i] == '\n')
		len--;
	if (s[i] == 0)
		return ("");
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	while (j < len)
	{
		str[j] = s[i];
		i++;
		j++;
	}
	str[j] = '\0';
	return (str);
}
