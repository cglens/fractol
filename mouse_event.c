/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_event.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglens <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 15:17:29 by cglens            #+#    #+#             */
/*   Updated: 2016/10/05 15:36:20 by cglens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom(int key, t_fractol *fractol, int x, int y)
{
	double		W;
	double		H;
	t_graph		*put;
	t_point		*pt;

	put = fractol->put;
	pt = fractol->pt;
	mlx_destroy_image(fractol->put->mlx, fractol->put->img);
	W = (fractol->pt->x1 - fractol->pt->x0) * 500 * 0.9;
	H = (fractol->pt->y1 - fractol->pt->y0) * 500 * 0.9;
	printf("W : %f, H : %f\n", W, H);
	if (key == 1)
	{
		printf("AVANT -> x0 : %f, y0 : %f, x1 : %f, y1 : %f\n", fractol->pt->x0, fractol->pt->y0, fractol->pt->x1, fractol->pt->y1);
		fractol->pt->x0 = x - W / 2;
		fractol->pt->x1 = x + W / 2;
		fractol->pt->y0 = y - H / 2;
		fractol->pt->y1 = y + H / 2;
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
