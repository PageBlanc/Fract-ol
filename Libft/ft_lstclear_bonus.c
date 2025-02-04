/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axdubois <axdubois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 18:38:01 by axdubois          #+#    #+#             */
/*   Updated: 2023/11/11 16:35:56 by axdubois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;

	if (*lst == NULL || !del)
		return ;
	while ((*lst)->next)
	{
		tmp = (*lst)->next;
		ft_lstdelone(*lst, (*del));
		*lst = tmp;
	}
	ft_lstdelone(*lst, (*del));
	*lst = NULL;
}
