/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbiagi <mbiagi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 17:16:02 by mbiagi            #+#    #+#             */
/*   Updated: 2024/11/19 17:17:31 by mbiagi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_tolower(int c)
{
	if ((c >= 65) && (c <= 90))
		c = c + 32;
	return (c);
}
/* 
int	main(void)
{
	char	c;

	c = 'A';
	c = ft_tolower(c);
	printf("%c", c);
} */