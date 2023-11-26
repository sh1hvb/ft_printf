/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchihab <mchihab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 16:01:37 by mchihab           #+#    #+#             */
/*   Updated: 2023/11/25 20:02:41 by mchihab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <unistd.h>

int	ft_printf_format(char spex, va_list ap)
{
	int	count;

	count = 0;
	if (spex == 'c')
		count += ft_print_chr(va_arg(ap, int));
	else if (spex == 's')
		count += ft_print_string(va_arg(ap, char *));
	else if (spex == 'p')
		count += (write(1, "0x", 2) + ft_print_hex((unsigned long)va_arg(ap,
						char *)) + 2);
	else if (spex == 'd' || spex == 'i')
		count += ft_putnbr(va_arg(ap, int));
	else if (spex == 'u')
		count += ft_print_u_nbr(va_arg(ap, unsigned int));
	else if (spex == 'x')
		count += ft_print_hex(va_arg(ap, unsigned int));
	else if (spex == 'X')
		count += ft_print_upper_hex(va_arg(ap, unsigned int));
	else if (spex == '%')
		count += write(1, &spex, 1);
	else
		count += write(1, &spex, 1);
	return (count);
}
int	ft_printf(const char *f, ...)
{
	va_list	ap;
	int		count;

	va_start(ap, f);
	count = 0;
	while ((*f))
	{
		if (*f == '%')
			count += ft_printf_format(*(++f), ap);
		else
			count += write(1, f, 1);
		++f;
	}
	va_end(ap);
	return (count);
}
int	main(void)
{
	ft_printf("%X", 123);
}
