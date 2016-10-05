/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglens <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 15:18:05 by cglens            #+#    #+#             */
/*   Updated: 2016/10/05 15:18:07 by cglens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_color(int key, t_graph *put, t_point *pt)
{
	if (ft_strcmp(pt->e, "Julia") == 0 ||
			ft_strcmp(pt->e, "Lapin_de_Douady") == 0 ||
			ft_strcmp(pt->e, "Julia_2") == 0 ||
			ft_strcmp(pt->e, "Mandelbrot") == 0)
		ft_init_model(put, pt);
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
	printf("key : %d\n", pt->key);
	if (key == 53)
		exit(1);
	if (key == 18 || key == 19 || key == 20 || key == 21)
		ft_change(key, put, pt);
	if (key == 15 || key == 5 || key == 11)
		ft_color(key, put, pt);
	return (0);
}
