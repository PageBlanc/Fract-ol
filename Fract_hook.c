/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fract_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axdubois <axdubois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 11:05:46 by axdubois          #+#    #+#             */
/*   Updated: 2023/12/11 10:43:06 by axdubois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fractol.h"

int	key_hook(int keycode, t_fract *fract)
{
	if (keycode == 65307)
		return (destroy(&fract->img));
	else if (keycode == 65363)
		fract->panx += 50 / fract->zoom;
	else if (keycode == 65361)
		fract->panx -= 50 / fract->zoom;
	else if (keycode == 65364)
		fract->pany += 50 / fract->zoom;
	else if (keycode == 65362)
		fract->pany -= 50 / fract->zoom;
	else if (keycode == 65451)
		fract->color += 120;
	else if (keycode == 65453)
		fract->color -= 120;
	else if (keycode == 65438)
		fract->color = 0;
	else if (keycode == 109)
		fract->multicolor = !fract->multicolor;
	print_fractol(fract);
	return (1);
}

void	zoom(t_fract *fract, double z_factor, int x, int y)
{
	fract->panx = ((double)x / fract->zoom + fract->panx) - \
	((double)x / (fract->zoom * z_factor));
	fract->pany = ((double)y / fract->zoom + fract->pany) - \
	((double)y / (fract->zoom * z_factor));
	fract->zoom *= z_factor;
}

int	mouse_hook(int mousecode, int x, int y, t_fract *fract)
{
	mlx_mouse_get_pos(fract->img.mlx, fract->img.win, &x, &y);
	if (mousecode == 4)
		zoom(fract, 1.5, x, y);
	else if (mousecode == 5)
		zoom(fract, 0.5, x, y);
	else if (mousecode == 1)
		fract->is_press = !fract->is_press;
	else if (mousecode == 3)
	{
		if (x < WIDTH / 2)
			x *= -1;
		if (y < HEIGHT / 2)
			y *= -1;
		fract->panx += (double)x / 5;
		fract->pany += (double)y / 5;
	}
	print_fractol(fract);
	return (1);
}
