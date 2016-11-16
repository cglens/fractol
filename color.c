/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglens <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 15:18:17 by cglens            #+#    #+#             */
/*   Updated: 2016/10/23 13:37:43 by cglens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	pixel(t_point *pt, t_graph *put, int x, int y)
{
	if (pt->key == 15 || pt->key == 5 | pt->key == 11 || pt->key == 35)
		pt->save_color = pt->key;
	if (pt->save_color == 35)
	{
		psych(pt, put, x, y);
		return ;
	}
	if (pt->save_color == 15)
		pt->rgb = pt->color * 9;
	else if (pt->save_color == 5)
		pt->rgb = pt->color * 9 * 256;
	else if (pt->save_color == 11)
		pt->rgb = pt->color * 9 * 256 * 256;
	else
		pt->rgb = pt->color * 9 * 256 * 256;
	pt->rgb = mlx_get_color_value(put->mlx, pt->rgb);
	if (1 <= x && x <= W && 1 <= y && y <= H)
	{
		(put->data + y * put->sizeline + 4 * x)[0] = pt->rgb >> 16;
		(put->data + y * put->sizeline + 4 * x)[1] = pt->rgb >> 8;
		(put->data + y * put->sizeline + 4 * x)[2] = pt->rgb;
	}
}

void	psych(t_point *pt, t_graph *put, int x, int y)
{
	int		r;
	int		g;
	int		b;

	if (pt->iter == pt->color)
	{
		(put->data + y * put->sizeline + 4 * x)[0] = 0;
		(put->data + y * put->sizeline + 4 * x)[1] = 0;
		(put->data + y * put->sizeline + 4 * x)[2] = 0;
		return ;
	}
	r = (int)(sinf(pt->frequency * pt->color + 0) * 127 + 128);
	g = (int)(sinf(pt->frequency * pt->color + 2) * 127 + 128);
	b = (int)(sinf(pt->frequency * pt->color + 4) * 127 + 128);
	pt->rgb = pt->color * r * g * b;
	pt->rgb = mlx_get_color_value(put->mlx, pt->rgb);
	if (1 <= x && x <= W && 1 <= y && y <= H)
	{
		(put->data + y * put->sizeline + 4 * x)[0] = (char)(pt->rgb >> 16);
		(put->data + y * put->sizeline + 4 * x)[1] = (char)(pt->rgb >> 8);
		(put->data + y * put->sizeline + 4 * x)[2] = (char)pt->rgb;
	}
}

int		ft_error(void)
{
	ft_putendl("Fractals disponibles :");
	ft_putendl("Julia, Julia_2, Mandelbrot, Lapin_de_Douady");
	return (0);
}

void	ft_win_2_next(t_graph *put)
{
	mlx_string_put(put->mlx_2, put->win_2, 50, 355, 0x00ff00, "ESC : Escape");
	mlx_string_put(put->mlx_2, put->win_2, 50, 405, 0x00ff00, "P.Up : Freq++");
	mlx_string_put(put->mlx_2, put->win_2, 300, 255, 0x00ff00, "Scroll : Zoom");
	mlx_string_put(put->mlx_2, put->win_2, 300, 305, 0x00ff00,
			"Left click : Zoom");
	mlx_string_put(put->mlx_2, put->win_2, 300, 355, 0x00ff00,
			"Right Click : Dezoom");
	mlx_string_put(put->mlx_2, put->win_2, 300, 405, 0x00ff00,
			"P.Down : Freq--");
	mlx_string_put(put->mlx_2, put->win_2, 50, 430, 0x00ff00,
			"----------------------------------------");
	mlx_string_put(put->mlx_2, put->win_2, 50, 455, 0x00ff00,
			"Left : Move Left");
	mlx_string_put(put->mlx_2, put->win_2, 50, 505, 0x00ff00,
			"Right : Move Right");
	mlx_string_put(put->mlx_2, put->win_2, 300, 455, 0x00ff00,
			"Up : Move Up");
	mlx_string_put(put->mlx_2, put->win_2, 300, 505, 0x00ff00,
			"Down : Move Down");
	mlx_loop(put->mlx_2);
}

void	ft_win_2(t_graph *put)
{
	put->mlx_2 = mlx_init();
	put->win_2 = mlx_new_window(put->mlx_2, 500, 550, "Help");
	mlx_string_put(put->mlx_2, put->win_2, 50, 50, 0x00ff00, "1 : Julia");
	mlx_string_put(put->mlx_2, put->win_2, 50, 100, 0x00ff00, "2 : Mandelbrot");
	mlx_string_put(put->mlx_2, put->win_2, 50, 150, 0x00ff00,
			"3 : Lapin de Douady");
	mlx_string_put(put->mlx_2, put->win_2, 50, 200, 0x00ff00, "4 : Julia 2");
	mlx_string_put(put->mlx_2, put->win_2, 300, 50, 0x00ff00, "R : Red");
	mlx_string_put(put->mlx_2, put->win_2, 300, 100, 0x00ff00, "G : Green");
	mlx_string_put(put->mlx_2, put->win_2, 300, 150, 0x00ff00, "B : Blue");
	mlx_string_put(put->mlx_2, put->win_2, 300, 200, 0x00ff00, "P : Psyche");
	mlx_string_put(put->mlx_2, put->win_2, 50, 225, 0x00ff00,
			"----------------------------------------");
	mlx_string_put(put->mlx_2, put->win_2, 50, 255, 0x00ff00, "SPACE : Move");
	mlx_string_put(put->mlx_2, put->win_2, 50, 305, 0x00ff00, "S : Stop Move");
	ft_win_2_next(put);
}
