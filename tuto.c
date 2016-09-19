#include "fractol.h"
#include <stdio.h>

/*void	make(t_point *pt, t_graph *put)
  {
  pt->x0 = -2,1;
  pt->x1 = 0,6;
  pt->y0 = -1,2;
  pt->y1 = 1,2;
  pt->zoom_x = put->win_x / (pt->x1 - pt->x0);
  pt->zoom_y = put->win_y / (pt->y1 - pt->y0);
  }*/

void    pixel(/*t_point *pt,*/ t_graph *put, int x, int y)
{
	int color1;
	int	color;

//	color = 0x00ff00;
	color1 = mlx_get_color_value(put->mlx, 0x00ff00);
	if (1 <= x && x <= put->win_x && 1 <= y && y <= put->win_y)
	{
		(put->data + y * put->sizeline + 4 * x)[0] = color1 >> 16;
		(put->data + y * put->sizeline + 4 * x)[1] = color1 >> 8;
		(put->data + y * put->sizeline + 4 * x)[2] = color1;
	}
}

/*int		tuto(t_point *pt, t_graph *put)
{
	int		i;
	float	nb;
	int		tmp;

	pt->c.r = pt->x / pt->zoom + pt->x1;
	pt->c.i = pt->y / pt->zoom + pt->y1;
	pt->z.r = 0;
	pt->z.i = 0;
	i = 0;

	while (pt->z.r * pt->z.r + pt->z.i * pt->z.i < 4 && i < pt->iter)
	{
		nb = pt->z.r * pt->z.r + pt->z.i * pt->z.i;
		if (nb > 0)
			printf("nb = %f, i = %d\n", nb, i);
//		pixel(pt, put, pt->x0, pt->y0);
		tmp = pt->z.r;
		pt->z.r = pt->z.r * pt->z.r - pt->z.i * pt->z.i + pt->c.r;
		pt->z.i = 2 * pt->z.i * tmp + pt->c.i;
		i++;
	}
	if (i == pt->iter)
		pixel(pt, put, pt->x, pt->y);
	return (i);
}

int		main(void)
{
	t_point	pt;
	t_graph put;

	printf("main");
	pt.color = 0xffffff;
	pt.iter = 50;
	create(&put, &pt);
	return (0);
}*/
/*
définir x1 = -2.1
définir x2 = 0.6
définir y1 = -1.2
définir y2 = 1.2
définir zoom = 100 // pour une distance de 1 sur le plan, on a 100 pixel sur l'image
définir iteration_max = 50

définir image_x = (x2 - x1) * zoom
définir image_y = (y2 - y1) * zoom

Pour x = 0 tant que x < image_x par pas de 1 
Pour y = 0 tant que y < image_y par pas de 1
définir c_r = x / zoom + x1
définir c_i = y / zoom + y1
définir z_r = 0
définir z_i = 0
définir i = 0

Faire
définir tmp = z_r
z_r = z_r*z_r - z_i*z_i + c_r
z_i = 2*z_i*tmp + c_i
i = i+1
Tant que z_r*z_r + z_i*z_i < 4 et i < iteration_max

si i = iteration_max
dessiner le pixel de coordonné (x; y)
finSi
finPour
finPour
*/


/*
   - On defini la zone que l'on dessine, ici la fractale est entiere
   définir x1 = -2.1
   définir x2 = 0.6
   définir y1 = -1.2
   définir y2 = 1.2
   définir image_x = 270
   définir image_y = 240
   définir iteration_max = 50

   - On calcule la taille de l'image :
   définir zoom_x = image_x/(x2 - x1)
   définir zoom_y = image_y/(y2 - y1)

   Pour x = 0 tant que x < image_x par pas de 1
   Pour y = 0 tant que y < image_y par pas de 1
   définir c_r = x / zoom_x + x1
   définir c_i = y / zoom_y + y1
   définir z_r = 0
   définir z_i = 0
   définir i = 0

   Faire
   définir tmp = z_r
   z_r = z_r*z_r - z_i*z_i + c_r
   z_i = 2*z_i*tmp + c_i
   i = i+1
   Tant que z_r*z_r + z_i*z_i < 4 et i < iteration_max

   si i = iteration_max
   dessiner le pixel de coordonné (x; y)
   finSi
   finPour
   finPour
   */

/*
   - définir iteration_max = 50

   - Pour chaque point de coordonnées (x; y) du plan :
   définir c_r = x;
   définir c_i = y;
   définir z_r = 0
   définir z_i = 0
   définir i = 0

   - Faire
   définir tmp = z_r
   z_r = z_r*z_r - z_i*z_i + c_r
   z_i = 2*z_i*tmp + c_i
   i = i+1
   Tant que z_r*z_r + z_i*z_i < 4 et i < iteration_max

   - Si i = iteration_max
   dessiner le pixel correspondant au point de coordonné (x; y)
   finSi
   finPour
   */
