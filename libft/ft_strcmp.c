/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthuy <jthuy@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 13:37:12 by jthuy             #+#    #+#             */
/*   Updated: 2019/09/08 13:56:33 by jthuy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*tmp_s1;
	unsigned char	*tmp_s2;

	tmp_s1 = (unsigned char *)s1;
	tmp_s2 = (unsigned char *)s2;
	if (tmp_s1 == tmp_s2)
		return (0);
	while (*tmp_s1 || *tmp_s2)
	{
		if (*tmp_s1 != *tmp_s2)
			return ((int)(*tmp_s1 - *tmp_s2));
		tmp_s1++;
		tmp_s2++;
	}
	return (0);
}
