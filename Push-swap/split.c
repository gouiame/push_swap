/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgouiame <cgouiame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 21:36:11 by cgouiame          #+#    #+#             */
/*   Updated: 2023/05/27 18:37:47 by cgouiame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_stack_b(t_data *data)
{
	if (data->size_b)
		free(data->stack_b);
}

void	ft_free(t_data *data)
{
	free(data->stack_b);
	free(data->stack_a);
	free(data);
}

char	**free_memory(char **p)
{
	int	n;

	n = 0;
	while (p[n])
	{
		free(p[n]);
		n++;
	}
	free (p);
	p = NULL;
	return (p);
}

int	words_counter(char *str, char c)
{
	int	counter;
	int	i;

	i = 0;
	counter = 0;
	while (str[i] == c)
		i++;
	while (str[i] != '\0')
	{
		if ((str[i] == c && str[i + 1] != c) || str[i + 1] == '\0' )
			counter++;
		i++;
	}
	return (counter);
}

char	**ft_split(char *s, char c)
{
	int		i;
	char	**split;
	int		j;
	int		wordstart;

	i = 0;
	j = 0;
	if (s == NULL)
		return (NULL);
	split = (char **) malloc ((words_counter(s, c) + 1) * sizeof(char *));
	if (split == NULL)
		return (NULL);
	while (i < words_counter(s, c) && s[j] != '\0')
	{
		while (s[j] == c)
			j++;
		wordstart = j;
		while (s[j] != c && s[j] != '\0')
			j++;
		split[i] = ft_substr(s, wordstart, j - wordstart);
		if (split[i++] == NULL)
			return (free_memory(split));
	}
	split[i] = NULL;
	return (split);
}
