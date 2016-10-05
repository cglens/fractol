/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglens <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 15:18:17 by cglens            #+#    #+#             */
/*   Updated: 2016/10/05 19:28:05 by cglens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	pixel(t_point *pt, t_graph *put, int x, int y)
{
	if (pt->key == 15 || pt->key == 5 | pt->key == 11)
		pt->save = pt->key;
	if (pt->save == 15)
		pt->rgb = pt->color * 9;
	else if (pt->save == 5)
		pt->rgb = pt->color * 9 * 256;
	else if (pt->save == 11)
		pt->rgb = pt->color * 9 * 256 * 256;
	else
		pt->rgb = pt->color * 9 * 256 * 256;
	pt->rgb = mlx_get_color_value(put->mlx, pt->rgb);
	if (1 <= x && x <= put->win_x && 1 <= y && y <= put->win_y)
	{
		(put->data + y * put->sizeline + 4 * x)[0] = pt->rgb >> 16;
		(put->data + y * put->sizeline + 4 * x)[1] = pt->rgb >> 8;
		(put->data + y * put->sizeline + 4 * x)[2] = pt->rgb;
	}
}

int		ft_error(void)
{
	ft_putendl("Fractals disponibles :");
	ft_putstr("Julia, Julia_2, Mandelbrot, Lapin_de_Douady");
	return (0);
}

void	ft_win_2(t_graph *put)
{
	put->mlx_2 = mlx_init();
	put->win_2 = mlx_new_window(put->mlx_2, 300, 500, "Help");
	mlx_string_put(put->mlx_2, put->win_2, 50, 50, 0x00ff00, "1 : Julia");
	mlx_string_put(put->mlx_2, put->win_2, 50, 100, 0x00ff00, "2 : Mandelbrot");
	mlx_string_put(put->mlx_2, put->win_2, 50, 150, 0x00ff00,
			"3 : Lapin de Douady");
	mlx_string_put(put->mlx_2, put->win_2, 50, 200, 0x00ff00, "4 : Julia 2");
	mlx_string_put(put->mlx_2, put->win_2, 50, 250, 0x00ff00, "R : Red");
	mlx_string_put(put->mlx_2, put->win_2, 50, 300, 0x00ff00, "G : Green");
	mlx_string_put(put->mlx_2, put->win_2, 50, 350, 0x00ff00, "B : Blue");
	mlx_string_put(put->mlx_2, put->win_2, 50, 400, 0x00ff00, "SPACE : Move");
	mlx_string_put(put->mlx_2, put->win_2, 50, 450, 0x00ff00, "ESC : escape");
	mlx_loop(put->mlx_2);
}
