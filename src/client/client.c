/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   client.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: pmolnar <pmolnar@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/14 10:07:05 by pmolnar       #+#    #+#                 */
/*   Updated: 2022/03/15 15:29:07 by pmolnar       ########   odam.nl         */
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

int	parse_cla(int argc, char *argv[], t_arg *arg, int *error_code)
{
	if (argc < 3)
	{
		*error_code = TOO_FEW_CLA;
		return (false);
	}
	else if (argc > 3)
	{
		*error_code = TOO_MANY_CLA;
		return (false);
	}
	arg->pid = atoi(argv[1]);
	if (arg->pid < 0)
	{
		*error_code = INVALID_PID;
		return (false);
	}
	arg->msg = argv[2];
	if (*(arg->msg) == '\0')
	{
		*error_code = INVALID_MSG;
		return (false);
	}
	return (true);
}

int	main(int argc, char *argv[])
{
	(void) argc;
	(void) argv;
	// t_arg	arg;
	// bool	is_valid_cla;
	// int		error_code;

	// is_valid_cla = parse_cla(argc, argv, &arg, &error_code);
	// if (!is_valid_cla)
	// 	return (display_client_error(error_code));
	// kill(arg.pid, SIGINT);
	// ft_printf("pid: %d\n", arg.pid);
	// ft_printf("msg: %s\n", arg.msg);
	unsigned int a = 0b1000001;
	ft_printf("bin: %c\n", a);
	return (EXIT_SUCCESS);
}
