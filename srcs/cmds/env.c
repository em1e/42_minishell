/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkettune <vkettune@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 20:43:28 by vkettune          #+#    #+#             */
/*   Updated: 2024/08/08 15:51:46 by vkettune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_env(t_data *data)
{
	t_env	*env;
	int found_key;
	char	*value;

	env = data->env;
	found_key = find_node(env, "PATH", data);
	value = 0;
	if (found_key == 0)
	{
		cmd_error("env", NULL); // returns "minishell: env: Success" ???
		return ;
	}
	else
	{
		if (data->tokens->args[data->i + 1] != NULL) // what does this if statement do
		{
			if (data->tokens->args[data->i + 1][0] != '|')
			{
				if (check_dir(data->tokens->args[data->i + 1]) == 0)
				{
					cmd_error("env", data->tokens->args[data->i + 1]);
					return ;
				}
			}
		}
		while (env != NULL)
		{
			// write(2, "printing env\n", 13);
			printf("%s=%s\n", env->key, env->value);
			env = env->next;
		}
	}
	// fix with "env -i ./minishell" "env -i bash"
}
