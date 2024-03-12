/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzinchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:10:45 by dzinchen          #+#    #+#             */
/*   Updated: 2024/01/25 11:13:47 by dzinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <unistd.h>
#include <signal.h>

void	signal_handler(int signal)
{
	static unsigned int	bits;
	static char			char_value;

	if (signal == SIGUSR1)
	{
		char_value = char_value | (0x01 << bits);
		bits++;
	}
	else if (signal == SIGUSR2)
	{
		bits++;
	}
	if (bits == 8)
	{
		ft_printf("%c", char_value);
		char_value = 0;
		bits = 0;
	}
}

int	main(int argc, char **argv)
{
	(void)argv;
	if (argc == 1)
	{
		ft_printf("PID: ");
		ft_printf("%i\n", getpid());
		while (1)
		{
			signal(SIGUSR1, signal_handler);
			signal(SIGUSR2, signal_handler);
		}
	}
	ft_printf("Usage: ./server\n");
	return (0);
}
