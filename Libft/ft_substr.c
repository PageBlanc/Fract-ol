/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axdubois <axdubois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 14:20:09 by axdubois          #+#    #+#             */
/*   Updated: 2023/11/08 14:26:15 by axdubois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sf;

	if (!s)
		return (0);
	if (start >= ft_strlen(s))
		return ((char *)ft_calloc(1, 1));
	if (start + len > ft_strlen(s))
		len = ft_strlen(s) - start;
	sf = ft_calloc((len + 1), sizeof(char));
	if (sf == NULL)
		return (NULL);
	ft_strlcpy(sf, (&s[start]), len + 1);
	return (sf);
}
