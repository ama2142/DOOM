/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthuy <jthuy@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 20:01:09 by jthuy             #+#    #+#             */
/*   Updated: 2019/10/15 22:40:49 by jthuy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup2(const char *s1)
{
	char	*tmp;
	size_t	i;

	tmp = (char *)malloc(sizeof(char) * (ft_strlen((char*)s1) + 1));
	if (tmp != 0)
	{
		i = 0;
		while (s1[i])
		{
			tmp[i] = s1[i];
			i++;
		}
		tmp[i] = 0;
	}
	return (tmp);
}
