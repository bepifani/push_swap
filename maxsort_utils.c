/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maxsort_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepifani <bepifani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:01:40 by bepifani          #+#    #+#             */
/*   Updated: 2022/01/18 15:03:06 by bepifani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_reverse_rotate_stack_a(int *stack_a, int *stack_b, int a)
{
	while (1)
	{
		if (stack_a[0] < a && stack_a[ft_size_of_mas(stack_a) - 1] > a)
			break ;
		ft_reverse_rotate(stack_a, stack_b, 'a');
	}
}

void	ft_rotate_stack_a(int *stack_a, int *stack_b, int a)
{
	while (1)
	{
		if (stack_a[0] < a && stack_a[ft_size_of_mas(stack_a) - 1] > a)
			break ;
		ft_rotate(stack_a, stack_b, 'a');
	}
}

void	ft_reverse_rotate_stack_b(int *stack_a, int *stack_b, int a)
{
	while (stack_b[ft_size_of_mas(stack_b) - 1] != a)
		ft_reverse_rotate(stack_a, stack_b, 'b');
}

void	ft_rotate_stack_b(int *stack_a, int *stack_b, int a)
{
	while (stack_b[ft_size_of_mas(stack_b) - 1] != a)
		ft_rotate(stack_a, stack_b, 'b');
}

void	ft_end_of_sort(int *stack_a, int *stack_b)
{
	if (stack_a[0] > ft_size_of_mas(stack_a) / 2)
	{
		while (stack_a[ft_size_of_mas(stack_a) - 1] != 0)
			ft_rotate(stack_a, stack_b, 'a');
	}
	else
	{
		while (stack_a[ft_size_of_mas(stack_a) - 1] != 0)
			ft_reverse_rotate(stack_a, stack_b, 'a');
	}
}
