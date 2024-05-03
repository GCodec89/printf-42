/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gonolive <gonolive@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 11:36:22 by gonolive          #+#    #+#             */
/*   Updated: 2024/05/03 13:53:16 by gonolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	ft_usize(unsigned int nbr)
{
	unsigned int	count;

	count = 0;
	while (nbr)
	{
		count ++;
		nbr = nbr / 10;
	}
	return (count);
}

int	ft_utoa(unsigned int nbr)
{
	char	*str;
	int		size;
	int		result;

	size = ft_usize(nbr);
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (!str)
	{
		return (0);
	}
	str[size] = '\0';
	while (nbr)
	{
		size --;
		str[size] = (nbr % 10) + 48;
		nbr = nbr / 10;
	}
	result = ft_printstr(str);
	free(str);
	return (result);
}

int	ft_printnbr(int nbr)
{
	int	result;

	result = 0;
	if (nbr < 0)
	{
		result += ft_putchar('-');
		nbr *= -1;
	}
	if (nbr < 10)
	{
		result += ft_putchar(nbr + 48);
	}
	else
	{
		result += ft_printnbr(nbr / 10);
		result += ft_printnbr(nbr % 10);
	}
	return (result);
}

int	ft_putptrhex(unsigned long nbr, const char c)
{
	char	*base;
	int		result;

	result = 0;
	if (c == 'x')
	{
		base = "0123456789abcdef";
	}
	if (c == 'X')
	{
		base = "0123456789ABCDEF";
	}
	if (nbr >= 16)
	{
		result += ft_putptrhex((nbr / 16), c);
		result += ft_putptrhex((nbr % 16), c);
	}
	else
	{
		result += write(1, &base[nbr], 1);
	}
	return (result);
}

int	ft_printptr(void *nbr)
{
	int				result;
	unsigned long	n;

	n = (unsigned long)nbr;
	result = 0;
	if (!n)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	result += ft_printstr("0x");
	if (n == 0)
	{
		result += ft_putchar(0);
	}
	else
	{
		result += ft_putptrhex(n, 'x');
	}
	return (result);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	ft_printstr(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		ft_putstr("(nil)");
		return (5);
	}
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_putchar(char c)
{
		int	result;

	result = 0;
	result += write (1, &c, 1);
	return (result);
}

static int	ft_arg(const char *format, int i, va_list ap)
{
	if (format[i + 1] == 'c')
		return (ft_putchar(va_arg(ap, int)));
	else if (format[i + 1] == 's')
		return (ft_printstr(va_arg(ap, char *)));
	else if (format[i + 1] == 'p')
		return (ft_printptr(va_arg(ap, void *)));
	else if (format[i + 1] == 'd' || format[i + 1] == 'i')
		return (ft_printnbr(va_arg(ap, int)));
	else if (format[i + 1] == 'u')
		return (ft_utoa(va_arg(ap, unsigned int)));
	else if (format[i + 1] == 'x')
		return (ft_putptrhex(va_arg(ap, unsigned int), 'x'));
	else if (format[i + 1] == 'X')
		return (ft_putptrhex(va_arg(ap, unsigned int), 'X'));
	else if (format[i + 1] == '%')
		return (ft_putchar(format[i + 1]));
	else
		return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	int		result;

	i = 0;
	result = 0;
	if (!format || *format == '\0')
		return (0);
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			result += ft_arg(format, i, ap);
			i++;
		}
		else
		{
			result += ft_putchar(format[i]);
		}
		i++;
	}
	va_end(ap);
	return (result);
}

int	main(void)
{
	char			c = 'y'; //%c
	char			*str = "A string"; //%s
	char			*var; var = &c; //%p
	int				nbr = -5; // %d // %i
	unsigned int	nbrr = 20;// %u
	int 			a = 0xffffffff;// %x
	ft_printf("Characters: %c \n", c);
	printf("Characters: %c \n", c);
	ft_printf ("This is what? %s \n", str);
	printf ("This is what? %s \n", str);
	ft_printf ("Pointer address: %p \n", var);
	printf ("Pointer address: %p \n", var);
	ft_printf ("Decimals: %d \n", nbr);
	printf ("Decimals: %d \n", nbr);
	ft_printf("We present you an unsigned int %u \n", nbrr);
	printf("We present you an unsigned int %u \n", nbrr);
	ft_printf("Lower case hex %x \n", a);
	printf("Lower case hex %x \n", a);
	ft_printf("Upper case hex %X \n", a);
	printf("Upper case hex %X \n", a);
	ft_printf("Olha percentagem %% \n");
	printf("Olha percentagem %% \n");
	return (0);
}
