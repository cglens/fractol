/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglens <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 15:18:58 by cglens            #+#    #+#             */
/*   Updated: 2016/10/05 15:32:16 by cglens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		main(int ac, char **av)
{
	t_graph		*put;
	t_point		*pt;

	put = (t_graph *)malloc(sizeof(t_graph));
	pt = (t_point *)malloc(sizeof(t_point));
	if (ac != 2)
		return (ft_error());
	pt->e = av[1];
	pt->key = 0;
	pt->save = 0;
	pt->x_move = 0;
	pt->y_move = 0;
	if (ft_strcmp(pt->e, "Julia") == 0 ||
			ft_strcmp(pt->e, "Julia_2") == 0 ||
			ft_strcmp(pt->e, "Lapin_de_Douady") == 0 ||
			ft_strcmp(pt->e, "Mandelbrot") == 0)
	{
		put->mlx = mlx_init();
		put->win = mlx_new_window(put->mlx, 2000, 1250, "fractol");
		ft_init_model(put, pt);
	}
	else
		return (ft_error());
	return (0);
}
