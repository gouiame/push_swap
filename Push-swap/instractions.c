/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instractions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgouiame <cgouiame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 21:35:33 by cgouiame          #+#    #+#             */
/*   Updated: 2023/05/26 22:36:42 by cgouiame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_data *data, int x)
{
	int	temp;

	if (data->size_a > 1)
	{
		temp = data->stack_a[0];
		data->stack_a[0] = data->stack_a[1];
		data->stack_a[1] = temp;
		if (x == 1)
			write (1, "sa\n", 3);
	}
}

void	swap_b(t_data *data, int x)
{
	int	temp;

	if (data->size_b > 1)
	{
		temp = data->stack_b[0];
		data->stack_b[0] = data->stack_b[1];
		data->stack_b[1] = temp;
		if (x == 1)
			write (1, "sb\n", 3);
	}
}

void	swap_a_b(t_data *data, int x)
{
	if (data->size_a > 1 && data->size_b > 1)
	{
		swap_a(data, 0);
		swap_b(data, 0);
		if (x)
			write(1, "ss\n", 3);
	}
}

void	reverse_a_b(t_data *data, int x)
{
	if (data->size_a > 1 && data->size_b > 1)
	{
		reverse_a(data, 0);
		reverse_b(data, 0);
		if (x)
			write(1, "rrr\n", 4);
	}
}
