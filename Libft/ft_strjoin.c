/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axdubois <axdubois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 15:30:25 by axdubois          #+#    #+#             */
/*   Updated: 2023/11/08 14:32:13 by axdubois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;

	if (s1 == NULL || s2 == NULL)
		return (0);
	dest = ft_calloc((ft_strlen(s1) + ft_strlen(s2) + 1), sizeof(char));
	if (dest == NULL)
		return (NULL);
	ft_memcpy(dest, s1, ft_strlen(s1));
	ft_strlcat(dest, s2, (ft_strlen(s1) + ft_strlen(s2) + 1));
	return (dest);
}
