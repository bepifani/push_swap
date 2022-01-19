/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepifani <bepifani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 16:46:34 by bepifani          #+#    #+#             */
/*   Updated: 2022/01/15 20:28:32 by bepifani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_mini_sort2(int *stack_a, int *stack_b)
{
	if (stack_a[1] < stack_a[0])
		ft_swap(stack_a, stack_b, 'a');
}

void	ft_mini_sort3(int *stack_a, int *stack_b)
{
	if (stack_a[2] > stack_a[1] && stack_a[2] > stack_a[0])
		ft_rotate(stack_a, stack_b, 'a');
	if (stack_a[2] > stack_a[1])
		ft_swap(stack_a, stack_b, 'a');
	if (stack_a[0] < stack_a[1])
		ft_reverse_rotate(stack_a, stack_b, 'a');
	if (stack_a[1] < stack_a[2])
		ft_swap(stack_a, stack_b, 'a');
}

void	ft_mini_sort4(int *stack_a, int *stack_b)
{
	while (stack_a[3] != 0)
		ft_rotate(stack_a, stack_b, 'a');
	ft_push(stack_a, stack_b, 'b');
	ft_mini_sort3(stack_a, stack_b);
	ft_push(stack_a, stack_b, 'a');
}

void	ft_mini_sort5(int *stack_a, int *stack_b)
{
	while (stack_a[4] != 0)
	{
		if (stack_a[0] == 0 || stack_a[1] == 0)
			ft_reverse_rotate(stack_a, stack_b, 'a');
		else
			ft_rotate(stack_a, stack_b, 'a');
	}
	ft_push(stack_a, stack_b, 'b');
	while (stack_a[3] != 1)
		ft_rotate(stack_a, stack_b, 'a');
	ft_push(stack_a, stack_b, 'b');
	ft_mini_sort3(stack_a, stack_b);
	ft_push(stack_a, stack_b, 'a');
	ft_push(stack_a, stack_b, 'a');
}

void	ft_mini_sort(int *stack_a, int *stack_b, int argc)
{
	if (argc == 6)
		ft_mini_sort5(stack_a, stack_b);
	else if (argc == 5)
		ft_mini_sort4(stack_a, stack_b);
	else if (argc == 4)
		ft_mini_sort3(stack_a, stack_b);
	else if (argc == 3)
		ft_mini_sort2(stack_a, stack_b);
}
