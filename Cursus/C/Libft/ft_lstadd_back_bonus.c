/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 16:33:00 by adriescr          #+#    #+#             */
/*   Updated: 2025/04/23 16:33:36 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	last = ft_lstlast(*lst);
	last->next = new;
}

/*
int main(void)
{
	t_list *head;
	t_list *new_node;

	head = ft_lstnew("Hello");
	new_node = ft_lstnew("World");
	ft_lstadd_back(&head, new_node);
	printf("%s\n", (char *)head->content);
	printf("%s\n", (char *)head->next->content);
	return (0);
}
*/