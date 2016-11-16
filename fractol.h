/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglens <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/18 00:01:35 by cglens            #+#    #+#             */
/*   Updated: 2016/10/27 17:14:30 by cglens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include "mlx.h"
# include "libft.h"
# define SIZELINE put->sizeline
# define ENDIAN put->endian
# define W 1600
# define H 1000

typedef struct		s_graph
{
	void			*mlx;
	void			*win;
	void			*img;
	int				bpp;
	int				endian;
	int				sizeline;
	char			*data;
	void			*mlx_2;
	void			*win_2;
}					t_graph;

typedef struct		s_complex
{
	double			r;
	double			i;
}					t_complex;

typedef struct		s_point
{
	char			*e;
	double			x;
	double			y;
	double			x0;
	double			y0;
	double			x1;
	double			y1;
	double			x2;
	double			y2;
	double			zoom_x;
	double			zoom_y;
	float			scale;
	int				iter;
	int				color;
	int				rgb;
	float			frequency;
	int				key;
	int				save_color;
	int				x_move;
	int				y_move;
	t_complex		c;
	t_complex		z;
}					t_point;

typedef struct		s_fractol
{
	t_point			*pt;
	t_graph			*put;
}					t_fractol;

int					ft_error(void);
void				ft_win_2(t_graph *put);
int					key_event(int key, t_fractol *fractol);
void				move_fractol(t_graph *put, t_point *pt, t_fractol *fractol);
int					julia_move(int x, int y, t_fractol *fractol);
int					ft_move(int x, int y, t_fractol *fractol);
int					mouse_event(int key, int x, int y, t_fractol *fractol);
void				ft_init_model(t_graph *put, t_point *pt);
void				ft_same(t_graph *put, t_point *pt, t_fractol *fractol);
void				go_init(t_point *pt);
void				ft_mandel(t_point *pt);
void				ft_julia(t_point *pt);
void				ft_julia_2(t_point *pt);
void				ft_lapin(t_point *pt);
void				pixel(t_point *pt, t_graph *put, int x, int y);
void				psych(t_point *pt, t_graph *put, int x, int y);
void				ft_color(int key, t_graph *put, t_point *pt,
		t_fractol *fractol);
void				freq(int key, t_graph *put, t_point *pt,
		t_fractol *fractol);

#endif
