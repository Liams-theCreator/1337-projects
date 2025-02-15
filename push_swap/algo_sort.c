/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imellali <imellali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 14:29:57 by imellali          #+#    #+#             */
/*   Updated: 2025/02/15 12:14:07 by imellali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	sorting_algorithm(t_lista **stack_a, t_lista **stack_b)
{
	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	while (list_len(*stack_a) > 3)
	{
		if (sorted(*stack_a) == 0)
			break ;
		push_a2b(stack_a, stack_b);
	}
	if ((sorted(*stack_a)) == -1 && list_len(*stack_a) == 3)
		sort_three(stack_a);
	push_b2a(stack_a, stack_b);
	if (sorted(*stack_a) == -1)
		shift_2top_a(stack_a, find_idx(*stack_a, find_smallest(*stack_a)));
}
