/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imellali <imellali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 11:06:48 by imellali          #+#    #+#             */
/*   Updated: 2025/02/15 12:17:41 by imellali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	find_idx(t_lista *stack_a, int num)
{
	int		idx;
	t_lista	*head;

	idx = 0;
	head = stack_a;
	while (head)
	{
		if (num == head->num)
			return (idx);
		idx++;
		head = head->next;
	}
	return (-1);
}

int	find_largest(t_lista *stack)
{
	int		largest;
	t_lista	*head;

	largest = stack->num;
	head = stack;
	while (head)
	{
		if (head->num > largest)
			largest = head->num;
		head = head->next;
	}
	return (largest);
}

int	find_smallest(t_lista *stack)
{
	int		smallest;
	t_lista	*head;

	smallest = stack->num;
	head = stack;
	while (head)
	{
		if (head->num < smallest)
			smallest = head->num;
		head = head->next;
	}
	return (smallest);
}

void	shift_2top_a(t_lista **stack_a, int index)
{
	int	length;

	length = list_len(*stack_a) / 2;
	if (index <= length)
		perfom_ra(stack_a, index);
	else
		perfom_rra(stack_a, index);
}

void	shift_2top_b(t_lista **stack_b, int position)
{
	int	length;

	length = list_len(*stack_b) / 2;
	if (position <= length)
		perfom_rb(stack_b, position);
	else if (position > length)
		perfom_rrb(stack_b, position);
}
