/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnanchen <thomasnanchen@hotmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 11:30:54 by tnanchen          #+#    #+#             */
/*   Updated: 2021/12/11 16:52:22 by tnanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(int error_code)
{
	ft_putstr_fd(RED, 2);
	ft_putstr_fd("Error\n", 2);
	exit(error_code);
}

int	stack_length(int **num_list)
{
	int	i;

	i = 0;
	while (num_list[i])
		i++;
	return (i);
}

void	print_num_list(int *num_list)
{
	int	i;
	int	n;

	i = 1;
	n = num_list[0];
	ft_printf("\nNUM LIST :\n");
	while (n--)
	{
		ft_printf("%d | %p\n", num_list[i], &num_list[i]);
		i++;
	}
	ft_printf("\n");
}

void	print_stack(t_int_stack *stack, char name)
{
	int	i;

	i = 0;
	if (name == 'a')
		ft_printf("\n");
	ft_printf("STACK %c :\n", name);
	while (stack->num_list[i] != NULL)
	{
		ft_printf("%d (%p)\n", *stack->num_list[i], stack->num_list[i]);
		i++;
	}
	ft_printf("\n");
}

int	is_sorted(t_int_stack *stack_a)
{
	int	i;

	i = 0;
	while (stack_a->num_list[i] != NULL)
	{
		if (stack_a->num_list[i + 1] == NULL)
			return (0);
		if ((*stack_a->num_list[i] > *stack_a->num_list[i + 1]))
			return (-1);
		i++;
	}
	return (0);
}
