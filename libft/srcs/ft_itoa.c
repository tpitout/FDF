/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpitout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 17:44:01 by tpitout           #+#    #+#             */
/*   Updated: 2018/07/20 17:44:05 by tpitout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char		*s;

	s = (char *)malloc(sizeof(char) * 2);
	if (!s)
		return (NULL);
	if (n == -2147483648)
		return (ft_strcpy(s, "-2147483648"));
	if (n < 0)
	{
		s[0] = '-';
		s[1] = '\0';
		s = ft_strjoin(s, ft_itoa(-n));
	}
	else if (n >= 10)
	{
		s = ft_strjoin(ft_itoa(n / 10), ft_itoa(n % 10));
	}
	else if (n < 10)
	{
		s[0] = (char)n + 48;
		s[1] = '\0';
	}
	return (s);
}
