/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strspn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpitout <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 18:00:01 by tpitout           #+#    #+#             */
/*   Updated: 2018/07/20 18:00:02 by tpitout          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strspn(const char *s1, const char *s2)
{
	int		i;
	int		j;
	int		count;

	if (!s1 || !s2)
		return (0);
	i = 0;
	count = 0;
	while (s1[i] != '\0')
	{
		j = 0;
		while (s2[j] != '\0')
		{
			if (s2[j] == s1[i])
			{
				count++;
				break ;
			}
			j++;
		}
		i++;
	}
	return (count);
}
