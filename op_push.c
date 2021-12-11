/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnanchen <thomasnanchen@hotmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 10:48:24 by tnanchen          #+#    #+#             */
/*   Updated: 2021/12/11 16:40:57 by tnanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	stack_shift_one_up(t_int_stack *stack)
{
	int	i;

	i = 0;
	while (stack->num_list[i])
	{
		stack->num_list[i] = stack->num_list[i + 1];
		i++;
	}
}

static void	stack_shift_one_down(t_int_stack *stack)
{
	int	i;
	int	n;

	i = 0;
	n = stack_length(stack->num_list);
	while (n--)
	{
		stack->num_list[n + 1] = stack->num_list[n];
		i++;
	}
}

int	push(t_int_stack *stack_dst, t_int_stack *stack_src)
{
	int	src_exists;
	int	*temp;

	src_exists = 0;
	if (*stack_src->num_list)
	{
		temp = *stack_src->num_list;
		stack_shift_one_up(stack_src);
		stack_shift_one_down(stack_dst);
		*stack_dst->num_list = temp;
		src_exists = 1;
	}
	ft_putchar_fd('p', 1);
	ft_putchar_fd(stack_dst->name, 1);
	ft_putchar_fd('\n', 1);
	if (src_exists)
		return (0);
	return (-1);
}
