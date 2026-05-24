/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fract_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axdubois <axdubois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 11:05:46 by axdubois          #+#    #+#             */
/*   Updated: 2026/05/24 13:08:07 by axdubois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fractol.h"

int key_hook(int keycode, t_fract *fract)
{
	double move = 50.0 / fract->zoom;
	if (keycode == 65307) // Escape key
		return (destroy(&fract->img));
	else if (keycode == 65363) // Right arrow key
		fract->panx += move;
	else if (keycode == 65361) // Left arrow key
		fract->panx -= move;
	else if (keycode == 65364) // Down arrow key
		fract->pany += move;
	else if (keycode == 65362) // Up arrow key
		fract->pany -= move;
	else if (keycode == 65451) // Plus key
		fract->color += 120;
	else if (keycode == 65453) // Minus key
		fract->color -= 120;
	else if (keycode == 65438) // Home key
		fract->color = 0;
	else if (keycode == 109) // 'm' key
		fract->multicolor = !fract->multicolor;
	print_fractol(fract);
	return (1);
}

void zoom(t_fract *fract, double factor, int x, int y)
{
	double world_x;
	double world_y;

	world_x = fract->panx + (x - WIDTH / 2.0) / fract->zoom;
	world_y = fract->pany + (y - HEIGHT / 2.0) / fract->zoom;

	fract->zoom *= factor;

	fract->panx = world_x - (x - WIDTH / 2.0) / fract->zoom;
	fract->pany = world_y - (y - HEIGHT / 2.0) / fract->zoom;
}

int mouse_hook(int mousecode, int x, int y, t_fract *fract)
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
		fract->panx += (double) x / 5;
		fract->pany += (double) y / 5;
	}
	print_fractol(fract);
	return (1);
}
