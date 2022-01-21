/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebackor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 12:58:31 by lebackor          #+#    #+#             */
/*   Updated: 2021/12/03 12:53:30 by lebackor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *s1)
{
	size_t	a;
	size_t	i;
	char	*s2;

	i = 0;
	a = ft_strlen(s1);
	s2 = malloc(sizeof(char) * a + 1);
	if (!s2)
		return (s2);
	while (i < a)
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}
