/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglens <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/09 13:43:11 by cglens            #+#    #+#             */
/*   Updated: 2016/06/12 16:19:13 by cglens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*str;
	int		tab[2];

	if (s1 == NULL)
		str = (char *)malloc(sizeof(char) * (ft_strlen(s2) + 1));
	else
		str = (char *)malloc(sizeof(char) * (ft_strlen(s1)
					+ ft_strlen(s2) + 1));
	if (str == NULL)
		return (NULL);
	tab[0] = 0;
	while (s1 && s1[tab[0]])
	{
		str[tab[0]] = s1[tab[0]];
		tab[0]++;
	}
	tab[1] = -1;
	while (s2[++tab[1]])
	{
		str[tab[0]] = s2[tab[1]];
		tab[0]++;
	}
	free(s1);
	str[tab[0]] = '\0';
	return (str);
}

int		end_of_line(int nbyte, char *buff, char **line, char *str)
{
	int		len;
	int		i;

	len = 0;
	i = 0;
	while (buff[i] != '\n' && buff[i] != '\0')
		i++;
	ft_memcpy(str, buff, i);
	str[i] = '\0';
	len = (nbyte == 0) ? ft_strlen(buff) - i : nbyte - i;
	ft_memmove(buff, buff + i + 1, len);
	*line = ft_strjoin_gnl(*line, str);
	free(str);
	return (1);
}

void	again(char **line, char *str, char *buff, int fd)
{
	int		i;

	i = 0;
	while (buff[i] != '\n' && buff[i] != '\0')
		i++;
	ft_memcpy(str, buff, i);
	str[i] = '\0';
	*line = ft_strjoin_gnl(*line, str);
	buff[0] = '\0';
	free(str);
	get_next_line_rec(fd, line);
}

int		get_next_line_rec(int const fd, char **line)
{
	static char buff[BUFF_SIZE + 1] = {0};
	ssize_t		nbyte;
	size_t		i;
	char		*str;

	i = 0;
	nbyte = 0;
	if (!buff[0])
	{
		nbyte = read(fd, buff, BUFF_SIZE);
		if (nbyte == -1)
			return (-1);
		buff[nbyte] = '\0';
	}
	if (buff[0] == '\0')
		return (0);
	while (buff[i] != '\n' && buff[i] != '\0')
		i++;
	if (!(str = (char *)malloc(sizeof(char) * (i + 1))))
		return (-1);
	if (buff[i] == '\n')
		return (end_of_line(nbyte, buff, line, str));
	else
		again(line, str, buff, fd);
	return (1);
}

int		get_next_line(int const fd, char **line)
{
	if (fd < 0 || !line)
		return (-1);
	*line = NULL;
	return (get_next_line_rec(fd, line));
}
