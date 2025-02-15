/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strfunc2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imellali <imellali@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 10:30:42 by imellali          #+#    #+#             */
/*   Updated: 2025/02/15 12:39:37 by imellali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

size_t	ft_strlen(const char *s)
{
	int	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

static size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	srclen;
	size_t	i;

	i = 0;
	srclen = ft_strlen(src);
	if (dstsize == 0)
		return (srclen);
	if (dstsize > srclen)
	{
		while (src[i] != '\0')
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
		return (srclen);
	}
	while (i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (srclen);
}

static size_t	ft_checkin(char c)
{
	char	chr[7];
	size_t	i;

	i = 0;
	ft_strlcpy(chr, " \t\v\r\n\f", 8);
	while (chr[i] != '\0')
	{
		if (chr[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_atoi(const char *str, char **array, t_lista **list)
{
	int			i;
	int			sign;
	long long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (ft_checkin(str[i]) == 1)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	if ((result * sign) < -2147483648 || (result * sign) > 2147483647)
		exiting(array, list);
	return ((int)(result * sign));
}
