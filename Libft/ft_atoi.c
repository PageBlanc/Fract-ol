/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axdubois <axdubois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:34:31 by axdubois          #+#    #+#             */
/*   Updated: 2023/11/08 14:31:06 by axdubois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	signe;
	int	nb;

	i = 0;
	signe = 1;
	nb = 0;
	while ((nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13)) && nptr[i])
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			signe = -1;
		i++;
	}
	while (ft_isdigit(nptr[i]) && nptr[i])
	{
		nb = (nb * 10) + (nptr[i] - 48);
		i++;
	}
	return (nb * signe);
}
