/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepifani <bepifani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 16:48:51 by bepifani          #+#    #+#             */
/*   Updated: 2022/01/18 17:58:43 by bepifani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>

//utils
int		ft_atoi(const char *str); // строка в число
void	ft_full_free(int *mas); // чистит массив
void	ft_helper(int *massiv, int *arr, int *new_massiv);

//make_massiv
int		ft_checker(char *str); //проверка строки на число
int		*ft_make_stack_massiv(char **argv, int argc); //мас из введенных чисел
int		ft_find_min(int *massiv, int size); //поиск минимального значения
int		*ft_massiv_pars(int *massiv, int size); //индексация массива
int		*ft_final_stack(int argc, char **argv); // делает индексированный массив

//push_swap
void	ft_error(int *stack_a, int *stack_b); // выдает ошибку и все чистит
int		*ft_make_stack_b(int size); //создает стак в из -1
void	ft_write(int *m1, int *m2);

// swap
void	ft_swap(int *stack_a, int *stack_b, char rule); // правило свап
void	ft_make_swap(int *massiv); // делает свап в конкретном стаке
int		ft_size_of_mas(int *massiv); // находит длину стака

// push
void	ft_push(int *stack_a, int *stack_b, char rule); // команда пуш
void	ft_make_push(int *mas1, int *mas2); // делает пуш в массивах

// rotate
void	ft_make_rotate(int *massiv); // делает ротейт в массиве
void	ft_rotate(int *stack_a, int *stack_b, char rule); // команда ротейт

// reverse rotate
void	ft_reverse_rotate(int *stack_a, int *stack_b, char rule);
void	ft_make_reverse_rotate(int *massiv); // делает реверс ротэйт в массиве

// sort
void	ft_mini_sort2(int *stack_a, int *stack_b);
void	ft_mini_sort3(int *stack_a, int *stack_b);
void	ft_mini_sort4(int *stack_a, int *stack_b);
void	ft_mini_sort5(int *stack_a, int *stack_b);
void	ft_mini_sort(int *stack_a, int *stack_b, int argc);

// maxsort
void	ft_mediana_sort(int *stack_a, int *stack_b, int argc); //относ медианы
void	ft_max_sort(int *stack_a, int *stack_b, int argc);
void	ft_from_b_to_a(int *stack_a, int *stack_b);
int		ft_which_rotate(int *stack_a, int a); // в какую сторону крутить

// maxsort_utils
void	ft_reverse_rotate_stack_a(int *stack_a, int *stack_b, int a);
void	ft_rotate_stack_a(int *stack_a, int *stack_b, int a);
void	ft_reverse_rotate_stack_b(int *stack_a, int *stack_b, int a);
void	ft_rotate_stack_b(int *stack_a, int *stack_b, int a);
void	ft_end_of_sort(int *stack_a, int *stack_b); //ставит стэк в нужное полож

//score
int		ft_find_score(int *stack_a, int *stack_b, int i);
int		ft_find_score_b(int *stack_b, int i);
int		ft_find_score_a(int *stack_a, int *stack_b, int i);
int		ft_find_start(int *stack_a, int *stack_b); //индекс старта

#endif