/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglens <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 15:17:42 by cglens            #+#    #+#             */
/*   Updated: 2016/10/05 15:17:44 by cglens           ###   ########.fr       */
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
			go_init(pt);
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

void	ft_init_model(t_graph *put, t_point *pt)
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
