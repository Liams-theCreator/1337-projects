/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strfunc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imellali <imellali@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 10:28:27 by imellali          #+#    #+#             */
/*   Updated: 2025/02/02 17:46:00 by imellali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	ft_countword(const char *str, char c)
{
	int		word;
	size_t	i;

	word = 0;
	i = 0;
	if (str == NULL)
		return (-1);
	while (str[i] != '\0')
	{
		while (str[i] != '\0' && str[i] == c)
			i++;
		if (str[i] != '\0' && str[i] != c)
			word++;
		while (str[i] != '\0' && str[i] != c)
			i++;
	}
	return (word);
}

static char	*ft_mallocing(const char *str, char c)
{
	size_t	i;
	size_t	len;
	char	*buffer;

	i = 0;
	len = 0;
	while (str[len] != '\0' && str[len] != c)
		len++;
	buffer = malloc(sizeof(char) * (len + 1));
	if (buffer == NULL)
		return (NULL);
	while (i < len)
	{
		buffer[i] = str[i];
		i++;
	}
	buffer[i] = '\0';
	return (buffer);
}

static char	**ft_free(char **buffer)
{
	size_t	i;

	i = 0;
	while (buffer[i] != NULL)
	{
		free(buffer[i]);
		i++;
	}
	free(buffer);
	return (NULL);
}

static char	**ft_insert(char const *s, char **buffer, char c)
{
	size_t	i;
	size_t	idx;

	i = 0;
	idx = 0;
	while (s[i] != '\0')
	{
		while (s[i] != '\0' && s[i] == c)
			i++;
		if (s[i] != '\0' && s[i] != c)
		{
			buffer[idx] = ft_mallocing((s + i), c);
			if (buffer[idx] == NULL)
			{
				ft_free(buffer);
				return (NULL);
			}
			idx++;
		}
		while (s[i] != '\0' && s[i] != c)
			i++;
	}
	buffer[idx] = NULL;
	return (buffer);
}

char	**ft_split(char const *s, char c)
{
	int		word;
	char	**buffer;

	if (s == NULL)
		return (NULL);
	word = ft_countword(s, c);
	buffer = malloc(sizeof(char *) * (word + 1));
	if (buffer == NULL)
		return (NULL);
	buffer = ft_insert(s, buffer, c);
	if (!buffer)
	{
		free(buffer);
		return (NULL);
	}
	return (buffer);
}
