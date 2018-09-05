/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpitout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 19:45:30 by tpitout           #+#    #+#             */
/*   Updated: 2018/07/20 19:45:31 by tpitout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *str)
{
	char	*s;
	int		i;
	int		j;
	int		len;

	i = 0;
	j = 0;
	if (str == NULL)
		return (NULL);
	len = ft_strlen(str);
	while (str[len - 1] == ' ' || str[len - 1] == '\t' || str[len - 1] == '\n')
		len--;
	if (len > 0)
		while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
		{
			i++;
			len--;
		}
	s = ft_strnew(len);
	while (s && j < len)
	{
		s[j] = str[i + j];
		j++;
	}
	return (s);
}
