/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivelutin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 11:30:00 by ivelutin          #+#    #+#             */
/*   Updated: 2017/01/09 11:30:02 by ivelutin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	int		i;
	size_t	j;

	i = 0;
	j = 0;
	if (ft_strlen(little) == 0)
		return ((char *)big);
	while (ft_strlen(big) > 0)
	{
		if (big[0] == little[i])
			i++;
		else
		{
			big -= i;
			j -= i;
			i = 0;
		}
		if (j >= len)
			return (NULL);
		if (i == (int)ft_strlen(little))
			return ((char *)big - i + 1);
		big++;
		j++;
	}
	return (NULL);
}
