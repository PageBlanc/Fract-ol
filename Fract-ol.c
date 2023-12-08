/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fract-ol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axdubois <axdubois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 20:23:39 by axdubois          #+#    #+#             */
/*   Updated: 2023/12/08 23:24:02 by axdubois         ###   ########.fr       */
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
		zy = 2 * zx * zy + fract->cy;
		zx = xtemp + fract->cx;
	}
	if (i == max)
	 	return (0);
	else
		return (i);
}

int mandelbrot(t_fract *fract)
{
	double	zx;
	double	zy;
	double	xtemp;
	int		i;
	int		max;

	i = 0;
	max = 200;
	zx = 0;
	zy = 0;
	while (zx * zx + zy * zy < 4 && i++ < max)
	{
		xtemp = zx * zx - zy * zy;
		zy = 2 * zx * zy + fract->cy;
		zx = xtemp + fract->cx;
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
			i = julia(fract);
			put_pixel(&fract->img, fract->x, fract->y, ft_rgb(i, i, i) + \
			(i / -1 * (fract->cx + fract->color + fract->cy)) / 10);
		}
	}
	mlx_put_image_to_window(fract->img.mlx, \
	fract->img.win, fract->img.img, 0, 0);
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
	if (fract.type == )
	mlx_loop_hook(fract.img.mlx, multiple_julia, &fract);
	mlx_loop(fract.img.mlx);
	destroy(&fract.img);
}
int	main(int ac, char **av)
{
	if (!ft_strncmp(av[1], "julia", 5) && ac == 4)
		init_fractol(av[1], av[2], av[3]);
	else if (!ft_strncmp(av[1], "mandelbrot", 10) && ac == 2)
		init_fractol(av[1], "0", "0");
	// else if (ft_strncmp(fract.type, "burningship", 11) && ac == 2)
}
