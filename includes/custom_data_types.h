/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   custom_data_types.h                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: pmolnar <pmolnar@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/14 13:09:10 by pmolnar       #+#    #+#                 */
/*   Updated: 2022/03/22 23:38:34 by pmolnar       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUSTOM_DATA_TYPES_H
# define CUSTOM_DATA_TYPES_H
# include <sys/types.h>
# include <stdbool.h>
typedef struct s_clt_data
{
	pid_t				srv_pid;
	size_t				msg_len;
	char				*msg;
	struct sigaction	action;	
}				t_clt_data;

typedef struct s_srv_data
{
	char				*msg;
	size_t				msg_len;
	unsigned char		bite;
	size_t				bit_count;
	bool				is_msg_len_decoded;
	struct sigaction	action;	
}				t_srv_data;

#endif