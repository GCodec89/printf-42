/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gonolive <gonolive@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 11:31:12 by gonolive          #+#    #+#             */
/*   Updated: 2024/05/03 14:19:02 by gonolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int				ft_printf(const char *str, ...);
int				ft_putchar(char c);
int				ft_printstr(char *str);
void			ft_putstr(char *str);
int				ft_printptr(void *nbr);
int				ft_putptrhex(unsigned long nbr, const char c);
int				ft_printnbr(int nbr);
int				ft_utoa(unsigned int nbr);
unsigned int	ft_usize(unsigned int nbr);

#endif