/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: pmolnar <pmolnar@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/23 10:42:19 by pmolnar       #+#    #+#                 */
/*   Updated: 2022/03/30 09:36:27 by pmolnar       ########   odam.nl         */
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

double	ft_pow(int base, int power)
{
	size_t	i;

	i = 0;
	if (base != 0 && power == 0)
		return (1);
	while (i < power)
	{
		base *= base;
		i++;
	}
	return (base);
}
