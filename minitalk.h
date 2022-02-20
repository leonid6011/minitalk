/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echrysta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 17:46:37 by echrysta          #+#    #+#             */
/*   Updated: 2022/02/16 17:46:46 by echrysta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include <stdio.h> //потом убрать

void			ft_putstr_fd(char const *s, int fd);
unsigned long	ft_strlen(const char *s);
void			ft_putnbr_fd(int n, int fd);
int				ft_atoi(const char *str);
void			ft_putchar_fd(char c, int fd);

#endif
