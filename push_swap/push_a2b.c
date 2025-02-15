/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_a2b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imellali <imellali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 16:34:22 by imellali          #+#    #+#             */
/*   Updated: 2025/02/15 13:37:37 by imellali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	minimum(int num1, int num2)
{
	if (num1 < num2)
		return (num1);
	return (num2);
}

static int	calcul_moves(t_lista *stack_a, int num, t_lista *stack_b, int pos)
{
	int	cost_in_a;
	int	cost_in_b;
	int	index;

	index = find_idx(stack_a, num);
	cost_in_a = minimum(index, list_len(stack_a) - index);
	cost_in_b = minimum(pos, list_len(stack_b) - pos);
	return (cost_in_a + cost_in_b);
}

int	find_position(t_lista *stack_b, int num)
{
	int		position;
	int		largest;
	int		smallest;
	t_lista	*head;

	largest = find_largest(stack_b);
	smallest = find_smallest(stack_b);
	if (num > largest)
		return (find_idx(stack_b, largest) + 1);
	else if (num < smallest)
		return (find_idx(stack_b, smallest) + 1);
	head = stack_b;
	position = 0;
	while (head && head->next)
	{
		if (head->num > num && num > head->next->num)
			return (position + 1);
		position++;
		head = head->next;
	}
	return (position + 1);
}

static void	shift_and_push(t_lista **stack_a, t_lista **stack_b, int number)
{
	int	index_a;
	int	position_b;
	int	length_a;
	int	length_b;

	index_a = find_idx(*stack_a, number);
	position_b = find_position(*stack_b, number);
	length_a = list_len(*stack_a);
	length_b = list_len(*stack_b);
	while (index_a > 0 && position_b > 0
		&& index_a <= length_a / 2 && position_b <= length_b / 2)
	{
		rr(stack_a, stack_b);
		index_a--;
		position_b--;
	}
	while (index_a < length_a && position_b < length_b
		&& index_a > length_a / 2 && position_b > length_b / 2)
	{
		rrr(stack_a, stack_b);
		index_a++;
		position_b++;
	}
}

void	push_a2b(t_lista **stack_a, t_lista **stack_b)
{
	int		moves;
	int		cheap_moves;
	t_lista	*node;
	t_lista	*cheap_num;

	moves = 44444444;
	cheap_num = NULL;
	node = *stack_a;
	while (node)
	{
		cheap_moves = calcul_moves(*stack_a, node->num, *stack_b,
				find_position(*stack_b, node->num));
		if (cheap_moves < moves)
		{
			moves = cheap_moves;
			cheap_num = node;
		}
		node = node->next;
	}
	shift_and_push(stack_a, stack_b, cheap_num->num);
	shift_2top_a(stack_a, find_idx(*stack_a, cheap_num->num));
	shift_2top_b(stack_b, find_position(*stack_b, cheap_num->num));
	pb(stack_a, stack_b);
}
