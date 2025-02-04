/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axdubois <axdubois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 10:52:13 by axdubois          #+#    #+#             */
/*   Updated: 2023/11/08 14:26:36 by axdubois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*cpy;
	int		len;

	len = ft_strlen(s) + 1;
	cpy = (char *) malloc(len * sizeof(char));
	if (cpy == NULL)
		return (NULL);
	ft_strlcpy(cpy, s, len);
	return (cpy);
}
