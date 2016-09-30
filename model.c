/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   model.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglens <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 18:02:08 by cglens            #+#    #+#             */
/*   Updated: 2016/09/30 14:17:18 by cglens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_iter(t_point *pt)
{
	int		i;
	double	tmp;

	i = 0;
	while (pt->z.i * pt->z.i + pt->z.r * pt->z.r < 4. && i < pt->iter)
	{
		tmp = pt->z.r;
		pt->z.r = pt->z.r * pt->z.r - pt->z.i * pt->z.i + pt->c.r;
		pt->z.i = 2. * pt->z.i * tmp + pt->c.i;
		i++;
	}
	return (i);
}

void	ft_mandel(t_point *pt)
{
	pt->c.r = pt->x / pt->zoom + pt->x0;
	pt->c.i = pt->y / pt->zoom + pt->y0;
	pt->z.r = 0;
	pt->z.i = 0;
}

void	ft_lapin(t_point *pt)
{
	pt->c.r = -0.123;
	pt->c.i = 0.745;
	pt->z.r = pt->x / pt->zoom + pt->x0;
	pt->z.i = pt->y / pt->zoom + pt->y0;
}

void	ft_julia(t_point *pt)
{
	pt->z.r = pt->x / pt->zoom + pt->x0;
	pt->z.i = pt->y / pt->zoom + pt->y0;
}

void	ft_same(t_graph *put, t_point *pt, t_fractol *fractol)
{
	put->img = mlx_new_image(put->mlx, put->win_x, put->win_y);
	put->data = mlx_get_data_addr(put->img, &put->bpp, &SIZELINE, &ENDIAN);
	pt->x = 0;
	while (pt->x < put->win_x)
	{
		pt->y = 0;
		while (pt->y < put->win_y)
		{
			if (ft_strcmp(pt->e, "Julia") == 0)
				ft_julia(pt);
			if (ft_strcmp(pt->e, "Lapin_de_Douady") == 0)
				ft_lapin(pt);
			else if (ft_strcmp(pt->e, "Mandelbrot") == 0)
				ft_mandel(pt);
			pt->color = ft_iter(pt);
			pixel(pt, put, pt->x, pt->y);
			pt->y++;
		}
		pt->x++;
	}
	mlx_hook(put->win, 6, 1L << 6, julia_move, fractol);
	mlx_key_hook(put->win, key_event, fractol);
	mlx_mouse_hook(put->win, mouse_event, fractol);
	mlx_put_image_to_window(put->mlx, put->win, put->img, 0, 0);
}
