/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abutet <abutet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 13:00:44 by abutet            #+#    #+#             */
/*   Updated: 2023/11/14 10:27:38 by abutet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t				i;
	const unsigned char	*tmp_s1;
	const unsigned char	*tmp_s2;

	tmp_s1 = (const unsigned char *) s1;
	tmp_s2 = (const unsigned char *) s2;
	i = 0;
	if (n == 0)
		return (0);
	while (tmp_s1[i] == tmp_s2[i] && tmp_s1[i] != '\0' && tmp_s2[i] != '\0'
		&& i < n - 1)
		i++;
	return (tmp_s1[i] - tmp_s2[i]);
}
