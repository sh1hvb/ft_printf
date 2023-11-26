/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchihab <mchihab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 14:33:12 by mchihab           #+#    #+#             */
/*   Updated: 2023/11/26 21:09:06 by mchihab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>


void ft_putnbr_unsigned(unsigned int n);
int ft_printf(const char *f, ...);
int ft_print_chr(int c);
int ft_print_hex(unsigned long n);
int ft_print_upper_hex(unsigned long n);
void ft_putnbr_unsigned(unsigned int n) ;
int ft_print_string(char *str);
char	*ft_strdup(const char *s1);
int ft_putnbr(int nb);
#endif