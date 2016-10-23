/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglens <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 15:18:05 by cglens            #+#    #+#             */
/*   Updated: 2016/10/23 13:36:27 by cglens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	move_fractol(t_graph *put, t_point *pt, t_fractol *fractol)
{
	if (pt->key == 124)
	{
		pt->x0 -= pt->scale;
		pt->x1 -= pt->scale;
	}
	if (pt->key == 123)
	{
		pt->x0 += pt->scale;
		pt->x1 += pt->scale;
	}
	if (pt->key == 126)
	{
		pt->y0 += pt->scale;
		pt->y1 += pt->scale;
	}
	if (pt->key == 125)
	{
		pt->y0 -= pt->scale;
		pt->y1 -= pt->scale;
	}
	ft_same(put, pt, fractol);
}

void	freq(int key, t_graph *put, t_point *pt, t_fractol *fractol)
{
	if (key == 121)
		pt->frequency += 0.001;
	else
		pt->frequency -= 0.001;
	ft_same(put, pt, fractol);
}

void	ft_color(int key, t_graph *put, t_point *pt, t_fractol *fractol)
{
	if (ft_strcmp(pt->e, "Julia") == 0 ||
			ft_strcmp(pt->e, "Lapin_de_Douady") == 0 ||
			ft_strcmp(pt->e, "Julia_2") == 0 ||
			ft_strcmp(pt->e, "Mandelbrot") == 0)
		ft_same(put, pt, fractol);
}

void	ft_change(int key, t_graph *put, t_point *pt)
{
	if (key == 18)
		pt->e = "Julia";
	if (key == 20)
		pt->e = "Lapin_de_Douady";
	if (key == 21)
		pt->e = "Julia_2";
	if (key == 19)
		pt->e = "Mandelbrot";
	ft_init_model(put, pt);
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
	else if (key == 18 || key == 19 || key == 20 || key == 21)
		ft_change(key, put, pt);
	else if (key == 15 || key == 5 || key == 11 || key == 35)
		ft_color(key, put, pt, fractol);
	else if (key == 4)
		ft_win_2(put);
	else if (key == 116 || key == 121)
		freq(key, put, pt, fractol);
	else if (key == 124 || key == 123 || key == 126 || key == 125)
		move_fractol(put, pt, fractol);
	return (0);
}
