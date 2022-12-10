/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaygisi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 10:24:10 by agaygisi          #+#    #+#             */
/*   Updated: 2022/11/09 10:24:12 by agaygisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft/libft.h"
# include <stdarg.h>
# include <unistd.h>

int			ft_print_percent(char *part);
int			ft_print_char(char c);
int			ft_print_str(char *s);
int			ft_print_number(long long n, int base, char *radix);
int			ft_print_pointer(unsigned long n, int base, char *radix);
int			ft_c_dgt(long long nbr, int base);
int			ft_count_pointer(unsigned long nbr, int base);
int			ft_eval_arg(char *part, va_list args);
size_t		ft_count_arg_len(const char *s, size_t i);
size_t		ft_count_str_len(const char *s, size_t i);
int			ft_count_parts(const char *s);
char		**ft_split_parts(const char *s);
void		ft_free_all(char **parts);
int			ft_printf(const char *str, ...);

int			ft_left_padding_chr(char *arg);
int			ft_right_padding_chr(char *arg);
int			ft_minus_flag(char *s);
int			ft_zero_flag(char *s);
int			ft_hash_flag(char *s);
int			ft_space_flag(char *s);
int			ft_plus_flag(char *s);
int			ft_b_c(char *arg, char c);
int			ft_b_s(char *arg, char *str);
int			ft_b_n(char *arg, long long nbr, int base, char *radix);
int			ft_b_p(char *arg, unsigned long nbr);
int			ft_wm(char *s);
int			ft_is_pm(char *s);
int			ft_pm(char *s);
int			ft_left_padding_nbr(char *arg, long long nbr, int base);
int			ft_print_number_core(char *arg, long long nbr, int base,
				char *radix);
int			ft_right_padding_nbr(char *a, long long n, int base);
int			ft_left_padding_ptr(char *arg, unsigned long nbr, int base);
int			ft_right_padding_ptr(char *arg, unsigned long nbr, int base);
int			ft_p_nbr_sz(char *arg, long long nbr, int base);
int			ft_t_nbr_sz(char *arg, long long nbr, int base);
int			ft_t_str_sz(char *arg, char *str);
int			ft_ptr_sz(unsigned long nbr, int base);
int			ft_left_padding_str(char *arg, char *str);
int			ft_print_str_core(char *arg, char *str);
int			ft_right_padding_str(char *arg, char *str);
long long	ft_abs(long long n);
int			ft_isnegative(long long nbr);
int			ft_cc(char c, int repeat);
int			ft_signed(char *arg, long long nbr);
#endif
