/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   server.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: pmolnar <pmolnar@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/14 11:13:31 by pmolnar       #+#    #+#                 */
/*   Updated: 2022/03/24 21:33:52 by pmolnar       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <stdbool.h>
#include <stdio.h>
#include <math.h>

#include <errors.h>
#include <custom_data_types.h>
#include <utils.h>
#include "../../ft_printf/headers/ft_printf.h"

t_srv_data	data;

void	dislpay_server_info(pid_t srv_pid)
{
	ft_printf("Server status: %sActive%s\n", KGRN, KDEF);
	ft_printf("Server PID: %d\n", srv_pid);
}

void	reset_vars(void)
{
	data.bite = 0;
	data.msg_len = 0;
	data.bit_count = 0;
	data.is_msg_len_decoded = false;
}

void	decode_msg_len(int signum)
{
	static size_t	bit_count;
	if (signum == SIGUSR1)
		data.msg_len += pow(2, bit_count);
	if (bit_count++ == 31)
	{
		data.is_msg_len_decoded = true;
		bit_count = 0;
		data.msg = malloc((data.msg_len + 1) * sizeof(unsigned char));
		if (data.msg == NULL)
			exit(1);
	}
}

void	decode_signal(int signum, siginfo_t *info, void *ucontext)
{
	(void) ucontext;
	static size_t i;
	if (!data.is_msg_len_decoded)
		decode_msg_len(signum);
	else
	{
		if (signum == SIGUSR1)
		{
			data.bite += pow(2, data.bit_count);
		}
		if (data.bit_count++ == 7)
		{
			data.msg[i++] = data.bite;
			data.bit_count = 0;
			data.bite = 0;
			// send_signal(SIGUSR1, info->si_pid);
		}
		if (i == data.msg_len)
		{
			write(1, data.msg, data.msg_len);
			i = 0;
			free(data.msg);
			reset_vars();
			(void) info;
			usleep(500);
			send_signal(SIGUSR2, info->si_pid);
		}
	}
}

int	main(void)
{
	pid_t				srv_pid;
	
	srv_pid = getpid();
	data.action.sa_sigaction = decode_signal;
	reset_vars();
	dislpay_server_info(srv_pid);
	if (sigaction(SIGUSR1, &data.action, NULL))
		return (EXIT_FAILURE);
	if (sigaction(SIGUSR2, &data.action, NULL))
		return (EXIT_FAILURE);
	while (1)
	{
		pause();
	}
	return (EXIT_SUCCESS);
}
