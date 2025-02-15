/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imellali <imellali@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 16:23:31 by imellali          #+#    #+#             */
/*   Updated: 2025/02/03 14:37:43 by imellali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	shift_to_push4(t_lista **stack_a, t_lista **stack_b, int index)
{
	if (index == 0)
		pb(stack_a, stack_b);
	else if (index == 1)
	{
		sa(stack_a, 1);
		pb(stack_a, stack_b);
	}
	else if (index == 2)
	{
		ra(stack_a, 1);
		ra(stack_a, 1);
		pb(stack_a, stack_b);
	}
	else if (index == 3)
	{
		rra(stack_a, 1);
		pb(stack_a, stack_b);
	}
}

static void	shift_to_push5(t_lista **stack_a, t_lista **stack_b, int index)
{
	if (index == 0)
		pb(stack_a, stack_b);
	else if (index == 1)
	{
		sa(stack_a, 1);
		pb(stack_a, stack_b);
	}
	else if (index == 2)
	{
		ra(stack_a, 1);
		ra(stack_a, 1);
		pb(stack_a, stack_b);
	}
	else if (index == 3)
	{
		rra(stack_a, 1);
		rra(stack_a, 1);
		pb(stack_a, stack_b);
	}
	else if (index == 4)
	{
		rra(stack_a, 1);
		pb(stack_a, stack_b);
	}
}

void	sort_four(t_lista **stack_a, t_lista **stack_b)
{
	int	min_index;

	min_index = find_idx(*stack_a, find_smallest(*stack_a));
	shift_to_push4(stack_a, stack_b, min_index);
	sort_three(stack_a);
	pa(stack_a, stack_b);
}

void	sort_five(t_lista **stack_a, t_lista **stack_b)
{
	int	num1_idx;
	int	num2_idx;

	num1_idx = find_idx(*stack_a, find_smallest(*stack_a));
	shift_to_push5(stack_a, stack_b, num1_idx);
	num2_idx = find_idx(*stack_a, find_smallest(*stack_a));
	shift_to_push4(stack_a, stack_b, num2_idx);
	if ((sorted(*stack_a)) == -1)
		sort_three(stack_a);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
}
