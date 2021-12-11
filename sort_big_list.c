/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnanchen <thomasnanchen@hotmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 21:37:06 by tnanchen          #+#    #+#             */
/*   Updated: 2021/12/11 12:49:53 by tnanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Pseudo code
	// 1. push la moitié de a sur b (pas min et max)
	// 2. while a && b !sorted
		// 2.1 parallel sort (rotate_both / swap_both)
		// => a ou b est sorted
	// 3. while 2ème stack !sorted
		// 3.1 sort 1 stack
	// 4. while b a des num
		// 4.1 push les nums de b sur a au bon endroit (1 seule passe)
	// 5. finit la rotation de a pour mettre les num dans l'ordre
*/

static void divide_stack(t_int_stack *stack_a, t_int_stack *stack_b, int len)
{
	int min;
	int max;
	
	min = *stack_a->num_list[min_num_index(stack_a)];
	max = *stack_a->num_list[max_num_index(stack_a)];
	len = len / 2;
	while (len--)
	{	
		if (*stack_a->num_list[0] == min || *stack_a->num_list[0] == max)
		{
			rotate_one(stack_a);
			len++;
		}
		else
			push(stack_b, stack_a);
	}
}

static void parallel_sort(t_int_stack *stack_a, t_int_stack *stack_b)
{
	int min_a;
	int max_a;
	int min_b;
	int max_b;
	
	min_a = *stack_a->num_list[min_num_index(stack_a)];
	max_a = *stack_a->num_list[max_num_index(stack_a)];
	min_b = *stack_a->num_list[min_num_index(stack_b)];
	max_b = *stack_a->num_list[max_num_index(stack_b)];
	while ((is_sorted_unrotated(stack_a, min_a, max_a) < 0)
		&& (is_sorted_unrotated(stack_b, min_b, max_b) < 0))
	{
		if ((*stack_a->num_list[0] > *stack_a->num_list[1]) 
			&& (*stack_b->num_list[0] > *stack_b->num_list[1])
			&& !(*stack_a->num_list[0] == max_a && *stack_a->num_list[1] == min_a)
			&& !(*stack_b->num_list[0] == max_b && *stack_b->num_list[1] == min_b))
			swap_both(stack_a, stack_b);
		if (*stack_a->num_list[0] > *stack_a->num_list[1]
			&& !(*stack_a->num_list[0] == max_a && *stack_a->num_list[1] == min_a))
			swap_one(stack_a);
		if (*stack_b->num_list[0] > *stack_b->num_list[1]
			&& !(*stack_b->num_list[0] == max_b && *stack_b->num_list[1] == min_b))
			swap_one(stack_b);
		rotate_both(stack_a, stack_b);
	}
}

static void finish_sort(t_int_stack *stack_a, t_int_stack *stack_b, int len)
{
	int min_a;
	int max_a;
	int min_b;
	int max_b;

	min_a = *stack_a->num_list[min_num_index(stack_a)];
	max_a = *stack_a->num_list[max_num_index(stack_a)];
	min_b = *stack_b->num_list[min_num_index(stack_b)];
	max_b = *stack_b->num_list[max_num_index(stack_b)];
	if (is_sorted_unrotated(stack_a, min_a, max_a) < 0)
	{
		if (len < 29)
			one_stack_swapping(stack_a);
		else
			insertion_sort(stack_a, stack_b);
	}
	if (is_sorted_unrotated(stack_b, min_b, max_b) < 0)
	{	
		if (len < 29)
			one_stack_swapping(stack_b);
		else
			insertion_sort(stack_b, stack_a);
	}
}


void	divide_and_sort(t_int_stack *stack_a, t_int_stack *stack_b)
{
	int len;
	int i;
	
	len = stack_length(stack_a->num_list);
	
	// 1. push la moitié de a sur b
	divide_stack(stack_a, stack_b, len);
	
	// 2. trie les 2 stack en parallel jusqu'a ce qu'une des deux soit intégralement triée
	parallel_sort(stack_a, stack_b);

	// 3. finit le trie sur la stack pas triée complètement
	finish_sort(stack_a, stack_b, len);
	
	// 4. push les nums de b sur a au bon endroit (1 seule passe)
	while (stack_b->num_list[0] != NULL) 
	{
		if ((*stack_b->num_list[0] > *stack_a->num_list[0])
			&& (*stack_b->num_list[0] < *stack_a->num_list[1]))
		{
			rotate_one(stack_a);
			push(stack_a, stack_b);
		}
		else
			rotate_one(stack_a);	
	}

	// // 5. finit la rotation de a pour mettre les num dans l'ordre
	i = min_num_index(stack_a);
	while (is_sorted(stack_a) < 0)
		best_rotate(stack_a, i);
}
