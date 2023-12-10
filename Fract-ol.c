/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fract-ol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axdubois <axdubois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 20:23:39 by axdubois          #+#    #+#             */
/*   Updated: 2023/12/10 17:01:44 by axdubois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fract-ol.h"

void	put_pixel(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bbp / 8));
	*(unsigned int *)dst = color;
}

int	julia(t_fract *fract)
{
	double	zx;
	double	zy;
	double	xtemp;
	int		i;
	int		max;

	i = 0;
	max = 200;
	zx = (double)(fract->x) / fract->zoom + fract->panx;
	zx = ((zx / WIDTH - 0.5) * 4) * fract->ratio;
	zy = (double)(fract->y) / fract->zoom + fract->pany;
	zy = (zy / HEIGHT - 0.5) * 4;
	while (zx * zx + zy * zy < 4 && i++ < max)
	{
		xtemp = zx * zx - zy * zy;
		zy = 2 * zx * zy + fract->cx;
		zx = xtemp + fract->cy;
	}
	 if (i == max)
		return (0);
	else
		return (i);
}


long double mandelbrot(t_fract *fract)
{
 	double	zx;
 	double	zy;
 	double	xtemp;
 	long double		i;
 	long double		max;
	long double cx;
	long double cy;

 	i = 0;
 	max = 150;
 	zx = 0;
 	zy = 0;
	cx = (double)(fract->x) / fract->zoom + fract->panx;
	cx = ((cx / WIDTH - 0.5) * 2) * fract->ratio;
	cy = (double)(fract->y) / fract->zoom + fract->pany;
	cy = (cy / HEIGHT - 0.5) * 2;
 	while (zx * zx + zy * zy < 9 && i++ < max)
 	{
 		xtemp = zx * zx - zy * zy + cx;
		zy = 2 * zx * zy + cy;
		zx = xtemp;
 	}
 	if (i == max)
 	 	return (0);
 	else
 		return (i);
}

long double burningship(t_fract *fract)
{
 	double			zx;
 	double			zy;
 	double			xtemp;
 	long double		i;
 	long double		max;
	long double 	cx;
	long double 	cy;

 	i = 0;
 	max = 150;
 	zx = 0;
 	zy = 0;
	cx = (double)(fract->x) / fract->zoom + fract->panx;
	cx = ((cx / WIDTH - 0.5) * 2) * fract->ratio;
	cy = (double)(fract->y) / fract->zoom + fract->pany;
	cy = (cy / HEIGHT - 0.5) * 2;
 	while (zx * zx + zy * zy < 9 && i++ < max)
 	{
 		xtemp = fabs(zx * zx) - fabs(zy * zy) + cx;
		zy = 2 * fabs(zx * zy) + cy;
		zx = xtemp;
 	}
 	if (i == max)
 	 	return (0);
 	else
 		return (i);
}

t_data	print_fractol(t_fract *fract)
{
	int	i;
	
	fract->x = 0;
	while (fract->x++ < WIDTH)
	{
		fract->y = 0 ;
		while (fract->y++ < HEIGHT)
		{		
			if (fract->type == 'j')
				i = julia(fract);
			else if (fract->type == 'm')
				i = mandelbrot(fract);
			else if (fract->type == 'b')
				i = burningship(fract);
			put_pixel(&fract->img, fract->x, fract->y, get_color(fract, i));
		}
	}
	mlx_put_image_to_window(fract->img.mlx, \
	fract->img.win, fract->img.img, 0, 0);
	if (fract->multicolor)
		fract->color += cos(7/8) + tanl(sin(8/9) * 2);
	return (fract->img);
}

int	multiple_julia(t_fract *fract)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (fract->is_press)
	{
		mlx_mouse_get_pos(fract->img.mlx, fract->img.win, &x, &y);
		fract->cx = (double)((((double) x) / WIDTH - 0.5) * 2);
		fract->cy = (double)((((double) y) / HEIGHT - 0.5) * 2);
	}
	print_fractol(fract);
	return (1);
}

void	init_fractol(char *type, char *x, char *y)
{
	t_fract	fract;

	fract.type = type[0];
	fractval_init(&fract, x, y);
	fract.img.mlx = mlx_init();
	fract.img.win = mlx_new_window(fract.img.mlx, WIDTH, HEIGHT, type);
	fract.img.img = mlx_new_image(fract.img.mlx, WIDTH, HEIGHT);
	fract.img.addr = mlx_get_data_addr(fract.img.img, &fract.img.bbp, \
	&fract.img.line_length, &fract.img.endian);
	mlx_key_hook(fract.img.win, key_hook, &fract);
	mlx_mouse_hook(fract.img.win, mouse_hook, &fract);
	mlx_hook(fract.img.win, 17, 1L << 0, destroy, &fract.img);
	mlx_loop_hook(fract.img.mlx, multiple_julia, &fract);
	mlx_loop(fract.img.mlx);
	destroy(&fract.img);
}
int	main(int ac, char **av)
{
	if (ac == 4 && !ft_strncmp(av[1], "julia", 5))
		init_fractol(av[1], av[2], av[3]);
	else if (ac == 2 && !ft_strncmp(av[1], "mandelbrot", 10))
		init_fractol(av[1], "0", "0");
	else if (ac == 2 && !ft_strncmp(av[1], "burningship", 11))
		init_fractol(av[1], "0", "0");
	else
		return(0);
}
