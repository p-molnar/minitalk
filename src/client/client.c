/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   client.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: pmolnar <pmolnar@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/14 10:07:05 by pmolnar       #+#    #+#                 */
/*   Updated: 2022/03/17 14:40:44 by pmolnar       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <stdio.h>
#include <stdbool.h>
#include <custom_data_types.h>
#include <errors.h>
#include <utils.h>
#include "../../ft_printf/headers/ft_printf.h"

void	parse_cla(int argc, char *argv[], t_data *data)
{
	if (argc < 3)
		throw_error(TOO_FEW_CLA);
	else if (argc > 3)
		throw_error(TOO_MANY_CLA);
	data->server_pid = atoi(argv[1]);
	if (data->server_pid < 0)
		throw_error(INVALID_PID);
	data->msg = argv[2];
	if (*(data->msg) == '\0')
		throw_error(INVALID_MSG);
}

void	post_msg_to_server(t_data *data)
{
	char			*msg;
	pid_t			pid;
	size_t			i;
	unsigned int	bit_char;
	
	msg = data->msg;
	pid = data->server_pid;
	while (*msg)
	{
		i = 0;
		bit_char = *msg;
		while (i < 8)
		{
			if (bit_char & 128)
			{
				kill (pid, SIGUSR1);
				printf("1\n");
			}
			else
			{
				kill (pid, SIGUSR2);
				printf("0\n");
			}
			bit_char = bit_char << 1;
			i++;
		}
		printf("\n");
		msg++;
	}
}

int	main(int argc, char *argv[])
{
	t_data	data;

	parse_cla(argc, argv, &data);
	post_msg_to_server(&data);
	return (EXIT_SUCCESS);
}
