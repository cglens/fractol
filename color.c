/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuto.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglens <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/26 05:15:23 by cglens            #+#    #+#             */
/*   Updated: 2016/09/29 14:09:01 by cglens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	pixel(t_point *pt, t_graph *put, int x, int y)
{
	if (pt->key == 15)
		pt->rgb = pt->color * 9;
	else if (pt->key == 5)
		pt->rgb = pt->color * 9 * 256;
	else if (pt->key == 11)
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
