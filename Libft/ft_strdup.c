/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivelutin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 19:53:44 by ivelutin          #+#    #+#             */
/*   Updated: 2017/01/07 19:53:45 by ivelutin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	int		j;
	char	*cpy;

	i = 0;
	j = 0;
	while (s1[i])
		i++;
	cpy = (char *)malloc(i + 1);
	if (cpy != ('\0'))
	{
		while (s1[j])
		{
			cpy[j] = s1[j];
			j++;
			cpy[j] = '\0';
		}
		return (cpy);
	}
	return (0);
}
