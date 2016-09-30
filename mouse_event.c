/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglens <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 23:13:43 by cglens            #+#    #+#             */
/*   Updated: 2016/09/30 14:39:52 by cglens           ###   ########.fr       */
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
		printf("x : %d, y : %d\n", x, y);
		fractol->pt->x0 = -0.75;
		fractol->pt->y0 = 0.5;
		fractol->pt->x1 = -0.625;
		fractol->pt->y1 = 0.625;
	}
	if (key == 2)
	{
		x = (pt->x1 + pt->x0) * (fractol->put->win_x / 2);
		y = (pt->y1 + pt->y0) * (fractol->put->win_y / 2);
		fractol->pt->x0 += x;
		fractol->pt->y0 += y;
	}
	ft_same(put, pt, fractol);
}

int		julia_move(int x, int y, t_fractol *fractol)
{
	t_graph		*put;
	t_point		*pt;

	put = fractol->put;
	pt = fractol->pt;
	if (ft_strcmp(fractol->pt->e, "Julia") == 0)
	{
		mlx_destroy_image(fractol->put->mlx, fractol->put->img);
		if (x < pt->x_move && y < pt->y_move)
		{
			fractol->pt->c.r += 0.0001;
			fractol->pt->c.i += 0.001;
		}
		else
		{
			fractol->pt->c.r -= 0.0001;
			fractol->pt->c.i -= 0.001;
		}
		ft_same(put, pt, fractol);
	}
	pt->x_move = x;
	pt->y_move = y;
	return (0);
}

int		mouse_event(int key, int x, int y, t_fractol *fractol)
{
	printf("x = %d, y = %d\n", x, y);
//	if (key == 1 || key == 2)
//		zoom(key, fractol, x, y);
	return (0);
}
