/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   errors.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: pmolnar <pmolnar@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/14 14:40:49 by pmolnar       #+#    #+#                 */
/*   Updated: 2022/03/30 15:29:24 by pmolnar       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

# define TOO_FEW_CLA 1
# define TOO_MANY_CLA 2
# define INVALID_PID 3
# define INVALID_MSG 4
# define KILL_ERR 5
# define MALLOC_FAIL 6
# define SIGACTION_ERR 7

int		throw_error(int error_code);

#endif