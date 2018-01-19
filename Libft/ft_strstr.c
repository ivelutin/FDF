/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivelutin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 21:02:13 by ivelutin          #+#    #+#             */
/*   Updated: 2017/01/07 21:02:15 by ivelutin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int i;
	int j;

	i = 0;
	j = ft_strlen(little);
	if (j == 0)
		return ((char *)big);
	while (ft_strlen(big) > 0)
	{
		if (big[0] == little[i])
			i++;
		else
		{
			big -= i;
			i = 0;
		}
		if (i == j)
			return ((char *)big - i + 1);
		big++;
	}
	return (0);
}
