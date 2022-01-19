/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepifani <bepifani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 15:44:32 by bepifani          #+#    #+#             */
/*   Updated: 2022/01/18 17:03:27 by bepifani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_make_rotate(int *massiv)
{
	int	i;
	int	tmp;

	i = ft_size_of_mas(massiv);
	i = i - 1;
	tmp = massiv[i];
	while (i > 0)
	{
		massiv[i] = massiv[i - 1];
		i--;
	}
	massiv[0] = tmp;
}

void	ft_rotate(int *stack_a, int *stack_b, char rule)
{
	if (rule == 'a' && ft_size_of_mas(stack_a) > 1)
	{
		ft_make_rotate(stack_a);
		write(1, "ra\n", 3);
	}
	else if (rule == 'b' && ft_size_of_mas(stack_b) > 1)
	{
		ft_make_rotate(stack_b);
		write(1, "rb\n", 3);
	}
	else if (rule == 'r' && ft_size_of_mas(stack_b) > 1
		&& ft_size_of_mas(stack_a) > 1)
	{
		ft_make_rotate(stack_a);
		ft_make_rotate(stack_b);
		write(1, "rr\n", 3);
	}
}
