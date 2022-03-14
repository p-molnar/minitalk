/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   client.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: pmolnar <pmolnar@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/14 10:07:05 by pmolnar       #+#    #+#                 */
/*   Updated: 2022/03/14 13:14:20 by pmolnar       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <stdio.h>
#include <stdbool.h>
#include <custom_data_types.h>

int	main(int argc, char *argv[])
{
	size_t	i;
	size_t	j;
	if (argc != 3)
		return (EXIT_FAILURE);
	i = 1;
	while (i < (size_t) argc)
	{
		j = 0;
		while (argv[i][j])
		{
			printf("i: %zu, j: %zu, c: %c\n", i, j, argv[i][j]);
			j++;
		}
		i++;
	}
	return (EXIT_SUCCESS);
}
