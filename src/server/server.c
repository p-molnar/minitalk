/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   server.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: pmolnar <pmolnar@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/14 11:13:31 by pmolnar       #+#    #+#                 */
/*   Updated: 2022/03/17 19:32:32 by pmolnar       ########   odam.nl         */
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

void	set_bit(int pos)
{
	unsigned int	mask;
	
	mask = 1 << pos;
	if (var.bit_count == 8)
	{
		printf("%c", var.bite);
		var.bit_count = 0;
	}
	var.bite = var.bite | mask;
}

void	dislpay_server_info(pid_t pid)
{
	ft_printf("%sServer started\n%s", KGRN, KDEF);
	ft_printf("Server PID: %d\n", pid);
}

void	decode_bin_0(int exit_code)
{
	(void) exit_code;
	printf("0");
	var.bit_count++;
}

void	decode_bin_1(int exit_code)
{
	(void) exit_code;
	printf("1");
	set_bit(var.bit_count);
	var.bit_count++;
	printf("%c", var.bite);
}
int	main(void)
{
	pid_t			server_pid;
	
	server_pid = getpid();
	var.bite = 0;
	var.bit_count = 0;
	dislpay_server_info(server_pid);
	signal(SIGUSR1, decode_bin_1);
	signal(SIGUSR2, decode_bin_0);
	while (1)
	{
		pause();
	}
	return (EXIT_SUCCESS);
}
