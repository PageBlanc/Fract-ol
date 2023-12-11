/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axdubois <axdubois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 09:53:31 by axdubois          #+#    #+#             */
/*   Updated: 2023/12/11 10:44:20 by axdubois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fractol.h"

int	destroy(t_data *img)
{
	mlx_clear_window(img->mlx, img->win);
	mlx_destroy_image(img->mlx, img->img);
	mlx_destroy_window(img->mlx, img->win);
	mlx_destroy_display(img->mlx);
	mlx_loop_end(img->mlx);
	free(img->mlx);
	exit(EXIT_SUCCESS);
}

void	put_pixel(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bbp / 8));
	*(unsigned int *)dst = color;
}

double	fractol_choice(t_fract *fract, double i)
{
	if (fract->type == 'j')
		return (julia(fract));
	else if (fract->type == 'm')
		return (mandelbrot(fract));
	else if (fract->type == 'b')
		return (burningship(fract));
	return (0);
}

t_data	print_fractol(t_fract *fract)
{
	double	i;

	fract->x = 0;
	i = 0;
	while (fract->x++ < WIDTH)
	{
		fract->y = 0 ;
		while (fract->y++ < HEIGHT)
		{
			i = fractol_choice(fract, i);
			put_pixel(&fract->img, fract->x, fract->y, get_color(fract, i));
		}
	}
	mlx_put_image_to_window(fract->img.mlx, \
	fract->img.win, fract->img.img, 0, 0);
	if (fract->multicolor)
		fract->color += cos(7 / 8) + tanl(sin(8 / 9) * 2);
	return (fract->img);
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
