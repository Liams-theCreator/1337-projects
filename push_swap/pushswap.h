/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imellali <imellali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 10:32:41 by imellali          #+#    #+#             */
/*   Updated: 2025/02/15 15:29:38 by imellali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct list_a
{
	int				num;
	struct list_a	*next;
}	t_lista;

// string functions
size_t	ft_strlen(const char *s);
char	**ft_split(char const *s, char c);
char	*ft_strdup(const char *s);
int		ft_atoi(const char *str, char **array, t_lista **list);
int		ft_strcmp(char *s1, char *s2);

// input functions
t_lista	*ft_parsing(int argc, char **argv);

// linked list functions
t_lista	*ft_create_node(t_lista **head, int num);
void	ft_add_to_list(t_lista **head, char **array, int num);
int		list_len(t_lista *h);

// error handling functions
void	ft_error(void);
void	free_array(char **array);
void	free_list(t_lista **head);
void	exiting(char **array, t_lista **list);
int		sorted(t_lista *stack);

// operations functions
void	sa(t_lista **stack, int msg);
void	sb(t_lista **stack, int msg);
void	ss(t_lista **stack_a, t_lista **stack_b);
void	ra(t_lista **stack, int msg);
void	rb(t_lista **stack, int msg);
void	rr(t_lista **stack_a, t_lista **stack_b);
void	rra(t_lista **stack, int msg);
void	rrb(t_lista **stack, int msg);
void	rrr(t_lista **stack_a, t_lista **stack_b);
void	pa(t_lista **stack_a, t_lista **stack_b);
void	pb(t_lista **stack_a, t_lista **stack_b);

// sorting functions
void	sorting_algorithm(t_lista **stack_a, t_lista **stack_b);
void	push_b2a(t_lista **stack_a, t_lista **stack_b);
void	push_a2b(t_lista **stack_a, t_lista **stack_b);
void	sort_two(t_lista **stack_a);
void	sort_three(t_lista **stack_a);
void	sort_four(t_lista **stack_a, t_lista **stack_b);
void	sort_five(t_lista **stack_a, t_lista **stack_b);

// utils functions
int		find_idx(t_lista *stack_a, int num);
int		find_largest(t_lista *stack);
int		find_smallest(t_lista *stack);
int		find_position(t_lista *stack_b, int num);
int		find_pos(t_lista *stack_a, int num);

// perfom operations functions
void	perfom_ra(t_lista **stack_a, int index);
void	perfom_rra(t_lista **stack_a, int index);
void	perfom_rb(t_lista **stack_a, int index);
void	perfom_rrb(t_lista **stack_a, int index);
void	shift_2top_a(t_lista **stack_a, int index);
void	shift_2top_b(t_lista **stack_a, int index);

#endif
