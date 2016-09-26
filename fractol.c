/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglens <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 01:24:31 by cglens            #+#    #+#             */
/*   Updated: 2016/09/26 05:17:03 by cglens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "../libft/includes/libft.h"

int		main(int ac, char **av)
{
	t_graph		*put;
	t_point		*pt;

	put = (t_graph *)malloc(sizeof(t_graph));
	pt = (t_point *)malloc(sizeof(t_point));
	/*if (ac != 2)
		return (0);
	if (ft_strcmp(av[1], "Julia") != 0 || ft_strcmp(av[1], "Mandelbrot")
			!= 0 || ft_strcmp(av[1], "Pythagore") != 0)
		return (0);*/
	ft_init_mandelbrot(put, pt);
	return (0);
}
