/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgouiame <cgouiame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 21:36:07 by cgouiame          #+#    #+#             */
/*   Updated: 2023/05/27 20:59:41 by cgouiame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_4(t_data *data)
{
	sort_min(data);
	sort_3(data);
	push_a(data, 1);
}

void	sort_min(t_data *data)
{
	int	i;
	int	min;

	i = 0;
	min = data->stack_a[0];
	while (i < data->size_a)
	{
		if (min > data->stack_a[i])
			min = data->stack_a[i];
		i++;
	}
	while (data->stack_a[0] != min)
		rotate_a(data, 1);
	push_b(data, 1);
}

void	sorting_3(t_data *data)
{
	if (data->stack_a[0] < data->stack_a[1]
		&& data->stack_a[0] > data->stack_a[2]
		&& data->stack_a[1] > data->stack_a[2])
		reverse_a(data, 1);
}

void	sort_3(t_data *data)
{
	if (data->stack_a[0] > data->stack_a[1]
		&& data->stack_a[1] < data->stack_a[2]
		&& data->stack_a[2] > data->stack_a[0])
		swap_a (data, 1);
	else if (data->stack_a[0] > data->stack_a[1]
		&& data->stack_a[0] > data->stack_a[2]
		&& data->stack_a[1] > data->stack_a[2])
	{
		swap_a(data, 1);
		reverse_a(data, 1);
	}
	else if (data->stack_a[0] > data->stack_a[1]
		&& data->stack_a[1] < data->stack_a[2]
		&& data->stack_a[0] > data->stack_a[2])
		rotate_a(data, 1);
	else if (data->stack_a[0] < data->stack_a[1]
		&& data->stack_a[0] < data->stack_a[2]
		&& data->stack_a[1] > data->stack_a[2])
	{
		swap_a(data, 1);
		rotate_a(data, 1);
	}
	sorting_3(data);
}

void	ft_sort(t_data *data)
{
	if (data->size_a == 1)
		exit (0);
	else if (data->size_a == 2)
		swap_a(data, 1);
	else if (data->size_a == 3)
		sort_3(data);
	else if (data->size_a == 4)
		sort_4(data);
	else if (data->size_a == 5)
	{
		sort_min(data);
		sort_4(data);
		push_a(data, 1);
	}
	else
		sort(data);
}
