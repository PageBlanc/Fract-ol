/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axdubois <axdubois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 09:25:55 by axdubois          #+#    #+#             */
/*   Updated: 2023/11/08 14:24:12 by axdubois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*cal;

	if (nmemb == 0 || size == 0)
	{
		cal = malloc(1);
		if (cal == NULL)
			return (NULL);
		cal[0] = 0;
		return (cal);
	}
	if ((long long)nmemb < 0 || (long long)size < 0)
		return (NULL);
	cal = malloc(nmemb * size);
	if (cal == NULL)
		return (NULL);
	ft_bzero(cal, nmemb * size);
	return (cal);
}
