/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglens <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 23:13:43 by cglens            #+#    #+#             */
/*   Updated: 2016/09/29 14:13:10 by cglens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_color(int key, t_graph *put, t_point *pt)
{
	if (ft_strcmp(pt->e, "Julia") == 0)
		ft_init_julia(put, pt);
	if (ft_strcmp(pt->e, "Lapin_de_Douady") == 0)
		ft_init_julia(put, pt);
	if (ft_strcmp(pt->e, "Mandelbrot") == 0)
		ft_init_mandel(put, pt);
}

void	ft_change(int key, t_graph *put, t_point *pt)
{
	if (key == 18 || key == 19)
	{
		if (key == 18)
			pt->e = "Julia";
		if (key == 19)
			pt->e = "Lapin_de_Douady";
		ft_init_julia(put, pt);
	}
	if (key == 20)
	{
		pt->e = "Mandelbrot";
		ft_init_mandel(put, pt);
	}
}

int		key_event(int key, t_fractol *fractol)
{
	t_graph		*put;
	t_point		*pt;

	put = fractol->put;
	pt = fractol->pt;
	pt->key = key;
	if (key == 53)
		exit(1);
	if (key == 18 || key == 19 || key == 20)
		ft_change(key, put, pt);
	if (key == 15 || key == 5 || key == 11)
		ft_color(key, put, pt);
	return (0);
}
