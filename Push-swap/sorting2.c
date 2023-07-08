/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgouiame <cgouiame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 21:39:26 by cgouiame          #+#    #+#             */
/*   Updated: 2023/05/27 21:00:18 by cgouiame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max_in_b(t_data *data)
{
	int	i;
	int	max;

	max = -2147483648;
	i = 0;
	while (i < data->size_b)
	{
		if (data->stack_b[i] > max)
			max = data->stack_b[i];
		i++;
	}
	return (max);
}

int	find_in_a(t_data *data, int max)
{
	int	i;

	i = 0;
	while (i < data->size_a)
	{
		if (data->stack_a[i] <= max)
			return (data->stack_a[i]);
		i++;
	}
	return (-1);
}

int	get_pos_a(t_data *data, int find)
{
	int	i;

	i = 0;
	while (i < data->size_a)
	{
		if (data->stack_a[i] == find)
			break ;
		i++;
	}
	return (i + 1);
}

int	get_pos_b(t_data *data, int find)
{
	int	i;

	i = 0;
	while (i < data->size_b)
	{
		if (data->stack_b[i] == find)
			break ;
		i++;
	}
	return (i + 1);
}

void	sort(t_data *data)
{
	int	chunk;
	int	dev;
	int	to_push;

	if (data->size_a > 100)
		chunk = data->size_a / 10;
	else
		chunk = data->size_a / 5;
	dev = chunk;
	while (data->size_a > 0)
	{
		to_push = find_in_a(data, chunk);
		while (to_push != -1)
		{
			push_a_to_b(data, to_push, get_pos_a(data, to_push));
			if (data->stack_b[0] > (chunk - (dev / 2)))
				rotate_b(data, 1);
			to_push = find_in_a(data, chunk);
		}
		chunk += dev;
	}
	push_to_b(data);
}
