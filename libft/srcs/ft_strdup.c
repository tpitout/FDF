/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpitout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 17:52:28 by tpitout           #+#    #+#             */
/*   Updated: 2018/07/20 17:52:29 by tpitout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*str2;
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(str);
	str2 = (char *)malloc(sizeof(char) * (len + 1));
	if (str2)
	{
		while (str[i] != '\0')
		{
			str2[i] = str[i];
			i++;
		}
		str2[i] = '\0';
		return (str2);
	}
	return (NULL);
}
