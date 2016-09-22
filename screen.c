#include "fractol.h"

int		event(int key)
{
	if (key == 53)
		exit(1);
	return (0);
}

void	create(t_graph *put, t_point *pt)
{
	int		key;
	int		i;
	double	tmp;
	double	zoom;
	double	nb;

	//-------------------------------Init_Var_Mandelbrot--------------------------------//|
	zoom = 500;																			//|
	pt->x0 = -2.1;																		//|
	pt->x1 = 0.6;																			//|
	pt->y0 = -1.2;																		//|
	pt->y1 = 1.2;																			//|
	pt->iter = 200;																		//|
	put->win_x = (pt->x1 - pt->x0) * zoom;
	put->win_y = (pt->y1 - pt->y0) * zoom;
	//-----------------------------------mlx--------------------------------------------//|
	put->mlx = mlx_init();																//|
	put->win = mlx_new_window(put->mlx, put->win_x, put->win_y, "fractol");				//|
	put->img = mlx_new_image(put->mlx, put->win_x, put->win_y);							//| ----zone iter img---//|
	put->data = mlx_get_data_addr(put->img, &put->bpp, &put->sizeline, &put->endian);	//|						//|
	pt->x = 0;																									//|
	while (pt->x < put->win_x)																					//|
	{																											//|
		pt->y = 0;																								//|
		while (pt->y < put->win_y)																				//|
		{																										//|
			pt->c.r = pt->x / zoom + pt->x0;																	//|
			pt->c.i = pt->y / zoom + pt->y0;
			pt->z.r = 0;
			pt->z.i = 0;
			i = 0;
			while (pt->z.i * pt->z.i + pt->z.r * pt->z.r < 4. && i < pt->iter)
			{
				tmp = pt->z.r;
				pt->z.r = pt->z.r * pt->z.r - pt->z.i * pt->z.i + pt->c.r;
				pt->z.i = 2. * pt->z.i * tmp + pt->c.i;
				i++;
			}
			pixel(pt, put, pt->x, pt->y,  i);
			pt->y++;																							//|
		}																										//|
		pt->x++;																								//|
	}																											//|
	//-----------------------------------mlx--------------------------------------------//|						//|
	mlx_put_image_to_window(put->mlx, put->win, put->img, 0, 0);						//|---------------------//|
	mlx_key_hook(put->win, event, 0);													//|
	mlx_loop(put->mlx);																	//|
}
