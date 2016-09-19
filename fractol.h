/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglens <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/18 00:01:35 by cglens            #+#    #+#             */
/*   Updated: 2016/09/19 05:59:03 by cglens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "mlx.h"
# include "../libft/includes/libft.h"
# include <stdio.h>

typedef struct		s_graph
{
	void			*mlx;
	void			*win;
	int				win_x;
	int				win_y;
	void			*img;
	int				bpp;
	int				endian;
	int				sizeline;
	char			*data;
}					t_graph;

typedef struct		s_complex
{
	double			r;
	double			i;
}					t_complex;

typedef struct		s_point
{	
	float			x0;
	float			y0;
	float			x1;
	float			y1;
	int 	   	 	zoom;
	int				iter;
	int				x;
	int				y;
	int				color;
	t_complex		c;
	t_complex		z;
	t_complex		step;
	t_complex		origin;
	t_complex		init;

}					t_point;

//void				make(t_point *pt, t_graph *put);
void				create(t_graph *put/*, t_point *pt*/);
int					event(int key);
//int					tuto(t_point *pt, t_graph *put);
void				pixel(t_graph *put, int x, int y);
//int					ft_mandelbrot(int iter_max, t_complex z, t_complex c);

#endif
