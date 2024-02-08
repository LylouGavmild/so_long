/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abutet <abutet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 10:40:20 by abutet            #+#    #+#             */
/*   Updated: 2023/11/16 09:50:32 by abutet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	c;
	size_t	n_len;
	char	*b;

	if ((!big || !little) && !len)
		return (0);
	i = 0;
	b = (char *)big;
	n_len = ft_strlen(little);
	if (n_len == 0 || big == little)
		return (b);
	while (b[i] != '\0' && i < len)
	{
		c = 0;
		while (b[i + c] != '\0' && little[c] != '\0'
			&& b[i + c] == little[c] && i + c < len)
			c++;
		if (c == n_len)
			return (b + i);
		i++;
	}
	return (0);
}
