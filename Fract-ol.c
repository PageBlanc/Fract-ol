/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fract-ol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axdubois <axdubois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 20:23:39 by axdubois          #+#    #+#             */
/*   Updated: 2023/12/07 14:23:42 by axdubois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"Fract-ol.h"


int    destroy(t_data *img)
{
    mlx_clear_window(img->mlx, img->win);
    mlx_destroy_image(img->mlx,img->img);
    mlx_destroy_window(img->mlx, img->win);
    mlx_destroy_display(img->mlx);
    mlx_loop_end(img->mlx);
    exit(EXIT_SUCCESS);
    return (0);
}

void	put_pixel(t_data *data, int x, int y, int color)
{
	char	*dst;
	
	dst = data->addr + (y * data->line_length + x * (data->bbp / 8));
	*(unsigned int*)dst = color;
}

int ft_rgb(int r, int g, int b)
{
	g = ((g / 16) * ft_power(16, 3)) + (g % 16) * ft_power(16, 2);
	r = ((r / 16) * ft_power(16, 5)) + (r % 16) * ft_power(16, 4);
	return (r + g + b);
}

int julia(f_fract *fract)
{
	double zx;
	double zy;
	double xtemp;
	int i = 0;
	int max =250;

	zx = (double)(fract->x) / fract->zoom + fract->panx;
	zx = ((zx / WIDTH - 0.5) * 4 ) * fract->ratio;
	zy = (double)(fract->y) / fract->zoom + fract->pany;
	zy = (zy / HEIGHT - 0.5) * 4;
	while (zx * zx + zy * zy < 4  &&  i < max)
	{
		xtemp = zx * zx - zy * zy;
        zy = 2 * zx * zy  + fract->cy;
        zx = xtemp + fract->cx;
		i++;
	}
	if (i == max)
        return 0;
    else
        return i;
}

t_data print_fractol(f_fract *fract)
{
	int i;
	
	fract->x = 0;
	while (fract->x < WIDTH)
	{
		fract->y = 0 ;
		while (fract->y < HEIGHT)
		{
			i = julia(fract);
			//  if (i == 0)
			//  	put_pixel(&fract->img, fract->x, fract->y,ft_rgb(57,0,0));
			// else
				put_pixel(&fract->img, fract->x, fract->y,ft_rgb(i, i, i) + (i) * ((fract->x + fract->y) / (fract->cx + fract->cy)));/// - 1 * (fract->cx + fract->cy));
			fract->y++;
	 	}
	 	fract->x++;
	}
	mlx_put_image_to_window(fract->img.mlx, fract->img.win, fract->img.img,0, 0);
	return fract->img;
}


int multiple_julia(f_fract *fract)
{
	int x = 0;
	int y = 0;
	if (fract->is_press)
	{
		mlx_mouse_get_pos(fract->img.mlx, fract->img.win, &x, &y);
		fract->cx = (double)((((double) x) / WIDTH - 0.5) * 2);
		fract->cy = (double)((((double) y) / HEIGHT - 0.5) * 2);
	}
	print_fractol(fract);
	return  1;
}

void fract_init(f_fract *fract)
{
	fract->is_press = 1;
	fract->zoom = 1;
	fract->cx = 0;
	fract->cy = 0;
	fract->ratio = WIDTH / HEIGHT;
	fract->panx = 0;
	fract->pany = 0;
}

int	main(int ac, char **av)
{
	f_fract fract;
	
	fract_init(&fract);
	fract.img.mlx = mlx_init();
	fract.img.win = mlx_new_window(fract.img.mlx, WIDTH, HEIGHT, "Fract-ol!");
	fract.img.img = mlx_new_image(fract.img.mlx, WIDTH, HEIGHT);
	fract.img.addr = mlx_get_data_addr(fract.img.img, &fract.img.bbp, &fract.img.line_length, &fract.img.endian);
	mlx_key_hook(fract.img.win, key_hook, &fract);
	mlx_mouse_hook(fract.img.win, mouse_hook, &fract);
	mlx_hook(fract.img.win, 17, 1L<<0, destroy, &fract.img);
	mlx_loop_hook(fract.img.mlx, multiple_julia , &fract);
	mlx_loop(fract.img.mlx);
	destroy(&fract.img);
}