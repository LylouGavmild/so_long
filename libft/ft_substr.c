/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abutet <abutet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 13:59:14 by abutet            #+#    #+#             */
/*   Updated: 2023/11/13 18:08:11 by abutet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*r;
	size_t	i;
	size_t	len2;

	i = 0;
	if (!s)
		return (NULL);
	if ((size_t)start > ft_strlen(s))
		return (ft_strdup("\0"));
	if ((size_t)start + len > ft_strlen(s))
		len2 = ft_strlen(s) - start;
	if ((size_t)start + len <= ft_strlen(s))
		len2 = len;
	r = malloc(sizeof(char) * (len2 + 1));
	if (!r)
		return (NULL);
	while (i < len && s[start + i])
	{
		r[i] = s[start + i];
		i++;
	}
	r[i] = '\0';
	return (r);
}
