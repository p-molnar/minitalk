/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   errors.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: pmolnar <pmolnar@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/14 14:36:05 by pmolnar       #+#    #+#                 */
/*   Updated: 2022/03/20 17:00:35 by pmolnar       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_printf/headers/ft_printf.h"
#include <stdlib.h>
#include <errors.h>

int	throw_error(int error_code)
{
	ft_printf("%s[!]	ERROR - INVALID INPUT: ", KRED);
	if (error_code == TOO_FEW_CLA)
		ft_printf("too few command line arguments%s\n", KDEF);
	else if (error_code == TOO_MANY_CLA)
		ft_printf("too many command line arguments%s\n", KDEF);
	else if (error_code == INVALID_PID)
		ft_printf("PID must be positive%s\n", KDEF);
	else if (error_code == INVALID_MSG)
		ft_printf("Empty message - nothing to be sent%s\n", KDEF);
	else if (error_code == SIGNAL_ERR)
		ft_printf("Signal error\n");
	else
		ft_printf("Unknown error%s\n", KDEF);
	ft_printf("	usage: ./client <PID> <message-to-server>\n");
	exit (EXIT_FAILURE);
}

void	throw_warning(int error_code)
{
	ft_printf("%s[!]	WARNING - QUESITONABLE INPUT: ", KYEL);
	if (error_code == INVALID_MSG)
		ft_printf("Message is empty, nothing to be sent to server%s\n", KDEF);
	else
		ft_printf("Unknown error%s\n", KDEF);
	ft_printf("%s[hint]	usage: ./client <PID> <message-to-server>\n", KDEF);
}