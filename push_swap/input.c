/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imellali <imellali@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 10:47:19 by imellali          #+#    #+#             */
/*   Updated: 2025/02/15 15:29:50 by imellali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	ft_intcheck(char *number)
{
	int	i;

	i = 0;
	if (number[i] == '-' || number[i] == '+')
	{
		if (number[i + 1] == '\0')
			return (-1);
		i++;
	}
	while (number[i])
	{
		if (number[i] < '0' || number[i] > '9')
			return (-1);
		i++;
	}
	return (0);
}

t_lista	*ft_parsing(int argc, char **argv)
{
	char	**temp_arr;
	int		i;
	int		j;
	t_lista	*list;

	i = 1;
	list = NULL;
	while (i < argc)
	{
		temp_arr = ft_split(argv[i], ' ');
		if (!temp_arr || !temp_arr[0])
			exiting(temp_arr, &list);
		j = 0;
		while (temp_arr[j])
		{
			if (ft_intcheck(temp_arr[j]) == -1)
				exiting(temp_arr, &list);
			ft_add_to_list(&list, temp_arr,
				ft_atoi(temp_arr[j], temp_arr, &list));
			j++;
		}
		free_array(temp_arr);
		i++;
	}
	return (list);
}
