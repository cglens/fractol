/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_event.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglens <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 15:17:29 by cglens            #+#    #+#             */
/*   Updated: 2016/10/23 13:19:14 by cglens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom_init(int key, t_point *pt, int x, int y)
{
	double		tmp_x;
	double		tmp_y;

	tmp_x = ((double)x / pt->zoom_x + pt->x0);
	tmp_y = ((double)y / pt->zoom_y + pt->y0);
	if (key == 1 || key == 4)
	{
		pt->zoom_x *= 1.3;
		pt->zoom_y *= 1.3;
		pt->x0 = tmp_x - ((double)x / pt->zoom_x);
		pt->y0 = tmp_y - ((double)y / pt->zoom_y);
		pt->iter += 2;
		pt->scale -= 0.01;
	}
	if (key == 2 || key == 5)
	{
		pt->zoom_x *= 0.7;
		pt->zoom_y *= 0.7;
		pt->x0 = tmp_x - ((double)x / pt->zoom_x);
		pt->y0 = tmp_y - ((double)y / pt->zoom_y);
		pt->iter -= 2;
		pt->scale += 0.01;
	}
}

void	zoom(int key, t_fractol *fractol, int x, int y)
{
	t_graph		*put;
	t_point		*pt;

	put = fractol->put;
	pt = fractol->pt;
	ft_bzero(put->mlx, put->sizeline);
	if (y > 0 && 10 < pt->iter && pt->iter < 300)
		zoom_init(key, pt, x, y);
	ft_same(put, pt, fractol);
}

int		julia_move(int x, int y, t_fractol *fractol)
{
	t_graph		*put;
	t_point		*pt;

	put = fractol->put;
	pt = fractol->pt;
	if (pt->key == 49)
	{
		ft_bzero(put->mlx, put->sizeline);
		if (0 < x && x < 2000 && 0 < y && y < 1250)
		{
			pt->c.r = (double)x / W * 4 - 3;
			pt->c.i = (double)y / H * 4 - 3;
			ft_same(put, pt, fractol);
		}
	}
	return (0);
}

int		ft_move(int x, int y, t_fractol *fractol)
{
	t_graph		*put;
	t_point		*pt;

	put = fractol->put;
	pt = fractol->pt;
	if (pt->key == 49)
	{
		ft_bzero(put->mlx, put->sizeline);
		if (x < pt->x_move || y < pt->y_move)
		{
			pt->c.r += 0.0001;
			pt->c.i += 0.001;
		}
		else
		{
			pt->c.r -= 0.0001;
			pt->c.i -= 0.001;
		}
		ft_same(put, pt, fractol);
		pt->x_move = x;
		pt->y_move = y;
	}
	return (0);
}

int		mouse_event(int key, int x, int y, t_fractol *fractol)
{
	if (key == 1 || key == 2 || key == 4 || key == 5)
		zoom(key, fractol, x, y);
	return (0);
}
