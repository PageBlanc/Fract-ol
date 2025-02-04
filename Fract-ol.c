/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fract-ol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axdubois <axdubois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 20:23:39 by axdubois          #+#    #+#             */
/*   Updated: 2025/02/04 13:42:18 by axdubois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fractol.h"

double	julia(t_fract *fract)
{
	double	zx;
	double	zy;
	double	xtemp;
	double	i;
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
		return (-1);
	else
		return (i);
}

double	mandelbrot(t_fract *fract)
{
	double	zx;
	double	zy;
	double	xtemp;
	double	i;
	double	max;

	i = 0;
	max = 200;
	zx = 0;
	zy = 0;
	fract->cx = (double)(fract->x) / fract->zoom + fract->panx;
	fract->cx = ((fract->cx / WIDTH - 0.5) * 2) * fract->ratio;
	fract->cy = (double)(fract->y) / fract->zoom + fract->pany;
	fract->cy = (fract->cy / HEIGHT - 0.5) * 2;
	while (zx * zx + zy * zy < 9 && i++ < max)
	{
		xtemp = zx * zx - zy * zy + fract->cx;
		zy = 2 * zx * zy + fract->cy;
		zx = xtemp;
	}
	if (i == max)
		return (-1);
	else
		return (i);
}

double	burningship(t_fract *fract)
{
	double	zx;
	double	zy;
	double	xtemp;
	double	i;
	double	max;

	i = 0;
	max = 200;
	zx = 0;
	zy = 0;
	fract->cx = (double)(fract->x) / fract->zoom + fract->panx;
	fract->cx = ((fract->cx / WIDTH - 0.5) * 2) * fract->ratio;
	fract->cy = (double)(fract->y) / fract->zoom + fract->pany;
	fract->cy = (fract->cy / HEIGHT - 0.5) * 2;
	while (zx * zx + zy * zy < 9 && i++ < max)
	{
		xtemp = fabs(zx * zx) - fabs(zy * zy) + fract->cx;
		zy = 2 * fabs(zx * zy) + fract->cy;
		zx = xtemp;
	}
	if (i == max)
		return (-1);
	else
		return (i);
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

int	main(int ac, char **av)
{
	if (ac == 4 && !ft_strncmp(av[1], "julia", 5))
		init_fractol(av[1], av[2], av[3]);
	else if (ac == 2 && !ft_strncmp(av[1], "mandelbrot", 10))
		init_fractol(av[1], "0", "0");
	else if (ac == 2 && !ft_strncmp(av[1], "burningship", 11))
		init_fractol(av[1], "0", "0");
	else
	{
		ft_printf("1 -julia x y\n");
		ft_printf("2 -mandelbrot\n");
		ft_printf("3 -burningship\n");
	}
	return (0);
}
