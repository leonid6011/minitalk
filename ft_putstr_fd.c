/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echrysta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 17:46:17 by echrysta          #+#    #+#             */
/*   Updated: 2022/02/16 17:46:18 by echrysta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putstr_fd(char const *s, int fd)
{
	if (s == NULL)
		write(1, NULL, 1);
	else
		write(fd, s, ft_strlen(s));
}
