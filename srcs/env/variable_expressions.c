/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variable_expressions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkettune <vkettune@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 16:03:23 by vkettune          #+#    #+#             */
/*   Updated: 2024/06/13 17:57:53 by vkettune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char *replace_expansion(t_data *data, t_env *envs, char *arg, int i)
{
	int j;
	char *temp_key;
	char *value;
	// t_env *envs;

	j = i;
	value = NULL;
	// envs = data->env;
	ft_printf("i = %s\n", i);
	ft_printf("arg[%d - 1] = %s\n", i, arg[i - 1]);
	while (arg[j] != ' ' || arg[j] == '\0')
		j++;
	temp_key = malloc(sizeof(char) * (j - i) + 1);
	while (i < j)
	{
		temp_key[i] = ft_strdup(arg[i]);
		i++;
	}
	if (find_node(envs, temp_key, data) == 0)
	{
		value = find_keys_value(envs, temp_key);
		if (value != NULL)
			ft_printf("value= %s\n", value);
			// replace $key with value in arg
		else
			ft_printf("value= %s\n", value);
			// remove $ or give error, check bash for what to do
	}
	return (arg);
}

char	*look_if_expansions(t_data *data, t_env *envs, char *arg)
{
	int i;

	i = 0;
	while (arg[i])
	{
		if (ft_strncmp(arg[i], '$', 1) && !(ft_isdigit(arg[++i]) // there is a function for this
			|| arg[i] == ' ' || arg[i] == '\0'))
		{
			arg = replace_expansion(data, envs, arg, i); // can talk envs away
			break ;
		}
		i++;
	}
	return (arg);
}

int	variable_expansions(t_data *data, t_env *envs, char **args)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (args[i]) // loop through arg
	{
		if (is_pipe_or_redirect(args[i]) <= 0)
			continue ; // continue the while loop?
		args[i] = look_if_expansions(envs, args[i], data); // returns modified args[i], so that it can be handled accordingly
	}
		// see if there is $ and something after, 
		// if only $ then handle as char
	// if found run find_key()
		// move into it, 
		// get value of key
	// replace $key with the kay's value
}

int is_pipe_or_redirect(char *arg) // there is a function for this
{	
	if (ft_strncmp(arg, '|', 2))
		return (0);
	else if (ft_strncmp(arg, '||', 3))
		return (-1);
	else if (ft_strncmp(arg, '>>', 3))
		return (-2);
	else if (ft_strncmp(arg, '>', 2))
		return (-3);
	else if (ft_strncmp(arg, '<<', 3))
		return (-4);
	else if (ft_strncmp(arg, '<', 2))
		return (-5);
	return (1);
}