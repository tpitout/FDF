/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpitout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 17:46:12 by tpitout           #+#    #+#             */
/*   Updated: 2018/07/20 17:46:14 by tpitout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t n)
{
	char	*s;

	s = (char *)malloc(sizeof(char) + (n + 1));
	if (!s || n > 2147483648)
		return (NULL);
	ft_bzero(s, n);
	return ((void *)s);
}
