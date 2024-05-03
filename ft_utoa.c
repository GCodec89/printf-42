/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gonolive <gonolive@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 18:09:47 by gonolive          #+#    #+#             */
/*   Updated: 2024/05/03 11:53:11 by gonolive         ###   ########.fr       */
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
