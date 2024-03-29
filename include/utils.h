/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: pmolnar <pmolnar@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/23 11:11:27 by pmolnar       #+#    #+#                 */
/*   Updated: 2022/03/30 10:43:56 by pmolnar       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# include <signal.h>
# include <custom_data_types.h>

int			ft_atoi(const char *str);
size_t		ft_strlen(const char *str);
long int	ft_pow(int base, int power);
void		send_signal(int signum, pid_t pid);
void		set_bit(int pos, unsigned char *bite);

#endif