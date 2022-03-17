/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   server.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: pmolnar <pmolnar@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/14 11:13:31 by pmolnar       #+#    #+#                 */
/*   Updated: 2022/03/17 14:58:47 by pmolnar       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <stdbool.h>
#include <stdio.h>
#include <errors.h>
#include "../../ft_printf/headers/ft_printf.h"

unsigned int	bite;

unsigned int set_bit(int val, int pos)
{
	unsigned int	mask;
	
	mask = 1 << pos;
	if (++bit_count == 8)
		bit_count = 0;
	return (val | mask);
}

void	dislpay_server_info(pid_t pid)
{
	ft_printf("%sServer started\n%s", KGRN, KDEF);
	ft_printf("Server PID: %d\n", pid);
}

void	decode_bin_0(int exit_code)
{
	(void) exit_code;
}

void	decode_bin_0(int exit_code)
{
	(void) exit_code;

}
int	main(void)
{
	pid_t			server_pid;
	size_t			bit_count;

	bite = 0;
	server_pid = getpid();
	dislpay_server_info(server_pid);
	signal(SIGUSR1, decode_bin_0);
	signal(SIGUSR2, decode_bin_1);
	while (1)
	{
		pause();
	}
	return (EXIT_SUCCESS);
}
