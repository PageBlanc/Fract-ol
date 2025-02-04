/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axdubois <axdubois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 22:38:39 by axdubois          #+#    #+#             */
/*   Updated: 2023/12/02 20:11:12 by axdubois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_manadress(long long ap)
{
	int	len;

	len = 0;
	if (ap == 0)
		return (ft_putstr("(nil)"));
	len = ft_putstr("0x");
	len += (ft_putnbr_ubase(ap, "0123456789abcdef"));
	return (len);
}

int	ft_checkformat(char f, va_list *ap)
{
	int	len;

	len = 0;
	if (f == 's')
		len = (ft_putstr(va_arg(*ap, char *)));
	else if (f == 'c')
		len = (ft_putchar(va_arg(*ap, int)));
	else if (f == 'p')
		len = ft_manadress(va_arg(*ap, long long));
	else if (f == 'd' || f == 'i')
		len = (ft_putnbr_base(va_arg(*ap, int), "0123456789"));
	else if (f == 'u')
		len = (ft_putnbr_ubase(va_arg(*ap, unsigned int), "0123456789"));
	else if (f == 'x')
		len = (ft_putnbr_ubase(va_arg(*ap, unsigned int), "0123456789abcdef"));
	else if (f == 'X')
		len = (ft_putnbr_ubase(va_arg(*ap, unsigned int), "0123456789ABCDEF"));
	else if (f == '%')
		len = ft_putchar('%');
	return (len);
}

int	ft_printf(const char *format, ...)
{
	int			len;
	size_t		i;
	va_list		ap;

	if (!format)
		return (-1);
	len = 0;
	i = 0;
	va_start(ap, format);
	while (i < ft_strlen(format) && format[i])
	{
		if (format[i] == 37)
		{
			if (!format[i + 1])
				return (-1);
			len += ft_checkformat(format[i + 1], &ap);
			i += 2;
		}
		else
			len += ft_putchar(format[i++]);
	}
	va_end(ap);
	return (len);
}
