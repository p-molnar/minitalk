/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   status.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: pmolnar <pmolnar@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/23 11:37:16 by pmolnar       #+#    #+#                 */
/*   Updated: 2022/03/23 11:50:50 by pmolnar       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <custom_data_types.h>
#include <utils.h>
#include <errors.h>
#include "../../ft_printf/headers/ft_printf.h"

void	print_status(t_clt_data *data, char *msg)
{
	size_t 			total;
	long			finished;
	size_t			i;

	total = ft_strlen(data->msg);
	finished = msg - data->msg;
	// system("clear");
	ft_printf("%s[i]	transmission status:%s\n", KYEL, KDEF);
	ft_printf("message_sent: ");
	ft_printf("|");
	i = 0;
	while (i++ < (float) finished / total * STATUS_BAR_WIDTH)
		ft_printf("%s %s", BWHT, KDEF);
	while (i++ <= STATUS_BAR_WIDTH)
		ft_printf("-");
	ft_printf("|	%d%%\n", (int)(100.0 * finished / total));
}
