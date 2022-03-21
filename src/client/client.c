/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   client.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: pmolnar <pmolnar@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/14 10:07:05 by pmolnar       #+#    #+#                 */
/*   Updated: 2022/03/21 17:46:33 by pmolnar       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <custom_data_types.h>
#include <errors.h>
#include <utils.h>
#include "../../ft_printf/headers/ft_printf.h"
#include <string.h>
#include <stdio.h>

#define STATUS_BAR_WIDTH 30

size_t	ft_strlen(char *str)
{
	size_t	i;
	
	i = 0;
	while (str[i])
		i++;
	return (i);
}

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

void	print_status(t_clt_data *data, char *msg)
{
	size_t 			total;
	long			finished;
	size_t			i;

	total = strlen(data->msg);
	finished = msg - data->msg;
	// system("clear");
	ft_printf("%s[i]	transmission status:%s\n", KYEL, KDEF);
	ft_printf("message_sent: ");
	ft_printf("|");
	i = 0;
	while (i++ < (float) finished / total * STATUS_BAR_WIDTH)
		ft_printf("%s %s", BWHT, KDEF);
	while (i++ <= STATUS_BAR_WIDTH)
		ft_printf("-");
	ft_printf("|	%d%%\n", (int)(100.0 * finished / total));
}

void	set_bit(int pos, unsigned char *bite)
{
	unsigned char	mask;
	
	mask = 1 << pos;
	*bite = *bite | mask;
}

void	post_msg_len(t_clt_data *data, pid_t srv_pid);
{
	size_t	msg_len;
	size_t	i;

	msg_len = data->msg_len;
	i = 0;
	while (i < 32)
	{
		if (msg_len & 1)
		{
			kill(srv_pid, SIGUSR1);
		}
		else
		{
			kill(srv_pid, SIGUSR2);
		}
		msg_len = msg_len >> 1;
		i++;
		usleep(1000);
	}

}

void	post_msg(t_clt_data *data, pid_t srv_pid)
{
	char			*msg;
	unsigned char	bit_char;
	size_t			i;
	
	msg = data->msg;
	while (*msg)
	{
		i = 0;
		unsigned char bite = 0;
		bit_char = *msg;
		// printf("char %ld: ", msg - data->msg);
		while (i < 8)
		{
			if (bit_char & 1)
			{
				write(1, "1", 1);
				// set_bit(i, &bite);
				if (kill (srv_pid, SIGUSR1))
					throw_error(SIGNAL_ERR);
			}
			else
			{
				write(1, "0", 1);
				if (kill (srv_pid, SIGUSR2))
					throw_error(SIGNAL_ERR);
			}
			bit_char = bit_char >> 1;
			usleep(150);
			i++;
		}
		write(1, " ", 1);
		write(1, &bite, 1);
		write(1, "\n", 1);
		msg++;
		// print_status(data, msg);
	}
}

int	main(int argc, char *argv[])
{
	t_clt_data	data;
	
	parse_cla(argc, argv, &data);
	post_msg_len(&data, data.srv_pid);
	// post_msg(&data, data.srv_pid);
	return (EXIT_SUCCESS);
}
