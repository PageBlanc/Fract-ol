/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axdubois <axdubois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 23:15:14 by axdubois          #+#    #+#             */
/*   Updated: 2026/05/24 17:07:30 by axdubois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
#define FRACTOL_H

#define WIDTH 1000
#define HEIGHT 1000
#define DEBUG_PERF 0

#include "Libft/libft.h"
#include "mlx/mlx.h"
#include <math.h>
#include <time.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct s_data
{
	void *img;
	char *addr;
	int bbp;
	int line_length;
	int endian;
	void *win;
	void *mlx;
} t_data;

typedef struct f_fract
{
	t_data img;
	double zoom;
	double cx;
	double cy;
	double ratio;
	double panx;
	double pany;
	double c_re;
	double c_im;
	int x;
	int y;
	int color;
	int multicolor;
	char type;
	bool is_press;
	bool need_redraw;
} t_fract;

t_data print_fractol(t_fract *fract);
void fractval_init(t_fract *fract, char *x, char *y);
void put_pixel(t_data *data, int x, int y, int color);
void init_fractol(char *type, char *x, char *y);
double ft_atof(char *nbr);
int key_hook(int keycode, t_fract *fract);
int mouse_hook(int mousecode, int x, int y, t_fract *fract);
int destroy(t_data *img);
int lauch_fractol(t_fract *fract);
int ft_rgb(int r, int g, int b);
int get_color(t_fract *fract, int i);
int mandelbrot(double cx, double cy, int max, double c_re, double c_im);
int julia(double cx, double cy, int max, double c_re, double c_im);
int burningship(double cx, double cy, int max, double c_re, double c_im);

#endif
