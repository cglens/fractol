/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglens <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 23:13:43 by cglens            #+#    #+#             */
/*   Updated: 2016/09/26 05:16:31 by cglens           ###   ########.fr       */
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
		fractol->pt->x0 -= 1;
		fractol->pt->x1 += 1;
		fractol->pt->y0 -= 1;
		fractol->pt->y1 += 1;
		fractol->pt->zoom += 50;
	}
	mandel(put, pt);
	// calculer les coordonnees des nouveaux points grace aux X | Y renvoye par la mlx et faire des ailles de divisions et passer par des conertions pixel/plan
}

int		mouse_event(int key, int x, int y, t_fractol *fractol)
{
	zoom(key, fractol);
	return (0);
}

int		key_event(int key)
{
	if (key == 53)
		exit(1);
	return (0);
}
