/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpitout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 17:47:27 by tpitout           #+#    #+#             */
/*   Updated: 2018/07/20 17:47:28 by tpitout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *str1, const void *str2, size_t n)
{
	char	*s1;
	char	*s2;
	size_t	i;

	if (str1 == str2)
		return (str1);
	s1 = (char *)str1;
	s2 = (char *)str2;
	if (str1 > str2)
	{
		i = n;
		while (i-- > 0)
			s1[i] = s2[i];
	}
	else
	{
		i = 0;
		while (i < n)
		{
			s1[i] = s2[i];
			i++;
		}
	}
	return (s1);
}
