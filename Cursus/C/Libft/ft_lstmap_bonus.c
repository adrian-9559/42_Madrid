/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adriescr <adriescr@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 18:11:50 by adriescr          #+#    #+#             */
/*   Updated: 2025/04/23 18:29:40 by adriescr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_elem;

	if (!lst || !f)
		return (NULL);
	new_list = NULL;
	while (lst)
	{
		new_elem = (t_list *)malloc(sizeof(t_list));
		if (!new_elem)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		new_elem->content = f(lst->content);
		new_elem->next = NULL;
		ft_lstadd_back(&new_list, new_elem);
		lst = lst->next;
	}
	return (new_list);
}

/*
int main(void)
{
	t_list	*list;
	t_list	*new_list;

	list = ft_lstnew("Hello");
	ft_lstadd_back(&list, ft_lstnew("World"));
	ft_lstadd_back(&list, ft_lstnew("42"));
	new_list = ft_lstmap(list, &ft_strdup, &free);
	while (new_list)
	{
		printf("%s\n", (char *)new_list->content);
		new_list = new_list->next;
	}
	ft_lstclear(&list, &free);
	return (0);
}
*/