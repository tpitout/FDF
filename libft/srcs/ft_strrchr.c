/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpitout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 17:59:09 by tpitout           #+#    #+#             */
/*   Updated: 2018/07/20 17:59:10 by tpitout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int		len;
	int		i;
	char	*s;

	if (str[0] == '\0')
		return (NULL);
	s = (char *)str;
	i = ft_strlen(str);
	len = ft_strlen(str);
	while (len > 0 && s[i] != (unsigned char)c)
	{
		if (s[len - 1] == s[0] && s[len - 1] != c)
		{
			return (NULL);
		}
		i--;
		len--;
	}
	return (s + i);
}
