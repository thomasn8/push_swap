#include "push_swap.h"

static unsigned int	*unsigned_list(t_int_stack *stack, int len, int min)
{
	int	i;
	unsigned int *u_num_list;

	u_num_list = malloc(len * sizeof(unsigned int));
	if (!u_num_list)
		error(MALLOC_ERR);
	i = -1;
	while (stack->num_list[++i])
	{
		ft_printf("unsigned = %d + %d\n",*stack->num_list[i], min);
		if (min < 0)
		{
			min *= -1;
			u_num_list[i] = *stack->num_list[i] + min;
		}
		else
			u_num_list[i] = *stack->num_list[i];
	}	
	return (u_num_list);
}

static void	positiv_num_stack(t_uint_stack *u_stack, t_int_stack *stack)
{
	int min;
	int	len;
	int	i;
	unsigned int *u_num_list;

	len = stack_length(stack->num_list);
	u_stack->num_list = malloc((len + 1) * sizeof(unsigned int **));
	if (!stack->num_list)
		error(MALLOC_ERR);
	i = 0;
	if (stack->name == 'a')
	{
		min = *stack->num_list[min_num_index(stack)];
		u_num_list = unsigned_list(stack, len, min);
		while (len--)
			u_stack->num_list[i++] = u_num_list++;
	}
	else
	{
		while (len--)
			u_stack->num_list[i++] = NULL;
	}
	u_stack->num_list[i] = NULL;
	u_stack->name = stack->name;
}

void	sort_radix(t_int_stack *a, t_int_stack *b)
{
	t_uint_stack	u_a;
	t_uint_stack	u_b;

	positiv_num_stack(&u_a, a);
	positiv_num_stack(&u_b, b);
	ft_printf("Conversion en unsigned\n");
	print_stack((t_int_stack *)&u_a, 'a');
}