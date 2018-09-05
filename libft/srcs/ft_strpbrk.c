/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpbrk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpitout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 17:58:55 by tpitout           #+#    #+#             */
/*   Updated: 2018/07/20 17:58:57 by tpitout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strpbrk(const char *s, const char *charset)
{
	int		i;
	int		j;

	i = 0;
	if (!s || !charset)
		return (0);
	while (s[i] != '\0')
	{
		j = 0;
		while (charset[j] != '\0')
		{
			if (charset[j] == s[i])
				return ((char *)s + i);
			j++;
		}
		i++;
	}
	return (0);
}
