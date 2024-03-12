/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzinchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 09:56:43 by dzinchen          #+#    #+#             */
/*   Updated: 2023/10/19 12:56:16 by dzinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*#include <string.h>*/

int	ft_strncmp(const char *s1, const char *s2, size_t size)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			i;

	i = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while (s1[i] != '\0' && s2[i] != '\0' && i < size)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	if (i < size)
		return (str1[i] - str2[i]);
	return (0);
}

/*int	main(void)
{
	const char *s1 = "\x12\xff\x65\x12\xbd\xde\xad";
	const char *s2 = "\x12\x02";
	size_t size = 6;

	printf("%i\n", ft_strncmp(s1, s2, size));
	printf("%i", strncmp(s1, s2, size));
}*/
