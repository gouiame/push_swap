/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instractions2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgouiame <cgouiame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 21:41:37 by cgouiame          #+#    #+#             */
/*   Updated: 2023/05/27 20:07:34 by cgouiame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_data *data, int x)
{
	int	temp;
	int	*stack;
	int	i;

	if (data->size_b != 0)
	{
		temp = data->stack_b[0];
		data->size_b = data->size_b - 1;
		stack = (int *)malloc ((data->size_b) * sizeof(int));
		i = -1;
		while (++i < data->size_b)
			stack[i] = data->stack_b[i + 1];
		free(data->stack_b);
		data->stack_b = stack;
		data->size_a = data->size_a + 1;
		stack = (int *)malloc ((data->size_a) * sizeof(int));
		i = 0;
		stack[0] = temp;
		while (++i < data->size_a)
			stack[i] = data->stack_a[i - 1];
		free(data->stack_a);
		data->stack_a = stack;
		if (x)
			write(1, "pa\n", 3);
	}
}

void	push_b(t_data *data, int x)
{
	int	temp;
	int	*stack;
	int	i;

	if (data->size_a != 0)
	{
		temp = data->stack_a[0];
		data->size_a = data->size_a - 1;
		stack = (int *)malloc ((data->size_a) * sizeof(int));
		i = -1;
		while (++i < data->size_a)
			stack[i] = data->stack_a[i + 1];
		free(data->stack_a);
		data->stack_a = stack;
		data->size_b = data->size_b + 1;
		stack = (int *)malloc ((data->size_b) * sizeof(int));
		i = 0;
		stack[0] = temp;
		while (++i < data->size_b)
			stack[i] = data->stack_b[i - 1];
		ft_stack_b(data);
		data->stack_b = stack;
		if (x)
			write (1, "pb\n", 3);
	}
}

void	push_a_to_b(t_data *data, int to_push, int pos)
{
	if (pos > (data->size_a / 2))
		while (data->stack_a[0] != to_push)
			reverse_a(data, 1);
	else
		while (data->stack_a[0] != to_push)
			rotate_a(data, 1);
	push_b(data, 1);
}

void	push_b_to_a(t_data *data, int to_push, int pos)
{
	if (pos > (data->size_b / 2))
		while (data->stack_b[0] != to_push)
			reverse_b(data, 1);
	else
		while (data->stack_b[0] != to_push)
			rotate_b(data, 1);
	push_a(data, 1);
}

void	push_to_b(t_data *data)
{
	int	to_push;

	while (data->size_b > 0)
	{
		to_push = find_max_in_b(data);
		push_b_to_a(data, to_push, get_pos_b(data, to_push));
	}
}
