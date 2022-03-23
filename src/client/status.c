/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   status.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: pmolnar <pmolnar@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/23 11:37:16 by pmolnar       #+#    #+#                 */
/*   Updated: 2022/03/23 12:51:09 by pmolnar       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <custom_data_types.h>
#include <utils.h>
#include <errors.h>
#include "../../ft_printf/headers/ft_printf.h"

#include <stdio.h>

static void	print_title(const char *title)
{
	ft_printf("%s[i]	%s:%s\n", KYEL, title, KDEF);
	// ft_printf("%s: ", title);
}

void	print_status(size_t total, size_t completed, const char *title)
{
	static size_t	exec_count;
	size_t			i;

	if (exec_count++ == 0)
		print_title(title);
	ft_printf("|");
	i = 0;
	while (i++ < (float) completed / total * STATUS_BAR_WIDTH)
		ft_printf("%s %s", BWHT, KDEF);
	while (i++ <= STATUS_BAR_WIDTH)
		ft_printf("-");
	ft_printf("|	%d%%\n", (int)(100.0 * completed / total));
	printf("\33[2K\r");
	fflush(stdout);
}