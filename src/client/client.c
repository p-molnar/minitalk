/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   client.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: pmolnar <pmolnar@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/14 10:07:05 by pmolnar       #+#    #+#                 */
/*   Updated: 2022/03/19 19:55:06 by pmolnar       ########   odam.nl         */
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
#include <string.h>

#define STATUS_BAR_WIDTH 30

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

void	print_status(t_data *data, char *msg)
{
	size_t 			total;
	long			finished;
	size_t			i;

	total = strlen(data->msg);
	finished = msg - data->msg;
	// system("clear");
	printf("%s[i]	transmission status:%s\n", KYEL, KDEF);
	printf("message_sent: ");
	printf("[");
	i = 0;
	while (i++ < (float) finished / total * STATUS_BAR_WIDTH)
		printf("#");
	while (i++ <= STATUS_BAR_WIDTH)
		printf(" ");
	printf("] %d%%\n", (int)(100.0 * finished / total));
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
			if (bit_char & 1)
			{
				// printf("1");
				if (kill (pid, SIGUSR1))
					throw_error(SIGNAL_ERR);
			}
			else
			{
				// printf("0");
				kill (pid, SIGUSR2);
			}
			bit_char = bit_char >> 1;
			usleep(100);
			i++;
		}
		msg++;
		// print_status(data, msg);
	}
}

int	main(int argc, char *argv[])
{
	t_data	data;

	parse_cla(argc, argv, &data);
	post_msg_to_server(&data);
	return (EXIT_SUCCESS);
}
