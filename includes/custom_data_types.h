/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   custom_data_types.h                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: pmolnar <pmolnar@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/14 13:09:10 by pmolnar       #+#    #+#                 */
/*   Updated: 2022/03/14 13:12:38 by pmolnar       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUSTOM_DATA_TYPES_H 
# define CUSTOM_DATA_TYPES_H
# include <sys/types.h>

typedef struct	s_arg
{
	pid_t	pid;
	char	*msg;
}				t_arg;

#endif