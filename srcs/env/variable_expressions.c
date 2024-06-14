/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variable_expressions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkettune <vkettune@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 16:03:23 by vkettune          #+#    #+#             */
/*   Updated: 2024/06/14 12:41:31 by vkettune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// FOR **ARGS - - - - - - - - - - - - - - - - - - - - - - - -

// char *replace_expansion(t_data *data, t_env *envs, char *arg, int i)
// {
// 	int j;
// 	char *temp_key;
// 	char *value;
// 	// t_env *envs;

// 	j = i;
// 	value = NULL;
// 	// envs = data->env;
// 	ft_printf("i = %s\n", i);
// 	ft_printf("arg[%d - 1] = %s\n", i, arg[i - 1]);
// 	while (arg[j] != ' ' || arg[j] == '\0')
// 		j++;
// 	temp_key = malloc(sizeof(char) * (j - i) + 1);
// 	while (i < j)
// 	{
// 		temp_key[i] = ft_strdup(arg[i]);
// 		i++;
// 	}
// 	if (find_node(envs, temp_key, data) == 0)
// 	{
// 		value = find_keys_value(envs, temp_key);
// 		if (value != NULL)
// 			ft_printf("value= %s\n", value);
// 			// replace $key with value in arg
// 		else
// 			ft_printf("value= %s\n", value);
// 			// remove $ or give error, check bash for what to do
// 	}
// 	return (arg);
// }

// char	*look_if_expansions(t_data *data, t_env *envs, char *arg)
// {
// 	int i;

// 	i = 0;
// 	while (arg[i])
// 	{
// 		if (ft_strncmp(arg[i], '$', 1) && !(ft_isdigit(arg[++i]) // there is a function for this
// 			|| arg[i] == ' ' || arg[i] == '\0'))
// 		{
// 			arg = replace_expansion(data, envs, arg, i); // can talk envs away
// 			break ;
// 		}
// 		i++;
// 	}
// 	return (arg);
// }

// int	variable_expansions(t_data *data, t_env *envs, char **args)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	j = 0;
// 	while (args[i]) // loop through arg
// 	{
// 		if (is_pipe_or_redirect(args[i]) <= 0)
// 			continue ; // continue the while loop?
// 		args[i] = look_if_expansions(envs, args[i], data); // returns modified args[i], so that it can be handled accordingly
// 	}
// 		// see if there is $ and something after, 
// 		// if only $ then handle as char
// 	// if found run find_key()
// 		// move into it, 
// 		// get value of key
// 	// replace $key with the kay's value
// }

// FOR READLINE - - - - - - - - - - - - - - - - - - - - - -

// char *fill_new_rl(t_data *data, char *rl, char *temp_key, int end)
// {
// 	t_env *envs;
// 	int start;
// 	int b;
// 	char *new_rl;
// 	char *value;
// 	int new_len;

// 	envs = data->env;
// 	value = find_keys_value(envs, temp_key);
// 	start = 0;
// 	if (value != NULL) // replace $key with value in arg
// 	{
// 		ft_printf("value= %s\n", value);
// 		new_len = ft_strlen(rl) - (end - i - 1) + ft_strlen(value) + 1;
// 		new_rl = malloc(sizeof(char) * new_len);
// 		b = 0;
// 		while (b < new_len)
// 		{
// 			if ()
// 			new_rl[b] = rl[b]
// 		}
// 		return (new_rl);
// 	}
// 	else // remove $ or give error, check bash for what to do
// 		ft_printf("value= %s\n", value);
// }

// char	*look_if_expansions_rl(t_data *data, t_env *envs, char *rl)
// {
// 	int i;
// 	int j;
// 	char *temp_key;
// 	char *new_rl;

// 	i = 0;
// 	j = i;
// 	if (ft_strncmp(rl[i], '$', 1) && !(ft_isdigit(rl[++i]) // there is a function for this
// 			|| rl[i] == ' ' || rl[i] == '\0'))
// 	{
// 		// arg = replace_expansion(data, envs, arg, i); // can talk envs away
// 		while (rl[j] != ' ' || rl[j] == '\0')
// 			j++;
// 		temp_key = malloc(sizeof(char) * (j - i) + 1);
// 		while (i < j)
// 		{
// 			temp_key[i] = rl[i];
// 			i++;
// 		}
// 		temp_key[i] = 0;
// 		if (find_node(envs, temp_key, data) == 0)
// 		{
// 			new_rl = ft_strdup(rl);
// 			free(rl);
// 			rl = fill_new_rl(data, new_rl, temp_key, j);
// 		}
// 	}
// 	return (rl);
// }

// int	variable_expansions_rl(t_data *data, t_env *envs, char *rl)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	j = 0;
// 	while (rl[i]) // loop through arg
// 	{
// 		if (is_pipe_or_redirect(rl[i]) <= 0)
// 			continue ; // continue the while loop?
// 		rl = look_if_expansions_rl(envs, rl, data); // returns modified args[i], so that it can be handled accordingly
// 	}
// 		// see if there is $ and something after, 
// 		// if only $ then handle as char
// 	// if found run find_key()
// 		// move into it, 
// 		// get value of key
// 	// replace $key with the kay's value
// }

char	*variable_expansions_rl2(t_data *data, t_env *envs, char *rl)
{
	size_t	start;
	size_t	end;
	int new_len;
	int i;
	int j;
	char *temp_key;
	char *value;
	char *new_rl;

	start = 0;
	end = 0;
	new_rl = ft_strdup(rl);
	while (new_rl[start]) // loop through arg
	{
		ft_printf("first\n");
		ft_printf("rl: %s\n", rl);
		// ft_printf("rl[%d]: %s\n", start, rl[start]);
		// if (is_pipe_or_redirect(&rl[start]) < 1) // or special character
		// 	continue ;
		if (ft_strncmp(&new_rl[start], "$", 1) == 0 && !(ft_isdigit(new_rl[++start]) // there is a function for this
			|| new_rl[start] == ' ' || new_rl[start] == '\0'))
		{
			ft_printf("aaaaaaaaaaaa\n");
			end = start;
			// start--;
			while (end < ft_strlen(new_rl) && (new_rl[end] != ' ' || new_rl[end] != '\0'))
			{
				ft_printf("end: %d\n", end);
				ft_printf("rl[%d]: %c\n", end, new_rl[end]);
				ft_printf("\tsecond\n");
				end++;
			}
			temp_key = malloc(sizeof(char) * (end - start) + 1);
			while (start < end)
			{
				ft_printf("\t\tthird\n");
				temp_key[start] = rl[start];
				start++;
			}
			temp_key[start] = 0;
			if (find_node(envs, temp_key, data) == 0)
			{
				ft_printf("1 TESTTTTT\n");
				// new_rl = ft_strdup(rl);
				// free(rl);
				// rl = fill_new_rl(data, new_rl, temp_key, end);
				value = find_keys_value(envs, temp_key);
				ft_printf("2 TESTTTTT\n");
				if (value != NULL) // replace $key with value in arg
				{
					ft_printf("value= %s\n", value);
					new_len = ft_strlen(rl) - (end - start - 1) + ft_strlen(value) + 1;
					free(new_rl);
					new_rl = malloc(sizeof(char) * new_len);
					i = 0;
					j = 0;
					while (i < new_len) // then copy
					{
						ft_printf("\t\t\tfourth\n");
						if (ft_strncmp(&rl[i], "$", 1) == 0)
						{
							while (start < end)
							{
								ft_printf("\t\t\t\tfifth\n");
								new_rl[i] = value[j];
								start++;
								j++;
							}
						}
						new_rl[i] = rl[i];
					}
					// free(rl);
					// rl = ft_strdup(new_rl);
					return (new_rl);
				}
				else // remove $ or give error, check bash for what to do
					ft_printf("doesn't work\n");
			}
			return (new_rl);
		}
		start++;
	}
	return (new_rl);
}


int is_pipe_or_redirect(char *arg) // there is a function for this
{	
	if (ft_strncmp(arg, "|", 2))
		return (0);
	else if (ft_strncmp(arg, "||", 3))
		return (-1);
	else if (ft_strncmp(arg, ">>", 3))
		return (-2);
	else if (ft_strncmp(arg, ">", 2))
		return (-3);
	else if (ft_strncmp(arg, "<<", 3))
		return (-4);
	else if (ft_strncmp(arg, "<", 2))
		return (-5);
	return (1);
}