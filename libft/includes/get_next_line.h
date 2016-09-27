/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglens <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/09 13:21:44 by cglens            #+#    #+#             */
/*   Updated: 2016/02/12 19:18:34 by cglens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include "libft.h"

# define BUFF_SIZE 32

int		get_next_line(int const fd, char **line);
int		get_next_line_rec(int const fd, char **line);

#endif
