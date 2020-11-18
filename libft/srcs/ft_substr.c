/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 00:25:12 by marvin            #+#    #+#             */
/*   Updated: 2020/11/16 22:01:22 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	unsigned int	i;
	unsigned int	y;

	i = start;
	y = 0;
	if (!s)
		return (NULL);
	if (!(str = malloc((int)len + 1)))
		return (NULL);
	while (s[i] && y < (unsigned int)len && start < ft_strlen(s))
	{
		str[y] = s[i];
		i++;
		y++;
	}
	str[y] = '\0';
	return (str);
}
