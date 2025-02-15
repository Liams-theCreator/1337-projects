/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listfunc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imellali <imellali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 10:46:37 by imellali          #+#    #+#             */
/*   Updated: 2025/02/15 12:25:47 by imellali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	list_len(t_lista *h)
{
	int	len;

	len = 0;
	while (h)
	{
		h = h->next;
		len++;
	}
	return (len);
}

t_lista	*ft_create_node(t_lista **head, int num)
{
	t_lista	*node;
	t_lista	*temp;

	temp = *head;
	node = malloc(sizeof(t_lista));
	if (!node)
		return (NULL);
	node->num = num;
	node->next = NULL;
	if (*head == NULL)
	{
		*head = node;
		return (node);
	}
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = node;
	return (node);
}

void	ft_add_to_list(t_lista **head, char **array, int num)
{
	t_lista	*current;

	current = *head;
	while (current)
	{
		if (current->num == num)
			exiting(array, head);
		current = current->next;
	}
	ft_create_node(head, num);
}
