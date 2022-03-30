/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: pmolnar <pmolnar@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/23 10:42:19 by pmolnar       #+#    #+#                 */
/*   Updated: 2022/03/30 15:33:10 by pmolnar       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "../include/custom_data_types.h"
#include "../include/errors.h"

void	send_signal(int signum, pid_t pid)
{
	if (kill(pid, signum))
		throw_error(KILL_ERR);
}

void	set_bit(int pos, unsigned char *bite)
{
	unsigned char	mask;

	mask = 1 << pos;
	*bite = *bite | mask;
}

long int	ft_pow(int base, int power)
{
	size_t			i;
	long int		base_tmp;

	i = 0;
	base_tmp = 1;
	while (i < (size_t)power)
	{
		base_tmp *= base;
		i++;
	}
	return (base_tmp);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
