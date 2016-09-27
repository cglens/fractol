/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   model.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglens <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 18:02:08 by cglens            #+#    #+#             */
/*   Updated: 2016/09/27 18:57:11 by cglens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_mandel(t_graph *put, t_point *pt)
{
	int		i;
	double	tmp;
	double	nb;

	put->img = mlx_new_image(put->mlx, put->win_x, put->win_y);
	put->data = mlx_get_data_addr(put->img, &put->bpp, &put->sizeline, &put->endian);
	pt->x = 0;
	while (pt->x < put->win_x)
	{
		pt->y = 0;
		while (pt->y < put->win_y)
		{
			pt->c.r = pt->x / pt->zoom + pt->x0;
			pt->c.i = pt->y / pt->zoom + pt->y0;
			pt->z.r = 0;
			pt->z.i = 0;
			i = 0;
			while (pt->z.i * pt->z.i + pt->z.r * pt->z.r < 4. && i < pt->iter)
			{
				tmp = pt->z.r;
				pt->z.r = pt->z.r * pt->z.r - pt->z.i * pt->z.i + pt->c.r;
				pt->z.i = 2. * pt->z.i * tmp + pt->c.i;
				i++;
			}
			pixel(pt, put, pt->x, pt->y, i);
			pt->y++;
		}
		pt->x++;
	}
	mlx_put_image_to_window(put->mlx, put->win, put->img, 0, 0);
}

void	ft_julia(t_graph *put, t_point *pt)
{
	int		i;
	double	tmp;
	double	nb;

	put->img = mlx_new_image(put->mlx, put->win_x, put->win_y);
	put->data = mlx_get_data_addr(put->img, &put->bpp, &put->sizeline, &put->endian);
	pt->x = 0;
	while (pt->x < put->win_x)
	{
		pt->y = 0;
		while (pt->y < put->win_y)
		{
			pt->c.r = 0.285;
			pt->c.i = 0.01;
			pt->z.r = pt->x / pt->zoom + pt->x0;
			pt->z.i = pt->y / pt->zoom + pt->y0;
			i = 0;
			while (pt->z.i * pt->z.i + pt->z.r * pt->z.r < 4. && i < pt->iter)
			{
				tmp = pt->z.r;
				pt->z.r = pt->z.r * pt->z.r - pt->z.i * pt->z.i + pt->c.r;
				pt->z.i = 2. * pt->z.i * tmp + pt->c.i;
				i++;
			}
			pixel(pt, put, pt->x, pt->y, i);
			pt->y++;
		}
		pt->x++;
	}
	mlx_put_image_to_window(put->mlx, put->win, put->img, 0, 0);
}
