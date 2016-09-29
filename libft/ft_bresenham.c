/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   roset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglens <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/25 01:11:10 by cglens            #+#    #+#             */
/*   Updated: 2016/09/27 15:23:01 by cglens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	pixel(int x, int y)
{
	int color1;

	color1 = mlx_get_color_value(MLX, 0xffffff);
	if (1 < x && x < WIN_X && 1 < y && y < WIN_Y)
	{
		(img->data + y * img->sizeline + 4 * x)[0] = color1 >> 16;
		(img->data + y * img->sizeline + 4 * x)[1] = color1 >> 8;
		(img->data + y * img->sizeline + 4 * x)[2] = color1;
	}
}

void	line(int x0, int y0, int x1, int y1)
{
	dx = abs(x1 - x0);
	sx = x0 < x1 ? 1 : -1;
	dy = abs(y1 - y0);
	sy = y0 < y1 ? 1 : -1;
	err = (dx > dy ? dx : -dy) / 2;
	while (1)
	{
		pixel(x0, y0);
		if (x0 == x1 && y0 == y1)
			break ;
		e2 = err;
		if (e2 > -dx)
		{
			err -= dy;
			x0 += sx;
		}
		if (e2 < dy)
		{
			err += dx;
			y0 += sy;
		}
	}
}
