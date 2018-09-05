/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpitout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 19:45:16 by tpitout           #+#    #+#             */
/*   Updated: 2018/07/20 19:45:18 by tpitout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(const char *s, unsigned int start, size_t len)
{
	char		*s2;
	size_t		i;

	i = 0;
	if (!s)
		return (NULL);
	s2 = (char *)s;
	s2 = (char *)malloc(sizeof(char) * (len + 1));
	if (!s2)
	{
		return (NULL);
	}
	while (i < len)
	{
		s2[i] = s[start + i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}
