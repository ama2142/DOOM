/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthuy <jthuy@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 19:33:28 by jthuy             #+#    #+#             */
/*   Updated: 2019/09/23 17:07:20 by jthuy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrdup(char *str, size_t n)
{
	size_t	len;
	char	*tmp;
	size_t	i;

	if (!str || !n)
		return (0);
	len = ft_strlen(str);
	i = len;
	if (len > n)
		len = n;
	if (len == 0 || (len + 1) == 0)
		return (0);
	if (n == 1 && str[len - 1] == '\n')
		return (0);
	tmp = (char *)malloc(sizeof(char) * (len + 1));
	if (!tmp)
		return (0);
	while (len)
	{
		tmp[len - 1] = str[i];
		--i;
		--len;
	}
	return (tmp);
}
