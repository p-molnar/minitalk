/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   status.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: pmolnar <pmolnar@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/23 11:37:16 by pmolnar       #+#    #+#                 */
/*   Updated: 2022/03/24 22:14:48 by pmolnar       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <custom_data_types.h>
#include <utils.h>
#include <errors.h>
#include "../../ft_printf/headers/ft_printf.h"

#include <stdio.h>
#include <unistd.h>

void	print_status(size_t total, size_t completed, const char *title)
{
	static size_t	exec_count;
	size_t			i;

	if (exec_count++ == 0)
		ft_printf("[i]	message status\n");
	ft_printf("\33[2K\r");
	ft_printf("%s: ", title);
	ft_printf("|");
	i = 0;
	while (i++ < (float) completed / total * STATUS_BAR_WIDTH)
		ft_printf("%s %s", BWHT, KDEF);
	while (i++ <= STATUS_BAR_WIDTH)
		ft_printf("-");
	ft_printf("|	%d%%", (int)(100.0 * completed / total));
}