/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgouiame <cgouiame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 21:36:04 by cgouiame          #+#    #+#             */
/*   Updated: 2023/05/27 21:00:14 by cgouiame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct t_data{
	int	*stack_a;
	int	*stack_b;
	int	size_a;
	int	size_b;
}t_data;

char	**free_memory(char **p);
int		words_counter(char *str, char c);
char	**ft_split(char *s, char c);
int		ft_strlen(char *str);
char	*ft_strdup(char *s1);
char	*ft_substr(char *s, int start, int len);
char	*ft_strjoin(char *s1, char *s2);
void	ft_sorted(t_data *data);
void	ft_double(t_data *data);
void	ft_sort_data(int *num, int n);
void	swap_a(t_data *data, int x);
void	swap_b(t_data *data, int x);
void	swap_a_b(t_data *data, int x);
void	push_a(t_data *data, int x);
void	push_b(t_data *data, int x);
void	rotate_a(t_data *data, int x);
void	rotate_b(t_data *data, int x);
void	rotate_a_b(t_data *data, int x);
void	reverse_a(t_data *data, int x);
void	reverse_b(t_data *data, int x);
void	reverse_a_b(t_data *data, int x);
void	sort_3(t_data *data);
void	sort_min(t_data *data);
void	ft_sort(t_data *data);
void	sort_4(t_data *data);
void	ft_index(t_data *data);
void	sort(t_data *data);
long	ft_atoi(char *str);
void	push_a_to_b(t_data *data, int to_push, int pos);
void	push_b_to_a(t_data *data, int to_push, int pos);
void	sorting_3(t_data *data);
void	ft_free(t_data *data);
void	ft_stack_b(t_data *data);
void	ft_check_arg_1(char **av);
char	*ft_join(char **av);
void	push_to_b(t_data *data);
int		find_max_in_b(t_data *data);
int		get_pos_b(t_data *data, int find);
#endif
