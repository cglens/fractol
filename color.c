/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuto.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglens <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/26 05:15:23 by cglens            #+#    #+#             */
/*   Updated: 2016/09/26 05:17:59 by cglens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	pixel(t_point *pt, t_graph *put, int x, int y, int i)
{
	int		color1;

	color1 = i * 9 * 256 * 256;
	color1 = mlx_get_color_value(put->mlx, color1);
	if (1 <= x && x <= put->win_x && 1 <= y && y <= put->win_y)
	{
		(put->data + y * put->sizeline + 4 * x)[0] = color1 >> 16;
		(put->data + y * put->sizeline + 4 * x)[1] = color1 >> 8;
		(put->data + y * put->sizeline + 4 * x)[2] = color1;
	}
}
