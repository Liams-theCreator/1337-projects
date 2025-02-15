/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perfoms.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imellali <imellali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 18:28:03 by imellali          #+#    #+#             */
/*   Updated: 2025/02/15 12:24:09 by imellali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	perfom_ra(t_lista **stack_a, int index)
{
	int	i;

	i = 0;
	while (i < index)
	{
		ra(stack_a, 1);
		i++;
	}
}

void	perfom_rra(t_lista **stack_a, int index)
{
	int	len;

	len = list_len(*stack_a) - 1;
	while (len >= index)
	{
		rra(stack_a, 1);
		len--;
	}
}

void	perfom_rb(t_lista **stack_b, int index)
{
	int	i;

	i = 0;
	while (i < index)
	{
		rb(stack_b, 1);
		i++;
	}
}

void	perfom_rrb(t_lista **stack_b, int index)
{
	int	len;

	len = list_len(*stack_b) - 1;
	while (len >= index)
	{
		rrb(stack_b, 1);
		len--;
	}
}
