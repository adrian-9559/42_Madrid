/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 18:06:53 by adriescr          #+#    #+#             */
/*   Updated: 2025/04/23 18:07:32 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
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

	ft_lstiter(list, &ft_putstr_fd);
	return (0);
}
*/