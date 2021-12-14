/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnanchen <thomasnanchen@hotmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 22:44:18 by tnanchen          #+#    #+#             */
/*   Updated: 2021/12/11 16:40:38 by tnanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**arg_list_create(int ac, char **av, int *arg_split)
{
	char	**arg_list;

	if (ac == 2)
		arg_list = ft_split(av[1], ' ');
	else
		arg_list = ++av;
	if (ac == 2)
		*arg_split = 1;
	return (arg_list);
}

static int	*arg_to_int(char **arg_list, int *num_list, size_t arg_size)
{
	int	i;
	int	*num_list_ptr;

	*num_list = arg_size;
	num_list_ptr = num_list;
	num_list++;
	i = -1;
	while (arg_list[++i])
	{
		*num_list = ft_atoi(arg_list[i]);
		num_list++;
	}
	return (num_list_ptr);
}

static void	check_duplicates(int *num_list)
{
	int		n;
	int		i;
	int		j;
	int		*num_list_ptr;

	n = num_list[0];
	i = 0;
	j = 0;
	num_list_ptr = num_list;
	while (j < n)
	{
		num_list++;
		while (++i < (n - j))
		{
			if (*num_list == num_list[i])
			{
				free(num_list_ptr);
				error(DUPLICATES_ARG);
			}
		}
		i = 0;
		j++;
	}
}

int	*arg_checker(char **arg, int *num_list, int arg_split)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (arg[++i])
	{
		if (arg[i][j] == '+' || arg[i][j] == '-')
			j++;
		while (arg[i][j] >= '0' && arg[i][j] <= '9')
			j++;
		if (arg[i][j] != 0 && (arg[i][j] < '0' || arg[i][j] > '9'))
			error(INVALID_ARG);
		j = 0;
	}
	num_list = malloc((i + 1) * sizeof(int));
	if (!num_list)
		error(MALLOC_ERR);
	num_list = arg_to_int(arg, num_list, i);
	if (arg_split > 0)
		ft_free_arr(arg);
	check_duplicates(num_list);
	return (num_list);
}

void	stack_init(t_int_stack *stack, int *num_list, char name)
{
	int	n;
	int	i;

	n = num_list[0];
	stack->name = name;
	stack->num_list = malloc((n + 1) * sizeof(int **));
	if (!stack->num_list)
		error(MALLOC_ERR);
	i = 0;
	if (name == 'a')
	{
		while (n--)
			stack->num_list[i++] = ++num_list;
	}
	else
	{
		while (n--)
			stack->num_list[i++] = NULL;
	}
	stack->num_list[i] = NULL;
}
