/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abutet <abutet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 14:29:16 by abutet            #+#    #+#             */
/*   Updated: 2023/11/15 14:54:53 by abutet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t		i;
	char		*tmp_dst;
	const char	*tmp_src;

	tmp_dst = (char *)dst;
	tmp_src = (char *)src;
	i = 1;
	if (!dst && !src && len)
		return (NULL);
	if (tmp_src < tmp_dst)
	{
		while (i <= len)
		{
			tmp_dst[len - i] = tmp_src[len - i];
			i++;
		}
	}
	else
	{
		while (len-- > 0)
			*(tmp_dst++) = *(tmp_src++);
	}
	return (dst);
}
