/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: pmolnar <pmolnar@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/14 16:23:55 by pmolnar       #+#    #+#                 */
/*   Updated: 2022/03/14 17:15:59 by pmolnar       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

static int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

static int	ft_isspace(int c)
{
	return (c == ' '
		|| c == '\t'
		|| c == '\n'
		|| c == '\v'
		|| c == '\f'
		|| c == '\r');
}

int	ft_atoi(const char *str)
{
	int			num;
	int			sign;
	const int	coeff[2] = {+1, -1};

	num = 0;
	sign = 1;
	while (*str && ft_isspace(*str))
		str++;
	if (*str && (*str == '+' || *str == '-'))
		sign = coeff[(*str++ == '-')];
	while (*str && ft_isdigit(*str))
		num = 10 * num + (*str++ - '0');
	return (sign * num);
}