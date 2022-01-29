/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkai <kkai@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 11:06:43 by kkai              #+#    #+#             */
/*   Updated: 2022/01/29 14:55:35 by kkai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "./libft/libft.h"


typedef struct s_dlst
{
	bool nil;
	long value;
	struct s_dlst *prev;
	struct s_dlst *next;
}				t_dlst;



// 番兵ノード作成
t_dlst	*dlstnew()
{
	t_dlst	*new;

	new	= (t_dlst *)malloc(sizeof(t_dlst));
	new->nil = true;
	new->value = 0;
	new->prev = new;
	new->next = new;
	return (new);
}

void	dlstadd_back(t_dlst *a, long num)
{
	t_dlst	*new;

	new = dlstnew();
	new->nil = false;
	new->value = num;
	new->prev = a->prev;
	new->next = a;
	a->prev->next = new;
	a->prev = new;
}
void	print_dlst(t_dlst *a, t_dlst *b)
{
	printf("a: ");
	a = a->next;
	while (a->nil == false)
	{
		printf("%ld ", a->value);
		a = a->next;
	}
	printf("\n");

	printf("b: ");
	b = b->next;
	while (b->nil == false)
	{
		printf("%ld ", b->value);
		b = b->next;
	}
	printf("\n");
}

int	main(int argc, char **argv)
{
	char	**str;
	t_dlst	*a;
	t_dlst	*b;
	int		i;

	(void)argc;
	str = ft_split(argv[1], ' ');
	i = -1;
	a = dlstnew();
	b = dlstnew();

	// bに適当に追加
	dlstadd_back(b, 1);
	// aに数字を追加
	while (str[++i])
		dlstadd_back(a, ft_atoi(str[i]));
	print_dlst(a, b);
	return (0);
}
