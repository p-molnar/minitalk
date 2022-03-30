/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   errors.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: pmolnar <pmolnar@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/14 14:36:05 by pmolnar       #+#    #+#                 */
/*   Updated: 2022/03/30 15:34:17 by pmolnar       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf/headers/ft_printf.h"
#include <stdlib.h>
#include <errors.h>
#include <colors.h>

static void	give_hint(int error_code)
{
	ft_printf("%s[?]	HINT: ", KYEL);
	if (error_code == TOO_FEW_CLA || error_code == TOO_FEW_CLA)
		ft_printf("Check whether you have sufficient amount of args%s\n", KDEF);
	else if (error_code == INVALID_MSG)
		ft_printf("Send at least one character to the server%s\n", KDEF);
	else if (error_code == KILL_ERR)
		ft_printf("Check if server has started, or PID is correct%s\n", KDEF);
	ft_printf("\n	usage: ./client <PID> <message-to-server>\n");
}

int	throw_error(int error_code)
{
	ft_printf("%s[!]	ERROR: ", KRED);
	if (error_code == TOO_FEW_CLA)
		ft_printf("too few command line arguments%s\n", KDEF);
	else if (error_code == TOO_MANY_CLA)
		ft_printf("too many command line arguments%s\n", KDEF);
	else if (error_code == INVALID_PID)
		ft_printf("PID must be positive%s\n", KDEF);
	else if (error_code == INVALID_MSG)
		ft_printf("Empty message - nothing to be sent%s\n", KDEF);
	else if (error_code == KILL_ERR)
		ft_printf("Signal error (kill function)%s\n", KDEF);
	else if (error_code == MALLOC_FAIL)
		ft_printf("Memory allocation failed%s\n", KDEF);
	else if (error_code == SIGACTION_ERR)
		ft_printf("Signal error (sigaction function)%s\n", KDEF);
	else
		ft_printf("Unknown error%s\n", KDEF);
	give_hint(error_code);
	exit (EXIT_FAILURE);
}
