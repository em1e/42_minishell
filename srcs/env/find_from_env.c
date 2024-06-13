/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_from_env.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkettune <vkettune@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 20:02:41 by vkettune          #+#    #+#             */
/*   Updated: 2024/06/13 17:40:17 by vkettune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char *find_keys_value(t_env *envs, char *key)
{
	t_env *temp;

	temp = envs;
	while (temp->next != NULL)
	{
		// ft_printf("key: %s\n", temp->key); // remove
		// ft_printf("value: %s\n", temp->value); // remove
		if (ft_strncmp(temp->key, key, ft_strlen(key)) == 0)
			return (temp->value);
		temp = temp->next;
	}
	return (0);
}

int find_node(t_env *envs, char *key, t_data *data)
{
	// do we need to combine all into data, we get very long lines ???
	t_env *temp;
	(void)data;
	
	if (!envs)
		return (0);
	temp = envs;
	while (temp->next != NULL)// (1)
	{
		// ft_printf("- - - - - - - - - - - - - - - - - - \n"); // remove
		// ft_printf("looking for key: %s|\n", key); // remove
		// ft_printf("temp->key: %s|\n", temp->key); // remove
		// ft_printf("temp->value: %s\n", temp->value); // places revious key as value???
		if (ft_strncmp(temp->key, key, ft_strlen(key) + 1) == 0 && (ft_strlen(temp->key) == ft_strlen(key)))
		{
			// ft_printf("key found\n"); // remove
			data->tmp->env_line = ft_strdup(temp->value);
			return (1);
		}
		temp = temp->next;
		if (temp->next == envs)
			break ;
	}
	free(key);
	// ft_printf("key not found\n");
	return (0);
}

