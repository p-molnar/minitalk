/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   server.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: pmolnar <pmolnar@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/14 11:13:31 by pmolnar       #+#    #+#                 */
/*   Updated: 2023/09/24 12:06:51 by pmolnar       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minitalk.h>

t_srv_data	g_data;

static void	display_server_info(void)
{
	ft_printf("Server status: %sActive%s\n", KGRN, KDEF);
	ft_printf("Server PID: %d\n", g_data.srv_pid);
}

static void	reset_vars(void)
{
	g_data.bite = 0;
	g_data.msg_len = 0;
	g_data.bit_count = 0;
	g_data.is_msg_len_decoded = false;
}

static void	decode_msg_len(int signum)
{
	static size_t	bit_count;

	if (signum == SIGUSR1)
		g_data.msg_len += ft_pow(2, bit_count);
	if (bit_count++ == 31)
	{
		g_data.is_msg_len_decoded = true;
		bit_count = 0;
		g_data.msg = malloc((g_data.msg_len + 1) * sizeof(unsigned char));
		if (g_data.msg == NULL)
			throw_error (MALLOC_FAIL);
	}
}

static void	decode_msg(int signum, siginfo_t *info, void *ucontext)
{
	static size_t	i;

	(void)ucontext;
	if (!g_data.is_msg_len_decoded)
		decode_msg_len(signum);
	else
	{
		if (signum == SIGUSR1)
			g_data.bite += ft_pow(2, g_data.bit_count);
		if (g_data.bit_count++ == (CHAR_SIZE - 1))
		{
			g_data.msg[i++] = g_data.bite;
			g_data.bit_count = 0;
			g_data.bite = 0;
		}
		if (i == g_data.msg_len)
		{
			ft_printf("\n\n%sJob #%d - message%s\n", KMAG, info->si_pid, KDEF);
			write(1, g_data.msg, g_data.msg_len);
			i = 0;
			free(g_data.msg);
			reset_vars();
			send_signal(SIGUSR1, info->si_pid);
		}
	}
}

int	main(void)
{
	g_data.srv_pid = getpid();
	g_data.action.sa_sigaction = decode_msg;
	reset_vars();
	display_server_info();
	if (sigaction(SIGUSR1, &g_data.action, NULL))
		throw_error(SIGACTION_ERR);
	if (sigaction(SIGUSR2, &g_data.action, NULL))
		throw_error(SIGACTION_ERR);
	while (1)
		pause();
	return (EXIT_SUCCESS);
}
