/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imellali <imellali@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 18:27:44 by imellali          #+#    #+#             */
/*   Updated: 2025/02/25 15:28:22 by imellali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	send_bit(char byte, int pid)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if ((byte >> i) & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(850);
		i--;
	}
}

static void	send_signal(char *message, int pid)
{
	int		i;

	i = 0;
	while (message[i])
	{
		send_bit(message[i], pid);
		i++;
	}
}

static void	send_null(int pid)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		kill(pid, SIGUSR1);
		usleep(150);
		i++;
	}
}

int	main(int argc, char **argv)
{
	char	*message;
	int		pid;

	if (argc != 3 || argv[2][0] == '\0')
		return (-1);
	pid = ft_atoi(argv[1]);
	if (pid < 0)
		return (-1);
	message = argv[2];
	send_signal(message, pid);
	send_null(pid);
	return (0);
}
