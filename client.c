/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echrysta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 17:45:41 by echrysta          #+#    #+#             */
/*   Updated: 2022/02/16 17:45:45 by echrysta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sihandler(int signal_nbr, siginfo_t *siginfo, void *useless)
{
	(void)signal_nbr;
	(void)useless;
	(void)siginfo;
}

void	convert_to_bit_sig(char conv_char, int serv_pid)
{
	int	num;

	num = 128;
	while (num > 0)
	{
		if ((num & conv_char) > 0)
		{
			kill(serv_pid, SIGUSR1);
		}
		else
		{
			kill(serv_pid, SIGUSR2);
		}
		num /= 2;
		usleep(200);
	}
}

void	sending_str_to(int serv_pid, char *str)
{
	int	i;

	i = 1;
	convert_to_bit_sig(str[0], serv_pid);
	while (str[i] != '\0')
	{
		convert_to_bit_sig(str[i], serv_pid);
		i++;
	}
	ft_putstr_fd("String has been sent\n", 1);
}

int	main(int argc, char **argv)
{
	struct sigaction	siga;
	int					serv_pid;
	char				*str;

	if (argc > 3 || argc < 3)
	{
		ft_putstr_fd("Invalid\n", 1);
		return (0);
	}
	siga.sa_flags = SA_SIGINFO;
	siga.sa_sigaction = &sihandler;
	sigaction(SIGUSR1, &siga, NULL);
	sigaction(SIGUSR2, &siga, NULL);
	serv_pid = ft_atoi(argv[1]);
	str = argv[2];
	if (argc == 3)
		sending_str_to(serv_pid, str);
	else
	{
		ft_putstr_fd("Invalid\n", 1);
		return (0);
	}
}
