/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpitout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 18:00:15 by tpitout           #+#    #+#             */
/*   Updated: 2018/07/20 18:00:17 by tpitout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *sub)
{
	int		i;
	int		j;
	char	*s;

	s = (char *)str;
	i = 0;
	if (sub[0] == '\0')
	{
		return (s);
	}
	while (s[i] != '\0')
	{
		j = 0;
		while (sub[j] == s[i + j])
		{
			if (sub[j + 1] == '\0')
			{
				return (s + i);
			}
			j++;
		}
		i++;
	}
	return (NULL);
}
