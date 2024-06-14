/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkettune <vkettune@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 12:56:31 by vkettune          #+#    #+#             */
/*   Updated: 2024/06/14 09:00:57 by vkettune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	minishell(t_data *data)
{
	char	*rl;
	char *new_rl;
	
	while (1)
	{
		set_signals();
		rl_on_new_line();
		rl = readline(data->prompt);
		add_history(rl);
		if (rl)
		{
			// ft_printf("minishell rl[0]: %s\n", rl[0]);
			new_rl = variable_expansions_rl2(data, data->env, rl);
			free(rl);
			ft_printf("Got here!\n");
			collect_cmd_array(data->tokens, new_rl);
			// if (data->tokens->args[0] == NULL)
			// 	break ;
			if (handle_line(*data, *data->env, data->tokens, new_rl) == -1)
			{
				ft_printf("error\n");
				break ;
			}
			free_array(data->tokens->args);
			free(new_rl);
		}
		if (!rl)
			break ;
	}
	ft_printf("exit\n"); // move this tp ^D function
}

int main(int argc, char **argv)//, char **env)
{
	t_data data;
	static t_tokens tokens;
	static t_temps tmp;

	(void)argc;
	(void)argv;
	data.tokens = &tokens;
	data.tmp = &tmp;
	data.env = init(&data);
	ft_printf("env->key: %s\n", data.env->key);
	minishell(&data); // exits when whitsespace
	ft_printf("env->key: %s\n", data.env->key);
	free_nodes(data.env);
	return (0);
}
