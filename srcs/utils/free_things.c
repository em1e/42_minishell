/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_things.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: araveala <araveala@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 10:59:15 by araveala          #+#    #+#             */
/*   Updated: 2024/06/13 13:41:15 by araveala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_array(char **array)
{
	int i;

	i = 0;
	while (array[i] != NULL)
	{
		free(array[i]);
		array[i] = NULL;
		i++;
	}
	if (array != NULL)
	{
		free(array);
		array = NULL;
	}
}

void	free_string(char *string)
{
	if (string)
	{
		free(string);
		string = NULL;
	}
}
void	collective_free(char *str1, char *str2, char **array)
{
	if (array != NULL)
		free_array(array);
	if (str1 != NULL)
		free_string(str1);
	if (str2 != NULL)
		free_string(str2);
	
}
void	free_nodes(t_env *node)
{
	t_env *tmp;
	while (node != NULL)
	{
		if (node->value)
			free(node->value);
		free(node->key);
		tmp = node;
		node = node->next;
		free(tmp);
	}
}

int error(char *cmd, char *error)
{
	ft_printf("minishell: %s: %s\n", cmd, error); //perror
	return (1);
}
