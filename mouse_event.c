/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglens <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 23:13:43 by cglens            #+#    #+#             */
/*   Updated: 2016/09/29 13:31:42 by cglens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom(int key, t_fractol *fractol, int x, int y)
{
	t_graph		*put;
	t_point		*pt;

	put = fractol->put;
	pt = fractol->pt;
	mlx_destroy_image(fractol->put->mlx, fractol->put->img);
	if (key == 1)
	{
		x = (pt->x1 + pt->x0) * (fractol->put->win_x / 2);//== nb pxl/2
		y = (pt->y1 + pt->y0) * (fractol->put->win_y / 2);//== nb pxl/2
		fractol->pt->x0 -= x;
		fractol->pt->y0 -= y;
	}
	if (key == 2)
	{
		x = (pt->x1 + pt->x0) * (fractol->put->win_x / 2);//== nb pxl/2
		y = (pt->y1 + pt->y0) * (fractol->put->win_y / 2);//== nb pxl/2
		fractol->pt->x0 += x;
		fractol->pt->y0 += y;
	}
	ft_same(put, pt, fractol);
	// calculer les coordonnees des nouveaux points grace aux X | Y renvoye par la mlx et faire des bailles de divisions et passer par des conversions pixel/plan
}

int		julia_move(int x, int y, t_fractol *fractol)
{
	t_graph		*put;
	t_point		*pt;

	put = fractol->put;
	pt = fractol->pt;
	mlx_destroy_image(fractol->put->mlx, fractol->put->img);
	fractol->pt->c.r = 0;			//max 0.285
	fractol->pt->c.i = 0;			//max 0.01
	// MOTION NOTIFY \\/
	ft_same(put, pt, fractol);
	return (0);
}

int		mouse_event(int key, int x, int y, t_fractol *fractol)
{
	printf("x = %d, y = %d\n", x, y);
	if (ft_strcmp(fractol->pt->e, "Julia") == 0)
		julia_move(x, y, fractol);
	if (key == 1 || key == 2)
		zoom(key, fractol, x, y);
	return (0);
}
