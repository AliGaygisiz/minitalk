/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaygisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 16:59:09 by agaygisi          #+#    #+#             */
/*   Updated: 2022/11/22 16:59:10 by agaygisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_confirmation(int signal)
{
	static unsigned int	i;
	static unsigned int	s;
	static unsigned int	result;

	if (i == 0)
		i = 1;
	if (signal == SIGUSR1)
	{
		result += 2147483648 / i;
		i = i * 2;
		s++;
	}
	else if (signal == SIGUSR2)
	{
		i = i * 2;
		s++;
	}
	if (s == 32)
	{
		kill(result, SIGUSR1);
		result = 0;
		i = 1;
		s = 0;
	}
}

unsigned int	power(int power)
{
	unsigned int	x;

	x = 1;
	while (power)
	{
		x = x * 2;
		power--;
	}
	return (x);
}

void	ft_print_sigchar(int signal)
{
	static int	i;
	static int	s;
	static int	result;
	int			k;

	if (s < 32)
	{
		send_confirmation(signal);
		s++;
		return ;
	}
	k = 128 / power(i);
	if (signal == SIGUSR1)
		result += k;
	i++;
	if (k == 1)
	{
		if (result == '\n')
			s = 0;
		ft_printf("%c", result);
		i = 0;
		result = 0;
	}
}

int	main(void)
{
	int	pid;

	pid = getpid();
	ft_printf("pid: %d\n", pid);
	signal(SIGUSR1, ft_print_sigchar);
	signal(SIGUSR2, ft_print_sigchar);
	while (1)
		pause();
	return (0);
}
