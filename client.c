/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzinchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:10:16 by dzinchen          #+#    #+#             */
/*   Updated: 2024/01/25 11:13:20 by dzinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <unistd.h>
#include <signal.h>

void	send_bits(int pid, char char_value)
{
	unsigned int	bits;

	bits = 0;
	while (bits < 8)
	{
		if ((char_value & (0x01 << bits)) == 0)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(100);
		bits++;
	}
}

int	main(int argc, char **argv)
{
	pid_t	pid;
	int	i;

	i = 0;
	if (argc != 3 || !ft_strlen(argv[2]))
	{
		ft_printf("Please provide valid arguments.\n", 1);
		return (1);
	}
	pid = ft_atoi(argv[1]);
	if (pid < 1 || kill(pid, 0) == -1)
	{
		ft_printf("Please provide a valid PID.\n", 1);
		return (1);
	}
	while (argv[2][i])
	{
		send_bits(pid, argv[2][i]);
		i++;
	}
	send_bits(pid, '\0');
	return (0);
}
