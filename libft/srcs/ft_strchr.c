/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpitout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 17:51:04 by tpitout           #+#    #+#             */
/*   Updated: 2018/07/20 17:51:05 by tpitout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int		i;
	char	*s;

	s = (char *)str;
	i = 0;
	while (s[i] != (unsigned char)c)
	{
		if (s[i] == '\0')
		{
			return (NULL);
		}
		i++;
	}
	return (s + i);
}
