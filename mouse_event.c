/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_event.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglens <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 15:17:29 by cglens            #+#    #+#             */
/*   Updated: 2016/10/05 19:26:16 by cglens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom(int key, t_fractol *fractol, int x, int y)
{
	double		W;
	double		H;
	t_graph		*put;
	t_point		*pt;
	double		x2;
	double		y2;

	put = fractol->put;
	pt = fractol->pt;
	mlx_destroy_image(fractol->put->mlx, fractol->put->img);
	W = 2000;
	H = 1250;
	x2 = x / W;
	y2 = y / H;
	fractol->pt->zoom += 100;
	if (key == 1)
	{
		printf("AVANT -> x0 : %f, y0 : %f, x1 : %f, y1 : %f\n", fractol->pt->x0, fractol->pt->y0, fractol->pt->x1, fractol->pt->y1);
		fractol->pt->x0 = (fractol->pt->x0 * x2) - (x2) / 2;
		fractol->pt->y0 = (fractol->pt->y0 * y2) - (y2) / 2;
		printf("APRES -> x0 : %f, y0 : %f, x1 : %f, y1 : %f\n", fractol->pt->x0, fractol->pt->y0, fractol->pt->x1, fractol->pt->y1);
	}
	ft_same(put, pt, fractol);
}

int		julia_move(int x, int y, t_fractol *fractol)
{
	t_graph		*put;
	t_point		*pt;

	put = fractol->put;
	pt = fractol->pt;
	if (fractol->pt->key == 49)
	{
		mlx_destroy_image(fractol->put->mlx, fractol->put->img);
		if (x < pt->x_move || y < pt->y_move)
		{
			fractol->pt->c.r += 0.0001;
			fractol->pt->c.i += 0.001;
		}
		else
		{
			fractol->pt->c.r -= 0.0001;
			fractol->pt->c.i -= 0.001;
		}
		pt->x_move = x;
		pt->y_move = y;
		ft_same(put, pt, fractol);
	}
	return (0);
}

int		mouse_event(int key, int x, int y, t_fractol *fractol)
{
	printf("x = %d, y = %d\n", x, y);
	if (key == 1 || key == 2)
		zoom(key, fractol, x, y);
	return (0);
}
