/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix_realloc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edraccan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 11:09:35 by edraccan          #+#    #+#             */
/*   Updated: 2025/06/15 11:44:31 by edraccan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_matrix_realloc(char **m, size_t newsize)
{
	char	**new;
	size_t	i;

	if (matrix_len(m) == (int)newsize)
		return (m);
	new = malloc(sizeof(char *) * (newsize + 1));
	if (!new)
		return (NULL);
	i = 0;
	while (m && m[i])
	{
		new[i] = ft_strdup(m[i]);
		i++;
	}
	while (i < newsize)
	{
		new[i] = NULL;
		i++;
	}
	free_matrix(m);
	return (new);
}
