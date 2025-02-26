/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imellali <imellali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 22:16:29 by imellali          #+#    #+#             */
/*   Updated: 2025/02/24 20:57:56 by imellali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static unsigned char	decode_bin(unsigned char *bits)
{
	unsigned char	char_byte;
	int				i;

	char_byte = 0;
	i = 0;
	while (i < 8)
	{
		char_byte |= bits[i] << (7 - i);
		i++;
	}
	return (char_byte);
}

void	set_values(int *index, int *ccp, int pid)
{
	*index = 0;
	*ccp = pid;
}

static void	sig_handler(int signal, siginfo_t *info, void *context)
{
	static unsigned char	bits[8];
	static int				index = 0;
	static int				ccp = 0;
	unsigned char			char_byte;

	(void)context;
	if (ccp != info->si_pid)
		set_values(&index, &ccp, info->si_pid);
	if (signal == SIGUSR1)
		bits[index] = 0;
	else if (signal == SIGUSR2)
		bits[index] = 1;
	index++;
	if (index == 8)
	{
		char_byte = decode_bin(bits);
		index = 0;
		if (char_byte != '\0')
			ft_printf("%c", char_byte);
		else
		{
			ft_printf("\n");
			kill(info->si_pid, SIGUSR1);
		}
	}
}

static void	print_banner(void)
{
	ft_printf("\033[1;94m");
	ft_printf("\n");
	ft_printf("   ██████ ███████ ██████  ██    ██ ███████ ██████   \n");
	ft_printf("  ██      ██      ██   ██ ██    ██ ██      ██   ██  \n");
	ft_printf("   █████  █████   ██████  ██    ██ █████   ██████   \n");
	ft_printf("       ██ ██      ██   ██  ██  ██  ██      ██   ██  \n");
	ft_printf("  ██████  ███████ ██   ██   ████   ███████ ██   ██  \n");
	ft_printf("\033[0m\n");
	ft_printf("\033[1;36m───────────────────────────────────\033[0m\n");
	ft_printf("\033[1;92m\033[5m");
	ft_printf("  ➤ Server is Running...\n");
	ft_printf("\033[0m");
	ft_printf("\033[1;93m");
	ft_printf("  ➤ Server PID : %d\n", getpid());
	ft_printf("\033[0m");
	ft_printf("\033[1;36m───────────────────────────────────\033[0m\n");
}

int	main(void)
{
	struct sigaction	sig;

	print_banner();
	sig.sa_sigaction = sig_handler;
	sig.sa_flags = SA_SIGINFO;
	sigemptyset(&sig.sa_mask);
	sigaddset(&sig.sa_mask, SIGUSR1);
	sigaddset(&sig.sa_mask, SIGUSR2);
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	while (1)
		pause();
	return (0);
}
