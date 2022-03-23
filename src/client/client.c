/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   client.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: pmolnar <pmolnar@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/14 10:07:05 by pmolnar       #+#    #+#                 */
/*   Updated: 2022/03/23 11:56:18 by pmolnar       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

#include <custom_data_types.h>
#include <errors.h>
#include <utils.h>
#include "../../ft_printf/headers/ft_printf.h"
#include <minitalk.h>

t_clt_data	data;

void	parse_cla(int argc, char *argv[], t_clt_data *data)
{
	if (argc < 3)
		throw_error(TOO_FEW_CLA);
	else if (argc > 3)
		throw_error(TOO_MANY_CLA);
	data->srv_pid = atoi(argv[1]);
	if (data->srv_pid < 0)
		throw_error(INVALID_PID);
	data->msg = argv[2];
	if (*(data->msg) == '\0')
		throw_error(INVALID_MSG);
	data->msg_len = ft_strlen(data->msg);
}

void	set_bit(int pos, unsigned char *bite)
{
	unsigned char	mask;
	
	mask = 1 << pos;
	*bite = *bite | mask;
}

void	post_msg_len(t_clt_data *data, pid_t srv_pid)
{
	size_t	msg_len;
	size_t	i;

	msg_len = data->msg_len;
	i = 0;
	while (i < 32)
	{
		if (msg_len & 1)
			send_signal(SIGUSR1, srv_pid);
		else
			send_signal(SIGUSR2, srv_pid);
		msg_len = msg_len >> 1;
		i++;
		usleep(SLEEP_TIME);
	}
}

void	post_msg(t_clt_data *data, pid_t srv_pid)
{
	// char			*msg;
	unsigned char	bit_char;
	size_t			i;
	
	// msg = data->msg;
	while (*(data->msg))
	{
		i = 0;
		bit_char = *(data->msg);
		while (i < 8)
		{
			if (bit_char & 1)
				send_signal(SIGUSR1, srv_pid);
			else
				send_signal(SIGUSR2, srv_pid);
			bit_char = bit_char >> 1;
			usleep(SLEEP_TIME);
			i++;
		}
		data->msg++;
		// print_status(data, msg);
	}
}

void	listen_to_delievered_signal(int signum)
{
	// static size_t	delievered_char_count;	
	if (signum == SIGUSR1)
	{
		data.is_msg_printed = true;
	}
	else if (signum == SIGUSR2)
	{
		ft_printf("message has been printed\n");
		data.is_msg_printed = true;
	}
}

int	main(int argc, char *argv[])
{
	parse_cla(argc, argv, &data);
	init_vars(&data);
	init_signal_listener(&data);
	post_msg_len(&data, data.srv_pid);
	post_msg(&data, data.srv_pid);
	while (1)
	{
		if (data.is_msg_printed)
			return (EXIT_SUCCESS);
		pause();
	}
}
