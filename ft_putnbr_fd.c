/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echrysta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 17:46:10 by echrysta          #+#    #+#             */
/*   Updated: 2022/02/16 17:46:11 by echrysta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	count_nbr(long n)
{
	int	i;

	i = 1;
	if (n < 0)
		n = -n;
	while (n >= 10)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static unsigned int	del_creat(int count)
{
	int				i;
	unsigned int	del;

	del = 1;
	i = 0;
	while (i != count - 1)
	{
		del = del * 10;
		i++;
	}
	return (del);
}

void	ft_putnbr_fd(int n, int fd)
{
	int				i;
	unsigned int	del;
	char			ch;
	int				count;

	i = 0;
	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	count = count_nbr(n);
	del = del_creat(count);
	while (i != count)
	{
		ch = (n / del) + '0';
		write(fd, &ch, 1);
		n = n % del;
		del = del / 10;
		i++;
	}
}
