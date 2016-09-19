#include "fractol.h"

void		frac(t_graph *put)
{
	float		K;
	double pr, pi;           //real and imaginary part of the pixel p
	double newRe, newIm, oldRe, oldIm;   //real and imaginary parts of new and old z
	double zoom = 1, moveX = -0.5, moveY = 0; //you can change these to zoom and change position
//	ColorRGB color; //the RGB color value for the pixel
	int maxIterations = 300;//after how much iterations the function should stop
		for(int y = 0; y < put->win_y; y++)
		{
			for(int x = 0; x < put->win_x; x++)
   			{
				pr = 1.5 * (x - put->win_x / 2) / (0.5 * zoom * put->win_x) + moveX;
				pi = (y - put->win_y / 2) / (0.5 * zoom * put->win_y) + moveY;
				newRe = newIm = oldRe = oldIm = 0;
				int i;
				for(i = 0; i < maxIterations; i++)
				{
					oldRe = newRe;
					oldIm = newIm;
					newRe = oldRe * oldRe - oldIm * oldIm + pr;
					newIm = 2 * oldRe * oldIm + pi;
					K = newRe * newRe + newIm * newIm;
					printf("%f   ", K);
					if((newRe * newRe + newIm * newIm) > 4) break;
				}
				pixel(put, x, y);
//				color = HSVtoRGB(ColorHSV(i % 256, 255, 255 * (i < maxIterations)));
//				pset(x, y, color);
			}
//		redraw();
//		sleep();
	mlx_put_image_to_window(put->mlx, put->win, put->img, 0, 0);
	mlx_key_hook(put->win, event, 0);
	mlx_loop(put->mlx);
	}
}

int main(int argc, char *argv[])
{
	t_graph put;

	create(&put);
//	screen(400, 300, 0, "Mandelbrot Set"); //make larger to see more detail!
	frac(&put);
	return (0);
}
