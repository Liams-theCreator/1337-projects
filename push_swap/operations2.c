/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imellali <imellali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 18:35:48 by imellali          #+#    #+#             */
/*   Updated: 2025/02/15 12:25:21 by imellali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	pb(t_lista **stack_a, t_lista **stack_b)
{
	t_lista	*head;
	t_lista	*new_head;

	head = *stack_a;
	new_head = (*stack_a)->next;
	if (!(stack_b))
	{
		head->next = NULL;
		*stack_b = head;
	}
	head->next = *stack_b;
	(*stack_b) = head;
	*stack_a = new_head;
	write(1, "pb\n", 3);
}

void	pa(t_lista **stack_a, t_lista **stack_b)
{
	t_lista	*head;
	t_lista	*new_head;

	if (!(*stack_b))
		return ;
	head = *stack_b;
	new_head = (*stack_b)->next;
	head->next = *stack_a;
	*stack_a = head;
	*stack_b = new_head;
	write(1, "pa\n", 3);
}

void	sa(t_lista **stack, int msg)
{
	t_lista	*old_head;
	t_lista	*new_head;

	old_head = *stack;
	new_head = (*stack)->next;
	if (!(*stack) || !(*stack)->next)
		ft_error();
	old_head->next = new_head->next;
	new_head->next = old_head;
	*stack = new_head;
	if (msg == 1)
		write(1, "sa\n", 3);
}

void	sb(t_lista **stack, int msg)
{
	t_lista	*old_head;
	t_lista	*new_head;

	old_head = *stack;
	new_head = (*stack)->next;
	if (!(*stack) || !(*stack)->next)
		ft_error();
	old_head->next = new_head->next;
	new_head->next = old_head;
	*stack = new_head;
	if (msg == 1)
		write(1, "sb\n", 3);
}
