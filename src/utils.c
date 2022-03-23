/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: pmolnar <pmolnar@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/23 10:42:19 by pmolnar       #+#    #+#                 */
/*   Updated: 2022/03/23 12:07:01 by pmolnar       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "../include/custom_data_types.h"
#include "../include/errors.h"

void	send_signal(int signum, pid_t pid)
{
	if (kill(pid, signum))
		throw_error(SIGNAL_ERR);
}

void	set_bit(int pos, unsigned char *bite)
{
	unsigned char	mask;
	
	mask = 1 << pos;
	*bite = *bite | mask;
}