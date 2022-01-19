/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepifani <bepifani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 15:17:34 by bepifani          #+#    #+#             */
/*   Updated: 2022/01/18 17:03:50 by bepifani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_make_push(int *mas1, int *mas2)
{
	int	j;
	int	i;
	int	tmp;

	i = ft_size_of_mas(mas1);
	j = ft_size_of_mas(mas2);
	tmp = mas1[i - 1];
	mas1[i - 1] = mas2[j];
	mas2[j] = tmp;
	mas1[i - 1] = -1;
}

void	ft_push(int *stack_a, int *stack_b, char rule)
{
	if (rule == 'b')
	{
		ft_make_push(stack_a, stack_b);
		write(1, "pb\n", 3);
	}
	else if (rule == 'a')
	{
		ft_make_push(stack_b, stack_a);
		write(1, "pa\n", 3);
	}
}
