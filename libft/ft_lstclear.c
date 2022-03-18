/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayassir <ayassir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 20:28:10 by ayassir           #+#    #+#             */
/*   Updated: 2021/11/24 22:44:25 by ayassir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;
	t_list	*temp;

	if (!*lst)
		return ;
	tmp = *lst;
	temp = *lst;
	while (tmp != NULL)
	{
		temp = temp->next;
		del(tmp->content);
		free(tmp);
		tmp = temp;
	}
	*lst = NULL;
}
