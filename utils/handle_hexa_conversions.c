/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_hexa_conversions.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaroni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 16:09:00 by amaroni           #+#    #+#             */
/*   Updated: 2021/03/26 11:17:32 by amaroni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

char	conversion_hex_table(unsigned long input, char c)
{
	if (input > 9 && c == 'x')
		return ('a' + (input - 10));
	if (input > 9 && c == 'X')
		return ('A' + (input - 10));
	return ('0' + input);
}

char	*int2hexstring(unsigned long input, char c, size_t size)
{
	char	*str;
	char	*output;
	int		i;
	int		y;

	if (!input)
		return (ft_strdup("0"));
	i = 0;
	str = (char*)ft_calloc(size + 1, sizeof(*str));
	while (input)
	{
		str[i] = conversion_hex_table(input % 16, c);
		i++;
		input /= 16;
	}
	i = ft_strlen(str);
	y = 0;
	output = ft_strdup(str);
	while (i-- > 0)
	{
		output[y] = str[i];
		y++;
	}
	free(str);
	return (output);
}
