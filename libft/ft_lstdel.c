/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglens <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 17:48:36 by cglens            #+#    #+#             */
/*   Updated: 2015/12/17 16:34:12 by cglens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*p;

	p = *alst;
	while (p->next != NULL)
	{
		del((p)->content, (p)->content_size);
		free(p);
		p = (p)->next;
	}
	del((p)->content, (p)->content_size);
	free(p);
	*alst = NULL;
}
