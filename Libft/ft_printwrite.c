/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printwrite.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axdubois <axdubois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 11:26:39 by axdubois          #+#    #+#             */
/*   Updated: 2023/12/02 20:11:08 by axdubois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (ft_putstr("(null)"));
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
	return (i);
}

int	ft_is_error_base(char *base)
{
	int	i;

	if (base[0] == 0)
		return (1);
	if (base[1] == 0)
		return (1);
	i = 0;
	while (base[i +1])
	{
		if (base[i] == base[i +1] || base[i] == '+' || base[i] == '-')
			return (1);
		i++;
	}
	return (0);
}

int	ft_putnbr_base(long long nbr, char *base)
{
	int	res;

	res = 0;
	if (ft_is_error_base(base))
		return (res);
	if (nbr < 0)
	{
		res += ft_putchar('-');
		nbr *= -1;
	}
	if (nbr < (long long)ft_strlen(base))
		res += ft_putchar(base[nbr]);
	else
	{
		res += ft_putnbr_base(nbr / ft_strlen(base), base);
		res += ft_putnbr_base(nbr % ft_strlen(base), base);
	}
	return (res);
}

int	ft_putnbr_ubase(unsigned long long nbr, char *base)
{
	int			res;

	res = 0;
	if (ft_is_error_base(base))
		return (res);
	if (nbr < (unsigned long long)ft_strlen(base))
		res += ft_putchar(base[nbr]);
	else
	{
		res += ft_putnbr_base(nbr / ft_strlen(base), base);
		res += ft_putnbr_base(nbr % ft_strlen(base), base);
	}
	return (res);
}
