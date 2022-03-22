/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   errors.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: pmolnar <pmolnar@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/14 14:40:49 by pmolnar       #+#    #+#                 */
/*   Updated: 2022/03/21 23:42:29 by pmolnar       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

# define KDEF  "\x1B[0m"
# define KRED  "\x1B[31m"
# define KGRN  "\x1B[32m"
# define KYEL  "\x1B[33m"
# define KBLU  "\x1B[34m"
# define KMAG  "\x1B[35m"
# define KCYN  "\x1B[36m"
# define KWHT  "\x1B[37m"
# define BWHT  "\x1B[47m"

# define TOO_FEW_CLA 1
# define TOO_MANY_CLA 2
# define INVALID_PID 3
# define INVALID_MSG 4
# define SIGNAL_ERR 5
# define MALLOC_FAIL 6

int		throw_error(int error_code);
void	throw_warning(int error_code);

#endif