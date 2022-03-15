/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   server.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: pmolnar <pmolnar@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/14 11:13:31 by pmolnar       #+#    #+#                 */
/*   Updated: 2022/03/15 11:52:20 by pmolnar       ########   odam.nl         */
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

void	dislpay_server_info(pid_t pid)
{
	ft_printf("%sServer started\n%s", KGRN, KDEF);
	ft_printf("Server PID: %d\n", pid);
}

int	main(void)
{
	pid_t	server_pid;	

	server_pid = getpid();
	dislpay_server_info(server_pid);
	while (1)
	{
		pause();
	}
	return (EXIT_SUCCESS);
}
