/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echrysta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 17:46:54 by echrysta          #+#    #+#             */
/*   Updated: 2022/02/16 17:46:56 by echrysta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

pid_t	g_pid_c = 0;

void	sihandler(int signal_nbr, siginfo_t *siginfo, void *useless)
{
	static int	newchar = 0;
	static int	num = 128;

	(void)useless;
	if (g_pid_c == 0)
	{
		g_pid_c = siginfo->si_pid;
	}
	if (g_pid_c != siginfo->si_pid)
	{
		num = 128;
		newchar = 0;
		g_pid_c = 0;
	}
	if (signal_nbr == SIGUSR1)
		newchar = newchar | num;
	num = num / 2;
	if (num == 0)
	{
		ft_putchar_fd(newchar, 1);
		num = 128;
		newchar = 0;
		g_pid_c = 0;
	}
}

int	main(void)
{
	struct sigaction	siga;
	int					flag;

	siga.sa_flags = SA_SIGINFO;
	siga.sa_sigaction = &sihandler;
	sigaction(SIGUSR1, &siga, NULL);
	sigaction(SIGUSR2, &siga, NULL);
	flag = 1;
	ft_putstr_fd("PID: ", 1);
	ft_putnbr_fd(getpid(), 1);
	write(1, "\n", 1);
	while (flag)
		pause();
	return (0);
}
