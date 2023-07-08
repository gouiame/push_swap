/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instractions1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgouiame <cgouiame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 21:35:36 by cgouiame          #+#    #+#             */
/*   Updated: 2023/05/26 22:36:33 by cgouiame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_data *data, int x)
{
	int	temp;
	int	i;

	if (data->size_a > 1)
	{
		temp = data->stack_a[0];
		i = 0;
		while (i + 1 < data->size_a)
		{
			data->stack_a[i] = data->stack_a[i + 1];
			i++;
		}
		data->stack_a[data->size_a - 1] = temp;
		if (x)
			write(1, "ra\n", 3);
	}
}

void	rotate_b(t_data *data, int x)
{
	int	temp;
	int	i;

	if (data->size_b > 1)
	{
		temp = data->stack_b[0];
		i = 0;
		while (i + 1 < data->size_b)
		{
			data->stack_b[i] = data->stack_b[i + 1];
			i++;
		}
		data->stack_b[data->size_b - 1] = temp;
		if (x)
			write (1, "rb\n", 3);
	}
}

void	rotate_a_b(t_data *data, int x)
{
	if (data->size_a > 1 && data->size_b > 1)
	{
		rotate_a(data, 0);
		rotate_b(data, 0);
		if (x)
			write (1, "rr\n", 3);
	}
}

void	reverse_a(t_data *data, int x)
{
	int	temp;
	int	size;

	size = data->size_a;
	if (data->size_a > 1)
	{
		temp = data->stack_a[data->size_a - 1];
		while (--data->size_a)
			data->stack_a[data->size_a] = data->stack_a[data->size_a - 1];
		data->stack_a[0] = temp;
		if (x)
			write (1, "rra\n", 4);
	}
	data->size_a = size;
}

void	reverse_b(t_data *data, int x)
{
	int	temp;
	int	size;

	size = data->size_b;
	if (data->size_b > 1)
	{
		temp = data->stack_b[data->size_b - 1];
		while (--data->size_b)
			data->stack_b[data->size_b] = data->stack_b[data->size_b - 1];
		data->stack_b[0] = temp;
		if (x)
			write (1, "rrb\n", 4);
	}
	data->size_b = size;
}
