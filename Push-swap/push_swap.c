/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgouiame <cgouiame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 21:35:42 by cgouiame          #+#    #+#             */
/*   Updated: 2023/05/27 20:59:59 by cgouiame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_check_arg(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if ((av[i][j] == '+' || av[i][j] == '-')
				&& (av[i][j + 1] == '+' || av[i][j + 1] == '-'))
			{
				write(2, "Error\n", 6);
				exit(1);
			}
			if ((av[i][j] >= '0' && av[i][j] <= '9')
				&& (av[i][j + 1] == '+' || av[i][j + 1] == '-'))
			{
				write(2, "Error\n", 6);
				exit(1);
			}
			j++;
		}
		i++;
	}
}

void	ft_check_arg_1(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if ((av[i][j] == '+' || av[i][j] == '-') && (av[i][j + 1] == ' '
				|| av[i][j + 1] == '\t' || av[i][j + 1] == '\0'))
			{
				write(2, "Error\n", 6);
				exit(1);
			}
			if ((av[i][j] != ' ' && av[i][j] != '\t' && av[i][j] != '-'
				&& av[i][j] != '+' && (av[i][j] < '0' || av[i][j] > '9')))
			{
				write(2, "Error\n", 6);
				exit(1);
			}
			j++;
		}
		i++;
	}
}

void	ft_check_arg_2(char **av)
{
	int	j;
	int	i;

	j = 0;
	while (av[j])
	{
		i = 0;
		while (av[j][i] == ' ' || av[j][i] == '\t')
		i++;
		if (av[j][i] == '\0' || av[j][0] == '\0')
		{
			write(1, "Error\n", 7);
			exit (1);
		}
		j++;
	}
}

void	ft_store_data(char **s, t_data *data)
{
	int	i;

	i = 0;
	while (s[i])
	i++;
	data->size_a = i;
	data->size_b = 0;
	data->stack_a = malloc (sizeof(int) * i);
	data->stack_b = NULL;
	i = 0;
	while (s[i])
	{
		if (ft_atoi(s[i]) == 2147483648)
		{
			write(2, "Error\n", 6);
			free_memory(s);
			ft_free(data);
			exit(1);
		}
		data->stack_a[i] = ft_atoi(s[i]);
		i++;
	}	
}

int	main(int ac, char **av)
{
	t_data	*data;
	char	*s;
	char	**str;

	if (ac < 2)
		exit (0);
	ft_check_arg(av);
	ft_check_arg_1(av);
	ft_check_arg_2(av);
	s = ft_join(av);
	str = ft_split(s, ' ');
	free(s);
	data = malloc(sizeof(t_data));
	ft_store_data(str, data);
	free_memory(str);
	ft_double(data);
	ft_sorted(data);
	ft_index(data);
	ft_sort(data);
	ft_free(data);
}
