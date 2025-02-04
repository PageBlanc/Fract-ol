/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axdubois <axdubois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 17:42:57 by axdubois          #+#    #+#             */
/*   Updated: 2023/11/07 11:03:12 by axdubois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	int	i;
	int	a;

	a = -1;
	i = 0;
	while (s[i])
	{
		if ((unsigned char)s[i] == (unsigned char)c)
			a = i;
		i++;
	}
	if (a != -1)
		return ((char *)&s[a]);
	if (c == 0)
		return ((char *)&s[i]);
	return (0);
}
