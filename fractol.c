/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglens <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 01:24:31 by cglens            #+#    #+#             */
/*   Updated: 2016/09/27 18:05:11 by cglens           ###   ########.fr       */
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
	if (ac != 2)
	{
		ft_putstr("Fractals disponibles : Julia, Mandelbrot");
		return (0);
	}
	if (ft_strcmp(av[1], "Julia") == 0)
		ft_init_julia(put, pt);
	else if (ft_strcmp(av[1], "Mandelbrot") == 0)
		ft_init_mandelbrot(put, pt);
	else
		ft_putstr("Fractales disponibles : Julia, Mandelbrot");
	return (0);
}
