/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglens <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/26 05:11:11 by cglens            #+#    #+#             */
/*   Updated: 2016/09/30 14:15:57 by cglens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_init_mandel(t_graph *put, t_point *pt)
{
	t_fractol	*fractol;
	int			key;

	fractol = (t_fractol *)malloc(sizeof(t_fractol));
	fractol->put = put;
	fractol->pt = pt;
	pt->zoom = 500;
	pt->x0 = -2;
	pt->x1 = 2;
	pt->y0 = -1.25;
	pt->y1 = 1.25;
	pt->iter = 200;
	put->win_x = (pt->x1 - pt->x0) * pt->zoom;
	put->win_y = (pt->y1 - pt->y0) * pt->zoom;
	ft_same(put, pt, fractol);
	mlx_loop(put->mlx);
}

void	ft_init_julia(t_graph *put, t_point *pt)
{
	t_fractol	*fractol;
	int			key;

	fractol = (t_fractol *)malloc(sizeof(t_fractol));
	fractol->put = put;
	fractol->pt = pt;
	pt->zoom = 500;
	pt->x0 = -2;
	pt->x1 = 2;
	pt->y0 = -1.25;
	pt->y1 = 1.25;
	pt->iter = 200;
	put->win_x = (pt->x1 - pt->x0) * pt->zoom;
	put->win_y = (pt->y1 - pt->y0) * pt->zoom;
	pt->c.r = 0.285;
	pt->c.i = 0.01;
	ft_same(put, pt, fractol);
	mlx_loop(put->mlx);
}
