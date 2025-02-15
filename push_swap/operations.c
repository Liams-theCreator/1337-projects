/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imellali <imellali@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 10:47:53 by imellali          #+#    #+#             */
/*   Updated: 2025/02/05 12:13:08 by imellali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ra(t_lista **stack, int msg)
{
	t_lista	*old_head;
	t_lista	*current;
	t_lista	*new_head;

	current = *stack;
	old_head = *stack;
	new_head = (*stack)->next;
	if (!(*stack) || !(*stack)->next)
		ft_error();
	while (current->next)
		current = current->next;
	current->next = old_head;
	old_head->next = NULL;
	*stack = new_head;
	if (msg == 1)
		write(1, "ra\n", 3);
}

void	rb(t_lista **stack, int msg)
{
	t_lista	*old_head;
	t_lista	*current;
	t_lista	*new_head;

	current = *stack;
	old_head = *stack;
	new_head = (*stack)->next;
	if (!(*stack) || !(*stack)->next)
		ft_error();
	while (current->next)
		current = current->next;
	current->next = old_head;
	old_head->next = NULL;
	*stack = new_head;
	if (msg == 1)
		write(1, "rb\n", 3);
}

void	rra(t_lista **stack, int msg)
{
	t_lista	*old_head;
	t_lista	*new_head;
	t_lista	*current;
	t_lista	*temp;

	current = *stack;
	old_head = *stack;
	if (!(*stack) || !(*stack)->next)
		ft_error();
	while (current->next)
	{
		if (current->next->next == NULL)
			temp = current;
		current = current->next;
	}
	new_head = current;
	new_head->next = old_head;
	temp->next = NULL;
	*stack = new_head;
	if (msg == 1)
		write(1, "rra\n", 4);
}

void	rrb(t_lista **stack, int msg)
{
	t_lista	*old_head;
	t_lista	*new_head;
	t_lista	*current;
	t_lista	*temp;

	current = *stack;
	old_head = *stack;
	if (!(*stack) || !(*stack)->next)
		ft_error();
	while (current->next)
	{
		if (current->next->next == NULL)
			temp = current;
		current = current->next;
	}
	new_head = current;
	new_head->next = old_head;
	temp->next = NULL;
	*stack = new_head;
	if (msg == 1)
		write(1, "rrb\n", 4);
}
