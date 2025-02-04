/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axdubois <axdubois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 13:51:00 by axdubois          #+#    #+#             */
/*   Updated: 2023/11/08 14:19:11 by axdubois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_in(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	start;
	size_t	end;
	char	*s2;

	if (s1 == 0 || set == 0)
		return (NULL);
	start = 0;
	end = ft_strlen(s1) -1;
	while (ft_in(set, s1[start]) && s1[start])
		start++;
	if (!s1[start])
		return (ft_calloc(1, 1));
	while (ft_in(set, s1[end]) && end)
		end--;
	s2 = ft_calloc((end - start) + 2, sizeof(char));
	if (s2 == NULL)
		return (NULL);
	i = 0;
	while (s1[i] && i <= end - start)
	{
		s2[i] = s1[start + i];
		i++;
	}
	return (s2);
}
