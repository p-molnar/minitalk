/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   server.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: pmolnar <pmolnar@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/14 11:13:31 by pmolnar       #+#    #+#                 */
/*   Updated: 2022/03/21 17:59:19 by pmolnar       ########   odam.nl         */
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
#include <math.h>

t_srv_data	var;
char arr[1000] = {0};

void	dislpay_server_info(pid_t srv_pid)
{
	ft_printf("%sServer started%s\n", KGRN, KDEF);
	ft_printf("Server PID: %d\n", srv_pid);
	fflush(stdout);
}

// void	set_bit(int pos)
// {
// 	unsigned char	mask;
	
// 	mask = 1 << pos;
// 	var.bite = var.bite | mask;
// }

void	decode_signal(signum)
{
	static int i;
	if (signum == SIGUSR1)
	{
		// write(1, "1", 1);
		// var.bite += pow(2, var.bit_count);
		var.msg_len += pow(2, var.bit_count);
		// set_bit(var.bit_count);
	}
	else if (signum == SIGUSR2)
	{
		// write(1, "0", 1);
	}
	if (var.bit_count++ == 7)
	{
		// write(1, " ", 1);
		write(1, &var.bite, 1);
		// write(1, "\n", 1);
		arr[i] = var.bite;
		var.bite = 0b00000000;
		var.bit_count = 0;
		i++;
	}
	if (i == 449)
		printf("%s", arr);
}

int	main(void)
{
	pid_t				srv_pid;
	
	srv_pid = getpid();
	var.bite = 0b00000000;
	var.bit_count = 0;
	var.action.sa_handler = decode_signal;
	sigemptyset(&var.action.sa_mask);
	dislpay_server_info(srv_pid);
	if (sigaction(SIGUSR1, &var.action, NULL))
		return (EXIT_FAILURE);
	if (sigaction(SIGUSR2, &var.action, NULL))
		return (EXIT_FAILURE);
	while (1)
	{
		pause();
	}
	return (EXIT_SUCCESS);
}
