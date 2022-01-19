/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maxsort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepifani <bepifani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 18:11:31 by bepifani          #+#    #+#             */
/*   Updated: 2022/01/18 15:03:01 by bepifani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_mediana_sort(int *stack_a, int *stack_b, int argc)
{
	int	i;

	i = 0;
	argc = argc - 2;
	while (i <= argc)
	{
		if (stack_a[ft_size_of_mas(stack_a) - 1] == (argc + 1) / 2
			|| stack_a[ft_size_of_mas(stack_a) - 1] == 0
			|| stack_a[ft_size_of_mas(stack_a) - 1] == argc)
			ft_rotate(stack_a, stack_b, 'a');
		else if (stack_a[ft_size_of_mas(stack_a) - 1] > argc / 2)
		{
			ft_push(stack_a, stack_b, 'b');
			ft_rotate(stack_a, stack_b, 'b');
		}
		else
			ft_push(stack_a, stack_b, 'b');
		i++;
	}
}

int	ft_which_rotate(int *stack_a, int a)
{
	int	i;

	i = ft_size_of_mas(stack_a) - 1;
	if (a > stack_a[0] && a < stack_a[ft_size_of_mas(stack_a) - 1])
		return (1);
	while (i > 0)
	{
		if (a > stack_a[i] && a < stack_a[i - 1])
			break ;
		i--;
	}
	if (i < ft_size_of_mas(stack_a) / 2)
		return (-1);
	else
		return (1);
}

void	ft_from_b_to_a(int *stack_a, int *stack_b)
{
	int	a;

	while (ft_size_of_mas(stack_b) > 1)
	{
		a = stack_b[ft_find_start(stack_a, stack_b)];
		if (ft_find_start(stack_a, stack_b) < ft_size_of_mas(stack_b) / 2)
			ft_reverse_rotate_stack_b(stack_a, stack_b, a);
		else
			ft_rotate_stack_b(stack_a, stack_b, a);
		if (ft_which_rotate(stack_a, a) == -1)
			ft_reverse_rotate_stack_a(stack_a, stack_b, a);
		else
			ft_rotate_stack_a(stack_a, stack_b, a);
		ft_push(stack_a, stack_b, 'a');
	}
	if (ft_which_rotate(stack_a, a) == -1)
		ft_reverse_rotate_stack_a(stack_a, stack_b, stack_b[0]);
	else
		ft_rotate_stack_a(stack_a, stack_b, stack_b[0]);
	ft_push(stack_a, stack_b, 'a');
	ft_end_of_sort(stack_a, stack_b);
}

void	ft_max_sort(int *stack_a, int *stack_b, int argc)
{
	ft_mediana_sort(stack_a, stack_b, argc);
	ft_mini_sort3(stack_a, stack_b);
	ft_from_b_to_a(stack_a, stack_b);
}
