/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnanchen <thomasnanchen@hotmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 21:19:06 by tnanchen          #+#    #+#             */
/*   Updated: 2021/12/17 13:56:24 by tnanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// lib and functions
# include "libft/libft.h"

// defines
# define ARG ""

# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define DEFAULT "\033[0m"

# define NULL_ARG 1
# define INVALID_ARG 2
# define MALLOC_ERR 3
# define DUPLICATES_ARG 4

typedef struct s_int_stack
{
	int		**num_list;
	char	name;
}	t_int_stack;

typedef struct s_uint_stack
{
	unsigned int	**num_list;
	char			name;
}	t_uint_stack;

// utils.c
void			error(int error_code);
int				stack_length(int **num_list);
void			print_num_list(int *num_list);
void			print_stack(t_int_stack *stack, char name);
int				is_sorted(t_int_stack *stack);

// utils2.c
int				min_num_index(t_int_stack *stack);
int				max_num_index(t_int_stack *stack);
int				direction_to_top(t_int_stack *stack, int i);
void			best_rotate(t_int_stack *stack, int i);
int				is_sorted_unrotated(t_int_stack *stack, int min, int max);

// num_list.c
char			**arg_list_create(int ac, char **av, int *arg_split);
int				*arg_checker(char **arg, int *num_list, int arg_split);
void			stack_init(t_int_stack *stack, int *num_list, char name);

/* ************ */
/* OPERATIONS : */

// op_push.c
int				push(t_int_stack *dst, t_int_stack *src);
int				push_radix(t_int_stack *dst, t_int_stack *src);

// op_swap.c
int				swap_one(t_int_stack *stack);
int				swap_both(t_int_stack *a, t_int_stack *b);

// op_rotate.c
int				rotate_one(t_int_stack *stack);
int				rotate_both(t_int_stack *a, t_int_stack *b);
int				rotate_radix(t_int_stack *stack);

// op_rev_rotate.c
int				rev_rotate_one(t_int_stack *stack);
int				rev_rotate_both(t_int_stack *a, t_int_stack *b);

/* ************ */
/* SORT ALGOS : */

// short_list1
void			sort_2num(t_int_stack *stack);
void			sort_3num(t_int_stack *stack);
void			sort_4num(t_int_stack *a, t_int_stack *b);

// short_list2
void			sort_5num(t_int_stack *a, t_int_stack *b);
int				min2_num_index(t_int_stack *stack);

// swapping
void			one_stack_swapping(t_int_stack *a);

// insertions
void			insertion_sort(t_int_stack *a, t_int_stack *b);

// fusion
void			divide_sort_and_fusion(t_int_stack *a, t_int_stack *b);

// radix
unsigned int	*unsigned_list(t_int_stack *stack, int len);
unsigned int	*positiv_num_stack(t_uint_stack *u_stack,
					t_int_stack *stack, unsigned int *u_num_list, int len);
void			bitwise_check(t_uint_stack *u_a, t_uint_stack *u_b, int len);
void			sort_radix(t_int_stack *a, t_int_stack *b);

// radix_v2
void			sort_radix_indexes(t_int_stack *a, t_int_stack *b);

// packages (unused)
void			sort_packages(t_int_stack *a, t_int_stack *b);

#endif
