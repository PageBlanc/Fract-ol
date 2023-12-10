/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axdubois <axdubois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 22:47:12 by axdubois          #+#    #+#             */
/*   Updated: 2023/12/10 12:41:18 by axdubois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fract-ol.h"

int	ft_rgb(int r, int g, int b)
{
	g = ((g / 16) * ft_power(16, 3)) + (g % 16) * ft_power(16, 2);
	r = ((r / 16) * ft_power(16, 5)) + (r % 16) * ft_power(16, 4);
	return (r + g + b);
}

double	ft_atof(char *nbr)
{
	double	result;
	double	fraction;
	int		i;

	result = 0.0;
	fraction = 1.0;
	i = 0;
	if (nbr[i] == '-')
		i++;
	while (nbr[i] >= '0' && nbr[i] <= '9')
		result = result * 10.0 + (nbr[i++] - '0');
	if (nbr[i++] == '.')
	{
		while (nbr[i] >= '0' && nbr[i] <= '9')
		{
			fraction *= 0.1;
			result += (nbr[i++] - '0') * fraction;
		}
	}
	if (nbr[0] == '-')
		return (result * -1);
	return (result);
}

int	destroy(t_data *img)
{
	mlx_clear_window(img->mlx, img->win);
	mlx_destroy_image(img->mlx, img->img);
	mlx_destroy_window(img->mlx, img->win);
	mlx_destroy_display(img->mlx);
	mlx_loop_end(img->mlx);
	exit(EXIT_SUCCESS);
}

void	fractval_init(t_fract *fract, char *x, char *y)
{
	fract->is_press = 0;
	fract->zoom = 1;
	fract->cx = ft_atof(x);
	fract->cy = ft_atof(y);
	fract->ratio = WIDTH / HEIGHT;
	fract->panx = 0;
	fract->pany = 0;
	fract->color = 0;
	fract->multicolor = 0;
}