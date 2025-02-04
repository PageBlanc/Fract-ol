/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axdubois <axdubois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 16:45:24 by axdubois          #+#    #+#             */
/*   Updated: 2023/11/08 14:35:04 by axdubois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_cword(const char *s, char c)
{
	size_t	i;
	size_t	cword;

	i = 0;
	cword = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			cword++;
		i++;
	}
	return (cword);
}

static size_t	ft_lword(const char *s, char c, size_t i)
{
	size_t	lword;

	lword = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (lword);
		i++;
		lword++;
	}
	return (lword);
}

static char	**ft_freeall(char **bigtab, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		free(bigtab[n]);
		i++;
	}
	free(bigtab);
	return (bigtab);
}

static char	**ft_fillbigtab(char **bigtab, size_t n, char const *s, char c)
{
	size_t	i;

	i = 0;
	while (i < ft_strlen(s) && s[i])
	{
		if (s[i] != c)
		{
			bigtab[n] = ft_substr(s, i, ft_lword(s, c, i));
			if (bigtab[n] == NULL)
			{
				bigtab = ft_freeall(bigtab, n);
				return (NULL);
			}
			i += ft_strlen(bigtab[n]);
			n++;
		}
		else
			i++;
	}
	return (bigtab);
}

char	**ft_split(char const *s, char c)
{
	char	**bigtab;

	if (s == NULL)
		return (NULL);
	bigtab = ft_calloc(ft_cword(s, c) + 1, sizeof(char *));
	if (bigtab == NULL)
		return (NULL);
	bigtab = ft_fillbigtab(bigtab, 0, s, c);
	return (bigtab);
}
