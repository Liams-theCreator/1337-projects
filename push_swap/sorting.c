/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imellali <imellali@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 17:00:04 by imellali          #+#    #+#             */
/*   Updated: 2025/02/01 22:42:58 by imellali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	sort_two(t_lista **stack_a)
{
	if ((*stack_a)->next->num < (*stack_a)->num)
		sa(stack_a, 1);
}

void	sort_three(t_lista **stack_a)
{
	int	fst;
	int	sec;
	int	trd;

	fst = (*stack_a)->num;
	sec = (*stack_a)->next->num;
	trd = (*stack_a)->next->next->num;
	if (fst > sec && sec > trd)
	{
		sa(stack_a, 1);
		rra(stack_a, 1);
	}
	else if (fst > trd && trd > sec)
		ra(stack_a, 1);
	else if (sec > fst && fst > trd)
		rra(stack_a, 1);
	else if (sec > trd && trd > fst)
	{
		sa(stack_a, 1);
		ra(stack_a, 1);
	}
	else if (trd > fst && fst > sec)
		sa(stack_a, 1);
}
