/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: pmolnar <pmolnar@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/23 11:53:53 by pmolnar       #+#    #+#                 */
/*   Updated: 2022/03/23 11:57:33 by pmolnar       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdbool.h>
#include <errors.h>
#include <custom_data_types.h>

void	listen_to_delievered_signal(int signum);

void	init_signal_listener(t_clt_data *data)
{
	if (sigaction(SIGUSR1, &data->action, NULL))
		throw_error(SIGNAL_ERR);
	if (sigaction(SIGUSR2, &data->action, NULL))
		throw_error(SIGNAL_ERR);
}

void	init_vars(t_clt_data *data)
{
	data->action.sa_handler = listen_to_delievered_signal;
	data->is_msg_printed = false;
}
