/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: pmolnar <pmolnar@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/23 11:11:27 by pmolnar       #+#    #+#                 */
/*   Updated: 2022/03/23 12:07:16 by pmolnar       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# include <signal.h>
# include <custom_data_types.h>

int		ft_atoi(const char *);
size_t	ft_strlen(const char *str);
void	send_signal(int signum, pid_t pid);
void	init_vars(t_clt_data *data);
void	init_signal_listener(t_clt_data *data);
void	set_bit(int pos, unsigned char *bite);

#endif