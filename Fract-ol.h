/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fract-ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axdubois <axdubois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 23:15:14 by axdubois          #+#    #+#             */
/*   Updated: 2023/12/06 23:46:16 by axdubois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H

# define WIDTH 1000
# define HEIGHT 1000

#include "Libft/libft.h"
#include	"mlx/mlx.h"
#include <math.h>
#include <stdio.h>


typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bbp;
	int		line_length;
	int		endian;
	void	*win;
	void	*mlx;
}				t_data;

typedef struct f_fract {
	t_data img;
	double zoom;
	int is_press;
	int x;
	int y;
	double cx;
	double cy;
	double ratio;
	double panx;
	double pany;
}				f_fract;

int		key_hook(int keycode, f_fract *fract);
int 	mouse_hook(int mousecode,int x, int y, f_fract *fract);
int		destroy(t_data *img);
int		multiple_julia(f_fract *fract);
t_data 	print_fractol(f_fract *fract);



#endif