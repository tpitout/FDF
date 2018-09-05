/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpitout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 17:58:36 by tpitout           #+#    #+#             */
/*   Updated: 2018/07/20 17:58:38 by tpitout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *sub, size_t n)
{
	size_t	i;
	size_t	j;
	char	*s;

	s = 0;
	i = 0;
	if (sub[0] == '\0')
		return ((char *)str);
	while (str[i] && i < n)
	{
		if (str[i] == sub[0])
		{
			j = 0;
			s = (char *)str + i;
			while (str[i + j] == sub[j] && (i + j) < n)
			{
				if (sub[j + 1] == '\0')
					return (s);
				j++;
			}
			s = 0;
		}
		i++;
	}
	return (NULL);
}
