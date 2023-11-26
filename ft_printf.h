/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchihab <mchihab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 14:33:12 by mchihab           #+#    #+#             */
/*   Updated: 2023/11/26 14:53:10 by mchihab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H
#include <stdarg.h>
#include <unistd.h>

int ft_printf_format(char spex, va_list ap);
int ft_printf(const char *f, ...);
int ft_print_chr(int c);
int ft_print_hex(long n,int base);
int ft_print_upper_hex(unsigned int n,int base);
int ft_print_string(char *str);
int ft_print_upper_hexx(unsigned long n,int base);
#endif