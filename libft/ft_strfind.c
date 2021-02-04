/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strfind.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthuy <jthuy@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 17:10:52 by jthuy             #+#    #+#             */
/*   Updated: 2019/09/23 17:11:28 by jthuy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strfind(char *str, char sym)
{
	size_t	pos;

	if (!str)
		return (0);
	pos = 1;
	while (*str)
	{
		if (*str == sym)
			return (pos);
		++pos;
		++str;
	}
	return (0);
}
