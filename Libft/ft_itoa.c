/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axdubois <axdubois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 08:18:40 by axdubois          #+#    #+#             */
/*   Updated: 2023/11/08 14:28:34 by axdubois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_cdecimal(long int n)
{
	int	d;

	d = 0;
	while (n)
	{
		d++;
		n /= 10;
	}
	return (d);
}

static	char	*ft_tochard(char *res, long int n, int s, int len)
{
	if (s == 1)
		res[0] = '-';
	res[len] = 0;
	while (n)
	{
		res[len - 1] = (n % 10) + 48;
		len--;
		n /= 10;
	}
	return (res);
}

char	*ft_itoa(int n)
{
	char		*res;
	int			len;
	int			s;
	long int	nbr;

	nbr = n;
	s = 0;
	if (nbr < 0)
	{
		s++;
		nbr *= -1;
	}
	len = ft_cdecimal(nbr) + s;
	if (nbr == 0)
		len++;
	res = ft_calloc(len + 1, sizeof(char));
	if (res == NULL)
		return (NULL);
	if (n == 0)
	{
		res[0] = '0';
		return (res);
	}
	return (ft_tochard(res, nbr, s, len));
}
