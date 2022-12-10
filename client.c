/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaygisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 16:59:41 by agaygisi          #+#    #+#             */
/*   Updated: 2022/11/22 17:10:04 by agaygisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*dec_to_bin(unsigned int c, int size, unsigned int a)
{
	char	*str;
	int		j;

	str = malloc(sizeof(char) * (size + 1));
	j = 0;
	while (a > 0)
	{
		if (c >= a)
		{
			*(str + j) = '1';
			c %= a;
		}
		else
			*(str + j) = '0';
		a /= 2;
		j++;
	}
	*(str + j) = '\0';
	return (str);
}

char	*ft_binary_pid(void)
{
	unsigned int	pid;
	int				i;
	unsigned int	power;
	char			*binary_pid;

	i = 0;
	pid = getpid();
	power = 2147483648;
	binary_pid = malloc(33 * sizeof(char));
	while (i < 32)
	{
		if (pid / power)
		{
			binary_pid[i++] = '1';
			pid = pid - power;
			power = power / 2;
		}
		else
		{
			binary_pid[i++] = '0';
			power = power / 2;
		}
	}
	binary_pid[i] = '\0';
	return (binary_pid);
}

void	ft_send_sig(int pid, unsigned int c, int size, unsigned int a)
{
	char	*bit;
	int		i;

	bit = dec_to_bin(c, size, a);
	i = 0;
	while (*(bit + i))
	{
		if (*(bit + i) == '1')
			kill(pid, SIGUSR1);
		else if (*(bit + i) == '0')
			kill(pid, SIGUSR2);
		usleep(100);
		i++;
	}
	free(bit);
}

void	ft_send_pid(int srv_pid)
{
	char	*bits;
	int		i;

	if (srv_pid == SIGUSR1)
	{
		ft_printf("Mesaj basariyla gonderildi\n");
		return ;
	}
	i = 0;
	bits = ft_binary_pid();
	while (bits[i])
	{
		if (bits[i] == '1')
			kill(srv_pid, SIGUSR1);
		else if (bits[i] == '0')
			kill(srv_pid, SIGUSR2);
		i++;
		usleep(100);
	}
	free(bits);
}

int	main(int argc, char *argv[])
{
	int	i;

	if (argc != 3)
		ft_printf("./client <pid> [message]\n");
	else if (ft_atoi(argv[1]) < 0)
		return (1);
	else
	{
		signal(SIGUSR1, ft_send_pid);
		ft_send_pid(ft_atoi(argv[1]));
		i = 0;
		while (argv[2][i])
		{
			ft_send_sig(ft_atoi(argv[1]), argv[2][i++], 8, 128);
		}
		ft_send_sig(ft_atoi(argv[1]), '\n', 8, 128);
	}
	return (0);
}
