/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgouiame <cgouiame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 21:36:16 by cgouiame          #+#    #+#             */
/*   Updated: 2023/05/27 18:10:33 by cgouiame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_join(char **av)
{
	char	*p;
	int		i;

	i = 1;
	p = NULL;
	while (av[i])
	{
		p = ft_strjoin(p, av[i]);
		p = ft_strjoin(p, " ");
		i++;
	}
	i = 1;
	while (p[i])
	{
		if (p[i] == '\t')
		p[i] = ' ';
		i++;
	}
	return (p);
}

void	ft_double(t_data *data)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	while (i < data->size_a)
	{
		count = 0;
		j = 0;
		while (j < data->size_a)
		{
			if (data->stack_a[i] == data->stack_a[j])
				count++;
			j++;
		}
		if (count > 1)
		{
			write (2, "Error\n", 6);
			ft_free(data);
			exit (1);
		}
		i++;
	}
}

void	ft_sorted(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->size_a - 1)
	{
		if (data->stack_a[i] > data->stack_a[i + 1])
			return ;
		i++;
	}
	ft_free(data);
	exit (0);
}

long	ft_atoi(char *str)
{
	long	num;
	int		i;
	int		sign;

	sign = 1;
	i = 0;
	num = 0;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = ((num * 10) + (str[i] - '0'));
		i++;
	}
	num *= sign;
	if (num < -2147483648 || num > 2147483647)
		return (2147483648);
	return (num);
}

void	ft_index(t_data *data)
{
	int	*index;
	int	i;
	int	j;
	int	count;

	i = 0;
	index = malloc(sizeof(int) * data->size_a);
	while (i < data->size_a)
	{
		j = 0;
		count = 1;
		while (j < data->size_a)
		{
			if (data->stack_a[j] < data->stack_a[i])
			{
				count++;
			}
			j++;
		}
		index[i] = count;
		i++;
	}
	free(data->stack_a);
	data->stack_a = index;
}
