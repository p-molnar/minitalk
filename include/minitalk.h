/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minitalk.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: pmolnar <pmolnar@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/23 11:33:50 by pmolnar       #+#    #+#                 */
/*   Updated: 2022/03/23 12:34:08 by pmolnar       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */


void	init_signal_listener(t_clt_data * data);
void	listen_to_delievered_signal(int signum);
void	print_status(size_t total, size_t completed, const char *title);