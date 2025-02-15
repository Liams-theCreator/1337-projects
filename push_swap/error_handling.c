/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imellali <imellali@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 16:59:37 by imellali          #+#    #+#             */
/*   Updated: 2025/02/01 23:42:17 by imellali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(44);
}

void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	free_list(t_lista **head)
{
	t_lista	*temp;

	while (*head)
	{
		temp = *head;
		*head = temp->next;
		free(temp);
	}
	*head = NULL;
}

int	sorted(t_lista	*stack)
{
	t_lista	*head;

	head = stack;
	while (head && head->next)
	{
		if (head->next->num < head->num)
			return (-1);
		head = head->next;
	}
	return (0);
}

void	exiting(char **array, t_lista **list)
{
	free_array(array);
	free_list(list);
	ft_error();
}
