/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fract-ol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axdubois <axdubois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 20:23:39 by axdubois          #+#    #+#             */
/*   Updated: 2026/05/24 13:30:48 by axdubois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fractol.h"

int julia(double zx, double zy, int max_iter, double cr, double ci)
{
	double zx2 = 0.0;
	double zy2 = 0.0;
	int i = 0;

	// Iterate the function z = z^2 + c
	while (i < max_iter)
	{
		// Update zx2 and zy2 for the next iteration
		zx2 = zx * zx;
		zy2 = zy * zy;
		if (zx2 + zy2 > 4.0)
			break;
		// Calculate the next iteration of z
		zy = 2.0 * zx * zy + ci;
		zx = zx2 - zy2 + cr;

		i++;
	}
	return (i == max_iter) ? -1 : i;
}

int mandelbrot(double cx, double cy, int max_iter, double c_re, double c_im)
{
	(void)c_re; // Unused parameter
	(void)c_im; // Unused parameter

	double zx = 0.0;
	double zy = 0.0;
	double zx2 = 0.0;
	double zy2 = 0.0;
	double tmp = 0.0;
	int i = 0;

	// Iterate the function z = z^2 + c
	while (zx2 + zy2 < 4.0 && i < max_iter)
	{
		// Calculate the next iteration of z
		tmp = zx2 - zy2 + cx;
		zy = 2.0 * zx * zy + cy;
		zx = tmp;
		// Update zx2 and zy2 for the next iteration
		zx2 = zx * zx;
		zy2 = zy * zy;
		i++;
	}
	return (i == max_iter) ? -1 : i;
}

int burningship(double cx, double cy, int max_iter, double c_re, double c_im)
{
	(void)c_re; // Unused parameter
	(void)c_im; // Unused parameter

	double zx = 0.0;
	double zy = 0.0;
	double zx2 = 0.0;
	double zy2 = 0.0;
	double tmp = 0.0;
	int i = 0;

	// Iterate the function z = (|Re(z)| + i|Im(z)|)^2 + c
	while (i < max_iter)
	{
		// Calculate the next iteration of z
		zx2 = zx * zx;
		zy2 = zy * zy;
		if (zx2 + zy2 > 4.0)
			break;

		// Update zx and zy with absolute values
		tmp = zx2 - zy2 + cx;
		zy = fabs(2.0 * zx * zy) + cy;
		zx = fabs(tmp);

		i++;
	}
	return (i == max_iter) ? -1 : i;
}

int multiple_julia(t_fract *fract)
{
	int x;
	int y;

	x = 0;
	y = 0;
	if (fract->is_press)
	{
		mlx_mouse_get_pos(fract->img.mlx, fract->img.win, &x, &y);
		fract->cx = (double) ((((double) x) / WIDTH - 0.5) * 2);
		fract->cy = (double) ((((double) y) / HEIGHT - 0.5) * 2);
	}
	print_fractol(fract);
	return (1);
}

int main(int ac, char **av)
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
