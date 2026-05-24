/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axdubois <axdubois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 09:53:31 by axdubois          #+#    #+#             */
/*   Updated: 2026/05/24 14:22:33 by axdubois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fractol.h"

int destroy(t_data *img)
{
	mlx_clear_window(img->mlx, img->win);
	mlx_destroy_image(img->mlx, img->img);
	mlx_destroy_window(img->mlx, img->win);
	mlx_destroy_display(img->mlx);
	mlx_loop_end(img->mlx);
	free(img->mlx);
	exit(EXIT_SUCCESS);
}

void put_pixel(t_data *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->line_length + x * (data->bbp / 8));
	*(unsigned int *) dst = color;
}

int (*choice_func(char type))(double, double, int, double, double)
{
	if (type == 'j')
		return (julia);
	else if (type == 'm')
		return (mandelbrot);
	else if (type == 'b')
		return (burningship);
	return (NULL);
}

t_data print_fractol(t_fract *fract)
{
	int max_iter = 500;
	int (*func)(double, double, int, double, double) = choice_func(fract->type);
	if (!func)
		return (fract->img);
	else if (fract->type == 'j')
	{
		fract->c_re = fract->cx;
		fract->c_im = fract->cy;
	}
	double scale_x = 1.0 / fract->zoom;
	double scale_y = 1.0 / fract->zoom;

	double cy = fract->pany - (HEIGHT / 2.0) * scale_y;
	fract->y = 0;
	while (fract->y < HEIGHT)
	{
		double cx = fract->panx - (WIDTH / 2.0) * scale_x;
		fract->x = 0;
		while (fract->x < WIDTH)
		{
			int iteration = func(cx, cy, max_iter, fract->c_re, fract->c_im);
			put_pixel(
				&fract->img, fract->x, fract->y, get_color(fract, iteration)
			);
			cx += scale_x;
			fract->x++;
		}
		cy += scale_y;
		fract->y++;
	}
	mlx_put_image_to_window(
		fract->img.mlx, fract->img.win, fract->img.img, 0, 0
	);
	fract->need_redraw = false;
	// if (fract->multicolor)
	//  fract->color += (int){cos(7 / 8) + tanl(sin(8 / 9) * 2)};
	return (fract->img);
}

void init_fractol(char *type, char *x, char *y)
{
	t_fract fract;

	fract.type = type[0];
	fractval_init(&fract, x, y);
	fract.img.mlx = mlx_init();
	fract.img.win = mlx_new_window(fract.img.mlx, WIDTH, HEIGHT, type);
	fract.img.img = mlx_new_image(fract.img.mlx, WIDTH, HEIGHT);
	fract.img.addr = mlx_get_data_addr(
		fract.img.img, &fract.img.bbp, &fract.img.line_length, &fract.img.endian
	);
	mlx_key_hook(fract.img.win, (int (*)())(void *)key_hook, &fract);
	mlx_mouse_hook(fract.img.win, (int (*)())(void *)mouse_hook, &fract);
	mlx_hook(fract.img.win, 17, 1L << 0, (int (*)())(void *)destroy, &fract.img);
	mlx_loop_hook(fract.img.mlx, (int (*)())(void *)lauch_fractol, &fract);
	mlx_loop(fract.img.mlx);
	destroy(&fract.img);
}
