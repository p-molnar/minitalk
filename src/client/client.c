/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   client.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: pmolnar <pmolnar@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/14 10:07:05 by pmolnar       #+#    #+#                 */
/*   Updated: 2022/03/30 15:30:01 by pmolnar       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minitalk.h>

t_clt_data	g_data;

static void	listen_to_delivered_signal(int signum)
{
	if (signum == SIGUSR1)
	{
		g_data.is_msg_printed = true;
		ft_printf("\n%sJob #%d - Successful delivery and printing%s\n", \
		KGRN, g_data.clt_pid, KDEF);
	}
}

static void	post_msg_len(t_clt_data *g_data, pid_t srv_pid)
{
	size_t	msg_len;
	size_t	i;

	msg_len = g_data->msg_len;
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

static void	post_msg(t_clt_data *g_data, pid_t srv_pid)
{
	unsigned char	bite_char;
	size_t			i;
	size_t			j;

	i = 0;
	while (g_data->msg[i])
	{
		j = 0;
		bite_char = g_data->msg[i];
		while (j < CHAR_SIZE)
		{
			if (bite_char & 1)
				send_signal(SIGUSR1, srv_pid);
			else
				send_signal(SIGUSR2, srv_pid);
			bite_char = bite_char >> 1;
			j++;
			usleep(SLEEP_TIME);
		}
		i++;
	}
}

void	parse_cla(int argc, char *argv[], t_clt_data *g_data)
{
	if (argc < 3)
		throw_error(TOO_FEW_CLA);
	else if (argc > 3)
		throw_error(TOO_MANY_CLA);
	g_data->srv_pid = atoi(argv[1]);
	if (g_data->srv_pid < 0)
		throw_error(INVALID_PID);
	g_data->msg = argv[2];
	if (*(g_data->msg) == '\0')
		throw_error(INVALID_MSG);
	g_data->msg_len = ft_strlen(g_data->msg);
}

int	main(int argc, char *argv[])
{
	parse_cla(argc, argv, &g_data);
	g_data.action.sa_handler = listen_to_delivered_signal;
	if (sigaction(SIGUSR1, &g_data.action, NULL))
		throw_error(SIGACTION_ERR);
	g_data.is_msg_printed = false;
	g_data.clt_pid = getpid();
	post_msg_len(&g_data, g_data.srv_pid);
	post_msg(&g_data, g_data.srv_pid);
	while (1)
	{
		if (g_data.is_msg_printed)
			return (EXIT_SUCCESS);
		pause();
	}
}
