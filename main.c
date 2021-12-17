/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnanchen <thomasnanchen@hotmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 21:21:47 by tnanchen          #+#    #+#             */
/*   Updated: 2021/12/17 10:28:42 by tnanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	choose_sorting_algo(t_int_stack *a, t_int_stack *b)
{
	int	total;

	total = stack_length(a->num_list);
	if (total == 2)
		sort_2num(a);
	if (total == 3)
		sort_3num(a);
	if (total == 4)
		sort_4num(a, b);
	if (total == 5)
		sort_5num(a, b);
	if (total >= 6 && total <= 7)
		one_stack_swapping(a);

	if (total > 7)
		sort_packages(a, b);
	// if (total > 7 && total <= 30)
	// 	divide_sort_and_fusion(a, b);
	// if (total > 30)
	// 	sort_radix(a, b);

}

int	main(int ac, char **av)
{
	char			**arg_list;
	int				arg_split;
	int				*num_list;
	t_int_stack		a;
	t_int_stack		b;

	arg_split = 0;
	num_list = NULL;
	arg_list = arg_list_create(ac, av, &arg_split);
	num_list = arg_checker(arg_list, num_list, arg_split);
	stack_init(&a, num_list, 'a');
	stack_init(&b, num_list, 'b');
	choose_sorting_algo(&a, &b);
	free(num_list);
	free(a.num_list);
	free(b.num_list);
	return (0);
}
