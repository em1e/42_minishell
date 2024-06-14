/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_not.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkettune <vkettune@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 16:00:43 by araveala          #+#    #+#             */
/*   Updated: 2024/06/12 17:46:58 by araveala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "minishell.h"

// note that running cd .. ls(or other) or cd ../ ls(or other) , only take you back a dir, does not interact with other commands 

// the idea now is that i split the readline by space into a 2d array, i am not considering if there are spaces inbetween quotes with commands eg "ls    " | grep "objs    " , this should command not found anyway
// flags will also be seperate 

// string is rl
void collect_cmd_array(t_tokens *tokens, char *string)
{
	int i;
	int x;
	char *tmp;

	x = total_words_c(string, ' ');
	i = 0;
	tokens->args = ft_split_adv(string, ' '); // only double, no single
	tmp = NULL;
	pipe_collector(tokens, tokens->args); //maybe dont need
	tokens->array_count = x;
	if (tokens->args == NULL)
	{
		ft_printf("malloc fail in parsing , making of array of args\n");
		return ;
	}	
	i = 0;
	mini_parser(tokens, i, x);
}
int	null_check(char *str1, t_env *str2, char *str3)
{
	if (str1 == NULL)
	{
		ft_printf("ENVS KEY NULL \n");
		return (0);
	}
	if (str2 == NULL)
	{
		ft_printf("ENVS IS NULL\n");
		return (0);
	}
	if (str3 == NULL)
	{
		ft_printf("STRING IS NULL"); // may not need this check, sofar alwasy hardcoded
		return (-1);
	}
	else
		return (1);
}
int	find_passage(t_data *all, char *cmd, char *string, int divert)
{
	int path_found;
	(void)cmd;

	path_found = 0;
	if(null_check(all->env->key, all->env, string) != 1)
		return (-1);
	if (find_node(all->env, string, all) == 1 && all->tmp->env_line != NULL)
	{
		if (divert == 2)
		{
			if (check_dir(all->tmp->env_line) == 0)
				return (free_extra_return_function(all->tmp->env_line, -1));
			else
				all->tmp->filename = ft_strdup(all->tmp->env_line);
			return (free_extra_return_function(all->tmp->env_line, 1));
		}
		else
		{
			path_found = check_path(all->tmp->env_line, divert, all, cmd);
			free_string(all->tmp->env_line);
		}
	}
	if (path_found == 0)
		return (-1);
	return (1);
}

static void	set_array(t_data *data)// char *flag, char *arguments)
{
	data->tmp->ex_arr[0] = data->tmp->filename;
	data->tmp->ex_arr[1] = NULL; // flag;
	data->tmp->ex_arr[2] = NULL; // arguments;
	data->tmp->ex_arr[3] = NULL; // last one is null
}

static void	split_diversion(t_data *data, int divert, char *string)
{
	if (divert == 1) // PATH
		data->tmp->array = ft_split(string, ':');
	else if (divert == 2) // HOME
		data->tmp->array = ft_split(string, ' ');
	if (data->tmp->array == NULL)
	{
		printf("temp[i] is null for some reason\n"); // remove?
		// error
	}
}
int	check_and_excute(t_data *all, char *str, char *cmd, char *suffix, int i)
{
	size_t cmd_len;

	cmd_len = ft_strlen(cmd);
	if (ft_strncmp(str, cmd, cmd_len) == 0 && ft_strlen(str) == cmd_len)
	{
		all->tmp->filename = ft_strjoin(all->tmp->array[i], suffix);
		set_array(all); //, NULL, NULL, NULL);
		if (simple_fork(all) == -1)
			return (-1);
		collective_free(all->tmp->filename, suffix, all->tmp->array); // do we need this data if so , no free yet
		//closedir(dir);
		return (1);
	}
	return (0);
}
int	check_path(char *string, int divert, t_data *all, char *cmd)
{
	struct dirent	*dp;
	DIR				*dir; 
	char			*suffix;
	int				i;

	i = 0;
	suffix = ft_strjoin("/", cmd);
	if (suffix == NULL || ft_strlen(cmd) == 0)
		return (free_extra_return_function(suffix, 0));
	split_diversion(all, divert, string);
	while (all->tmp->array[i] != NULL && ++i)
	{		
		if (check_dir(all->tmp->array[i]) == 1)
		{
			dir = opendir(all->tmp->array[i]);
			dp = readdir(dir);
			while (dp != NULL)
			{
				if (check_and_excute(all, dp->d_name, cmd, suffix, i) == 1) // 5 parameters
				{
					closedir(dir);
					return (1);
				}
				dp = readdir(dir);
			}
			closedir(dir);
		}
		else
			return (free_extra_return_function(suffix, -1));
	}
	collective_free(NULL, suffix, all->tmp->array);
	return (0);
}
