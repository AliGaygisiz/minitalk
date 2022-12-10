/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaygisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:13:28 by agaygisi          #+#    #+#             */
/*   Updated: 2022/11/22 17:17:08 by agaygisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include "ft_printf/ft_printf.h"

char			*dec_to_bin(unsigned int c, int size, unsigned int a);
char			*ft_binary_pid(void);
void			ft_send_sig(int pid, unsigned int c, int size, unsigned int a);
void			ft_send_pid(int srv_pid);
void			send_confirmation(int signal);
unsigned int	power(int power);
void			ft_print_sigchar(int signal);

#endif
