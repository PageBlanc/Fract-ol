/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axdubois <axdubois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 23:15:14 by axdubois          #+#    #+#             */
/*   Updated: 2023/12/11 10:44:47 by axdubois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WIDTH 1000
# define HEIGHT 1000

# include "Libft/libft.h"
# include "mlx/mlx.h"
# include <math.h>
# include <stdio.h>

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bbp;
	int		line_length;
	int		endian;
	void	*win;
	void	*mlx;
}				t_data;

typedef struct f_fract{
	t_data	img;
	double	zoom;
	int		is_press;
	int		x;
	int		y;
	double	cx;
	double	cy;
	double	ratio;
	double	panx;
	double	pany;
	double	color;
	char	type;
	int		multicolor;
}				t_fract;

int		key_hook(int keycode, t_fract *fract);
int		mouse_hook(int mousecode, int x, int y, t_fract *fract);
int		destroy(t_data *img);
int		multiple_julia(t_fract *fract);
t_data	print_fractol(t_fract *fract);
int		ft_rgb(int r, int g, int b);
double	ft_atof(char *nbr);
int		destroy(t_data *img);
void	fractval_init(t_fract *fract, char *x, char *y);
int		get_color(t_fract *fract, int i);
void	put_pixel(t_data *data, int x, int y, int color);
double	julia(t_fract *fract);
double	mandelbrot(t_fract *fract);
double	burningship(t_fract *fract);
void	init_fractol(char *type, char *x, char *y);

#endif
