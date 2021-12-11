/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnanchen <thomasnanchen@hotmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 21:21:47 by tnanchen          #+#    #+#             */
/*   Updated: 2021/12/11 12:56:14 by tnanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	choose_algo(t_int_stack *stack_a, t_int_stack *stack_b)
{
	int	total;

	total = stack_length(stack_a->num_list);
	if (total == 2)
		sort_2num(stack_a);
	if (total == 3)
		sort_3num(stack_a);
	if (total == 4)
		sort_4num(stack_a, stack_b);
	if (total == 5)
		sort_5num(stack_a, stack_b);
	if (total >= 6 && total <= 7)
		one_stack_swapping(stack_a);
	if (total > 7)
		divide_and_sort(stack_a, stack_b);
}

int	main(int ac, char **av)
{
	char			**arg_list;
	int				arg_split;
	int				*num_list;
	t_int_stack		stack_a;
	t_int_stack		stack_b;

	arg_split = 0;
	num_list = NULL;
	arg_list = arg_list_create(ac, av, &arg_split);
	num_list = arg_checker(arg_list, num_list, arg_split);
	stack_init(&stack_a, num_list, 'a');
	stack_init(&stack_b, num_list, 'b');
	choose_algo(&stack_a, &stack_b);
	free(num_list);
	free(stack_a.num_list);
	free(stack_b.num_list);
	return (0);
}
