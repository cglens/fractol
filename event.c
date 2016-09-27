/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglens <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 23:13:43 by cglens            #+#    #+#             */
/*   Updated: 2016/09/27 18:57:04 by cglens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom(int key, t_fractol *fractol)
{
	t_graph		*put;
	t_point		*pt;

	put = fractol->put;
	pt = fractol->pt;
	mlx_destroy_image(fractol->put->mlx, fractol->put->img);
	if (key == 4)
	{
	//x fractol->put->win_x / 2//== nb pxl/2;
	//y	fractol->put->win_y / 2;
		fractol->pt->x0 -= 1;
		fractol->pt->x1 += 1;
		fractol->pt->y0 -= 1;
		fractol->pt->y1 += 1;
	}
//	mandel(put, pt);
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
	ft_julia(put, pt);
	return (0);
}

int		mouse_event(int key, int x, int y, t_fractol *fractol)
{
	printf("x = %d, y = %d\n", x, y);
	julia_move(x, y, fractol);
	if (key == 4 || key == 5)
		zoom(key, fractol);
	return (0);
}

int		key_event(int key)
{
	if (key == 53)
		exit(1);
	return (0);
}
