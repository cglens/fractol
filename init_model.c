/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_model.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglens <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/03 18:54:39 by cglens            #+#    #+#             */
/*   Updated: 2016/10/05 13:18:49 by cglens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_mandel(t_point *pt)
{
	pt->c.r = pt->x / pt->zoom + pt->x0;
	pt->c.i = pt->y / pt->zoom + pt->y0;
	pt->z.r = 0;
	pt->z.i = 0;
}

void	ft_lapin(t_point *pt)
{
	if (pt->key != 49)
	{
		pt->c.r = -0.123;
		pt->c.i = 0.745;
	}
	pt->z.r = pt->x / pt->zoom + pt->x0;
	pt->z.i = pt->y / pt->zoom + pt->y0;
}

void	ft_julia(t_point *pt)
{
	if (pt->key != 49)
	{
		pt->c.r = 0.285;
		pt->c.i = 0.01;
	}
	pt->z.r = pt->x / pt->zoom + pt->x0;
	pt->z.i = pt->y / pt->zoom + pt->y0;
}

void	ft_julia_2(t_point *pt)
{
	if (pt->key != 49)
	{
		pt->c.r = -0.223;
		pt->c.i = 0.745;
	}
	pt->z.r = pt->x / pt->zoom + pt->x0;
	pt->z.i = pt->y / pt->zoom + pt->y0;
}

void	go_init(t_point *pt)
{
	if (ft_strcmp(pt->e, "Julia") == 0)
		ft_julia(pt);
	if (ft_strcmp(pt->e, "Julia_2") == 0)
		ft_julia_2(pt);
	if (ft_strcmp(pt->e, "Lapin_de_Douady") == 0)
		ft_lapin(pt);
	if (ft_strcmp(pt->e, "Mandelbrot") == 0)
		ft_mandel(pt);
}
