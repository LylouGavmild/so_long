/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abutet <abutet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 11:50:33 by abutet            #+#    #+#             */
/*   Updated: 2023/11/13 17:52:46 by abutet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	tmp;
	void	*r;

	if (!nmemb || !size)
		return (malloc(1));
	if (SIZE_MAX / nmemb < size)
	{
		return (NULL);
	}
	tmp = nmemb * size;
	r = malloc(tmp);
	if (!r)
		return (0);
	ft_bzero(r, tmp);
	return (r);
}
