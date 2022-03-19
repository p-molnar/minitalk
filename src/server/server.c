/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   server.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: pmolnar <pmolnar@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/14 11:13:31 by pmolnar       #+#    #+#                 */
/*   Updated: 2022/03/19 20:00:11 by pmolnar       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <stdbool.h>
#include <stdio.h>
#include <errors.h>
#include <custom_data_types.h>
#include "../../ft_printf/headers/ft_printf.h"

t_var	var;

void	dislpay_server_info(pid_t pid)
{
	ft_printf("Server started\n");
	ft_printf("Server PID: %d\n", pid);
}

void	set_bit(int pos)
{
	unsigned int	mask;
	
	mask = 1 << pos;
	var.bite = var.bite | mask;
	// printf("set_bit %d\n", var.bite);
}

void	reset_vars(void)
{
	var.bit_count = 0;
	var.bite = 0;
}

void	decode_signal(signum)
{
	if (signum == SIGUSR1)
	{
		set_bit(var.bit_count);
		// printf("0");
	}
	// fflush(stdout);
	if (var.bit_count++ == 7)
	{
		write(1, &var.bite, 1);
		reset_vars();
	}
}

int	main(void)
{
	struct sigaction sa;
	pid_t			server_pid;
	
	server_pid = getpid();
	var.bite = 0;
	var.bit_count = 0;
	sa.sa_handler = decode_signal;
	dislpay_server_info(server_pid);
	if (sigaction(SIGUSR1, &sa, NULL))
		return (EXIT_FAILURE);
	if (sigaction(SIGUSR2, &sa, NULL))
		return (EXIT_FAILURE);
	while (1)
	{
		;
	}
	return (EXIT_SUCCESS);
}
