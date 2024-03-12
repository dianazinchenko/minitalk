/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzinchen <dzinchen@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 12:02:45 by dzinchen          #+#    #+#             */
/*   Updated: 2023/10/28 15:30:46 by dzinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf(const char *str, ...)
{
	int		i;
	int		print_len;
	va_list	args;

	i = 0;
	print_len = 0;
	va_start(args, str);
	while (str[i] != '\0')
	{
		if (str[i] != '%')
		{
			print_len += write(1, &str[i], 1);
		}
		else
		{
			i++;
			print_len += ft_typefinder(str[i], args);
		}
		i++;
	}
	va_end(args);
	return (print_len);
}

/*#include <stdio.h>

int	main(void)
{
	ft_printf("\nft_printf:\n");
	ft_printf(" count: %i\n", ft_printf("NULL %s NULL", 0));
	ft_printf("\t count: %i\n", ft_printf("%i", 2147483647));
	ft_printf("\t\t count: %d\n", ft_printf("%i", -101));
	ft_printf("\t count: %i\n", ft_printf("%i", -2147483648));
	ft_printf("\t count: %i\n", ft_printf("%u", 4294967295));
	ft_printf("\t\t count: %i\n", ft_printf("%x", 255));
	ft_printf("\t count: %i\n", ft_printf("%X", 2147483647));
	ft_printf("\t count: %i\n", ft_printf("%p", &"hi"));
	ft_printf("\t\t count: %i\n", ft_printf("%p", 0));
	
	printf("\nprintf:\n");
	printf(" count: %i\n", printf("NULL %s NULL", (char *) 0));
	printf("\t count: %i\n", printf("%i", 2147483647));
	printf("\t\t count: %d\n", printf("%i", -101));
	printf("\t count: %i\n", printf("%li", -2147483648));
	printf("\t count: %i\n", printf("%ld", 4294967295));
	printf("\t\t count: %i\n", printf("%x", 255));
	printf("\t count: %i\n", printf("%X", 2147483647));
	printf("\t count: %i\n", printf("%p", &"hi"));
	printf("\t\t count: %i\n", printf("%p", (void *) 0));

	return (0);
}*/
