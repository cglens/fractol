/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglens <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 15:18:58 by cglens            #+#    #+#             */
/*   Updated: 2016/10/23 13:41:28 by cglens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		main(int ac, char **av)
{
	t_graph		*put;
	t_point		*pt;

	put = (t_graph *)malloc(sizeof(t_graph));
	pt = (t_point *)ft_memalloc(sizeof(t_point));
	if (ac != 2)
		return (ft_error());
	pt->e = av[1];
	pt->frequency = .01;
	if (ft_strcmp(pt->e, "Julia") == 0 ||
			ft_strcmp(pt->e, "Julia_2") == 0 ||
			ft_strcmp(pt->e, "Lapin_de_Douady") == 0 ||
			ft_strcmp(pt->e, "Mandelbrot") == 0)
	{
		if (!(put->mlx = mlx_init()))
			return (0);
		if (!(put->win = mlx_new_window(put->mlx, W, H, "fractol")))
			return (0);
		ft_init_model(put, pt);
	}
	else
		return (ft_error());
	return (0);
}
