/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglens <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/18 00:01:35 by cglens            #+#    #+#             */
/*   Updated: 2016/09/27 18:57:14 by cglens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include "mlx.h"
# include "../libft/includes/libft.h"

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
	double			x0;
	double			y0;
	double			x1;
	double			y1;
	int 	   	 	step_x;
	int				step_y;;
	int				iter;
	double			x;
	double			y;
	int				color;
	double			zoom;
	t_complex		c;
	t_complex		z;
	t_complex		step;
	t_complex		origin;
	t_complex		init;

}					t_point;

typedef struct		s_fractol
{
	t_point			*pt;
	t_graph			*put;
}					t_fractol;

void				ft_init_mandelbrot(t_graph *put, t_point *pt);
void				ft_init_julia(t_graph *put, t_point *pt);
int					key_event(int key);
int					julia_move(int x, int y, t_fractol *fractol);
int					mouse_event(int key, int x, int y, t_fractol *fractol);
void				pixel(t_point *pt, t_graph *put, int x, int y, int i);
void				ft_mandel(t_graph *put, t_point *pt);
void				ft_julia(t_graph *put, t_point *pt);

#endif
