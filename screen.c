#include <stdlib.h>
#include <stdio.h>
#include "fractol.h"

int		event(int key)
{
	if (key == 53)
		exit(1);
	return (0);
}

void	create(t_graph *put/*, t_point *pt*/)
{
	int		key;

	put->win_x = 500;
	put->win_y = 500;
/*	pt->x0 = -2.1;
	pt->x1 = 0.6;
	pt->y0 = -1.2;
	pt->y1 = 1.2;
	pt->zoom = 100;
	put->win_x = ft_absolut((pt->x1 - pt->x0) * 100);
	put->win_y = ft_absolut((pt->y1 - pt->y0) * 100);
	printf("%d %d", put->win_x, put->win_y);*/
	put->mlx = mlx_init();
	put->win = mlx_new_window(put->mlx, put->win_x, put->win_y, "fractol");
	put->img = mlx_new_image(put->mlx, put->win_x, put->win_y);
	put->data = mlx_get_data_addr(put->img, &put->bpp, &put->sizeline, &put->endian);
/*	pt->init.r = pt->origin.r - put->win_x / 2 * pt->step.r;
	pt->init.i = pt->origin.i - put->win_y / 2 * pt->step.i;
	pt->x = 0;
	while (pt->x < put->win_x)
	{
		pt->y = 0;
		while (pt->y < put->win_y)
		{
			printf("x = %d, y = %d\n", pt->x, pt->y);
			tuto(pt, put);
			pt->y++;
		//	ft_mandelbrot(100, pt->z, pt->c);
		}
		pt->x++;
	}
	mlx_put_image_to_window(put->mlx, put->win, put->img, 0, 0);
	mlx_key_hook(put->win, event, 0);
	mlx_loop(put->mlx);*/
}
