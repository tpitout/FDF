/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpitout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 17:44:44 by tpitout           #+#    #+#             */
/*   Updated: 2018/07/20 17:44:46 by tpitout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*lst;
	t_list	*tmp;

	lst = *alst;
	while (lst != NULL)
	{
		tmp = lst->next;
		del(lst->content, lst->content_size);
		lst = lst->next;
		lst = tmp;
		free(tmp);
	}
	*alst = NULL;
}
