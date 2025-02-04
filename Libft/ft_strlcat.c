/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axdubois <axdubois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 10:43:05 by axdubois          #+#    #+#             */
/*   Updated: 2023/11/08 14:35:31 by axdubois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	d_len;
	size_t	s_len;

	if (dst == NULL && size == 0)
		return (0);
	d_len = ft_strlen(dst);
	s_len = ft_strlen(src);
	if (size == 0)
		return (s_len);
	i = 0;
	if (size < d_len)
		return (s_len + size);
	while (src[i] && (d_len + i) < (size - 1))
	{
		dst[d_len + i] = src[i];
		i++;
	}
	dst[d_len + i] = 0;
	return (s_len + d_len);
}
