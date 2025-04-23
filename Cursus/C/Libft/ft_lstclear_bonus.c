/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 17:58:33 by adriescr          #+#    #+#             */
/*   Updated: 2025/04/23 17:59:07 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*temp;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		temp = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = temp;
	}
}

/*
int	main(void)
{
	t_list	*list;
	t_list	*node1;
	t_list	*node2;

	list = ft_lstnew("Hello");
	node1 = ft_lstnew("World");
	node2 = ft_lstnew("!");

	ft_lstadd_front(&list, node1);
	ft_lstadd_front(&list, node2);

	ft_lstclear(&list, free);
	return (0);
}
*/