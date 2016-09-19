#include <math.h>
#include <stdio.h>
#include "fractol.h"

int		ft_mandelbrot(int iter_max, t_complex z, t_complex c)
{
	t_complex		tmp;
	int				i;
	float			x;


	tmp.r = 0;
	tmp.i = 0;
	i = 0;
	while (i < iter_max && (tmp.r * tmp.r - tmp.i * tmp.i) < 4)
	{
		i++;
		x = tmp.r;
		tmp.r = tmp.r * tmp.r - tmp.i * tmp.i + c.r;
		tmp.i = (2 * x * tmp.i) + c.i;
	}
	return (i);
}

int		main(void)
{
	t_point	*pt;
	t_graph	*put;
	int		iter_max;

	//r|i de origin, step, init
	pt->origin.r = -0.8;
	pt->origin.i = 0;
	pt->step.r = 0.007;
	pt->step.i = 0.007;
	pt->z.r = 0;
	pt->z.i = 0;
	pt->c.r = 0;
	pt->c.i = 0;
	create(put, pt);
//	pt->init.r = pt->origin.r - put->win_x / 2 * pt->step.r;
//	pt->init.i = pt->origin.i - put->win_y / 2 * pt->step.i;
//	ft_mandelbrot(100, pt->z, pt->c);

	return (0);
}
