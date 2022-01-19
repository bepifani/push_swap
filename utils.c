/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepifani <bepifani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 16:49:10 by bepifani          #+#    #+#             */
/*   Updated: 2022/01/18 17:58:19 by bepifani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	b;

	i = 0;
	b = 0;
	while (*str == ' ' || *str == '\n' || *str == '\v'
		|| *str == '\t' || *str == '\f' || *str == '\r')
		str++;
	if (*str == '-')
		b++;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		i = i * 10 + (*str - 48);
		str++;
	}
	if (b == 1)
		i = i * (-1);
	return (i);
}

void	ft_full_free(int *mas)
{
	if (mas)
		free(mas);
	mas = NULL;
}

void	ft_error(int *stack_a, int *stack_b)
{
	write (1, "error\n", 6);
	if (stack_a)
		free (stack_a);
	stack_a = NULL;
	if (stack_b)
		free(stack_b);
	stack_b = NULL;
}

void	ft_helper(int *massiv, int *arr, int *new_massiv)
{
	while (arr[1] >= 0)
	{
		if (massiv[arr[1]] == arr[0])
		{
			new_massiv[arr[1]] = arr[2];
			massiv[arr[1]] = INT_MAX;
			arr[2]++;
			break ;
		}
		arr[1]--;
	}
}
