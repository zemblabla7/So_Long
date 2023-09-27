/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carolina <carolina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 13:19:23 by casomarr          #+#    #+#             */
/*   Updated: 2022/12/06 15:58:10 by carolina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_content;
	t_list	*new_list;

	if (lst == NULL)
		return (NULL);
	else
	{
		new_list = 0;
		while (lst != NULL)
		{
			new_content = ft_lstnew((*f)(lst -> content));
			if (new_content == NULL)
			{
				ft_lstclear(&new_content, del);
				return (NULL);
			}
			ft_lstadd_back(&new_list, new_content);
			lst = lst -> next;
		}
		return (new_list);
	}
}
