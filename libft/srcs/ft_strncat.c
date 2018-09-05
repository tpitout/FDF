/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpitout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 17:39:22 by tpitout           #+#    #+#             */
/*   Updated: 2018/07/20 17:39:24 by tpitout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	size_t		i;
	int			len;

	i = 0;
	len = ft_strlen((const char *)dest);
	while (n > 0)
	{
		if (src[i] == '\0')
		{
			i++;
			break ;
		}
		dest[len] = src[i];
		len++;
		i++;
		n--;
	}
	dest[len] = '\0';
	return (dest);
}
