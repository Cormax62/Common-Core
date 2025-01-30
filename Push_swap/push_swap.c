/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiagi <mbiagi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 11:45:44 by mbiagi            #+#    #+#             */
/*   Updated: 2025/01/29 17:06:38 by mbiagi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_lst(t_list *lst)
{
	t_list	*temp;

	while (lst)
	{
		ft_printf("free %d\n", lst->n);
		temp = lst->next;
		free(lst);
		lst = temp;
	}
}

t_list	*create_lst(char **c)
{
	t_list		*head;
	int			content;
	int			j;

	j = 0;
	head = NULL;
	while (c[j])
	{
		content = ft_atoi(c[j]);
		ft_lstadd_back(&head, ft_lstnew(content));
		j++;
	}
	return (head);
}

t_list	*more_str_handle(char **argv)
{
	if ((digit_control(argv) == 0) || (equals_control(argv) == 0) || \
	(value_control(argv) == 0))
		return (ft_putstr_fd("Error\n[invalid argument]", 2), NULL);
	return (create_lst(argv));
}

t_list	*one_str_handle(char *argv)
{
	t_list	*stack;
	char	**split_c;

	if (argv[0] == '\0')
		return (ft_putstr_fd("Error\n[invalid argument]", 2), NULL);
	split_c = ft_split(argv, ' ');
	if ((digit_control(split_c) == 0) || (equals_control(split_c) == 0) || \
	(value_control(split_c) == 0))
	{
		ft_free(split_c);
		return (ft_putstr_fd("Error\n[invalid argument]", 2), NULL);
	}
	stack = create_lst(split_c);
	free(split_c);
	return (stack);
}

int	main(int argc, char **argv)
{
	t_list	*stack;

	stack = NULL;
	if (argc < 2)
		return (0);
	else if (argc == 2)
		stack = one_str_handle(argv[1]);
	else if (argc > 2)
		stack = more_str_handle(&argv[1]);
	control_alg(stack);
	return (0);
}
