/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpitout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 17:53:34 by tpitout           #+#    #+#             */
/*   Updated: 2018/07/20 17:53:35 by tpitout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *str1, const char *str2)
{
	char	*s;
	int		size;

	if (!str1 || !str2)
		return (NULL);
	size = ft_strlen(str1) + ft_strlen(str2);
	s = (char *)malloc(sizeof(char) * (size + 1));
	if (!s)
		return (NULL);
	ft_strcpy(s, str1);
	ft_strcat(s, str2);
	return (s);
}
