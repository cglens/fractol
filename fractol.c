/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglens <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 15:17:42 by cglens            #+#    #+#             */
/*   Updated: 2016/10/23 13:11:16 by cglens           ###   ########.fr       */
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
	int		x;
	int		y;

	put->img = mlx_new_image(put->mlx, W, H);
	put->data = mlx_get_data_addr(put->img, &put->bpp, &SIZELINE, &ENDIAN);
	pt->x = 0;
	while (pt->x < W)
	{
		pt->y = 0;
		while (pt->y < H)
		{
			go_init(pt);
			pt->color = ft_iter(pt);
			pixel(pt, put, pt->x, pt->y);
			pt->y++;
		}
		pt->x++;
	}
	if (ft_strcmp(pt->e, "Julia_2") == 0)
		mlx_hook(put->win, 6, 1L << 6, julia_move, fractol);
	else
		mlx_hook(put->win, 6, 1L << 6, ft_move, fractol);
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
	pt->x0 = -2;
	pt->x1 = 2;
	pt->y0 = -1.25;
	pt->y1 = 1.25;
	pt->scale = 0.2;
	pt->zoom_x = W / (pt->x1 - pt->x0);
	pt->zoom_y = H / (pt->y1 - pt->y0);
	pt->iter = 150;
	ft_same(put, pt, fractol);
	mlx_loop(put->mlx);
}
