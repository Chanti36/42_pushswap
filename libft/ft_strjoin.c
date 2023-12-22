/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgil-moy <sgil-moy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 10:55:10 by sgil-moy          #+#    #+#             */
/*   Updated: 2023/12/05 11:02:33 by sgil-moy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../code/push_swap.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*p;

	i = (ft_strlen(s1) + ft_strlen(s2) + 1);
	p = (char *)malloc(i * sizeof(char));
	if (p == NULL)
		return (p);
	i = 0;
	while (s1[i] != '\0')
	{
		p[i] = s1[i];
		++i;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		p[i + j] = s2[j];
		++j;
	}
	p[i + j] = '\0';
	return (p);
}
