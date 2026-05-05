/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils_alpha.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-san- <lde-san-@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 21:41:48 by lde-san-          #+#    #+#             */
/*   Updated: 2026/05/05 21:09:44 by lde-san-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	ph_getnow(void);
void		ph_usleep(long sleep);
int			ph_atoll(const char *str, long long *storage);
static int	ph_getnum(const char *str, long long *strg, int guide, int sign);
static int	check_limits(char next_digit, int sign, long long *n);

void	ph_usleep(long sleep)
{
	long long	start;
	long long	passed;

	start = ph_getnow();
	while (1)
	{
		passed = ph_getnow() - start;
		if (passed >= sleep)
			break ;
		if (sleep - passed > 1)
			usleep(500);
		else
			continue ;
	}
	return ;
}
/* Improves the presition of the usleep() function by performing tiny 
halts on each iteration and constantly checking if the current time 
minus the time the function was called is smaller than the sleep time.
This creates extra check in points with the system, ensuring that more
of the processing power is used, improving precision. */

long long	ph_getnow(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}
/* Interprets the output of the gettimeofday() function, turning the 
values it returns into a more manageable milisecond format */

int	ph_atoll(const char *str, long long *storage)
{
	size_t		guide;
	int			sign;

	guide = 0;
	sign = 1;
	*storage = 0;
	while (str[guide] == ' ' || (str[guide] >= '\t' && str[guide] <= '\r'))
		guide++;
	if (str[guide] == '-' || str[guide] == '+')
	{
		if (str[guide] == '-')
			sign *= -1;
		guide++;
	}
	return (ph_getnum(str, storage, guide, sign));
}
/* Takes a string of numerical characters and a pointer to a variable
that will store their value as a long long. It ignores any leading 
spaces, and will return 1 if there are any non-numerical characters
after the first sign is reached,  or if the string shows a number 
that's bigger than LLONG_MAX or smaller than LLONG_MIN. Otherwise 
it'll return 0. */

static int	ph_getnum(const char *str, long long *strg, int guide, int sign)
{
	if (str[guide] && str[guide] >= '0' && str[guide] <= '9')
	{
		while (str[guide] && str[guide] >= '0' && str[guide] <= '9')
		{
			if (check_limits(str[guide], sign, strg))
				return (1);
			*strg = (*strg) * 10 + (str[guide] - '0');
			guide++;
		}
		if (str[guide])
			return (1);
		*strg = (*strg) * ((long long)sign);
		if (*strg > 0)
			return (0);
		return (1);
	}
	return (1);
}
/* Iterates through the string passed as a parameter, checking if it
contains non-numerical characters in an unexpected format, and converting
the string to a numerical value, while checking for limits as well. If the
value is fully converted successfully, and the resulting value is bigger
than 0, it'll return 0, otherwise, it'll return 1. In the event the string
is a valid number, it will set the variable pointed at to the resulting value.*/

static int	check_limits(char next_digit, int sign, long long *n)
{
	int	digit;

	digit = next_digit - '0';
	if (sign == 1 && (*n > (LLONG_MAX / 10)
			|| (*n == (LLONG_MAX / 10) && digit > (LLONG_MAX % 10))))
		return (1);
	if (sign == -1 && (*n > (LLONG_MAX / 10)
			|| (*n == (LLONG_MAX / 10) && digit > ((LLONG_MAX % 10) + 1))))
		return (1);
	return (0);
}
/* Checks if by entering the next digit, the result will be a value
bigger (or smaller) than a long long can handle. If it is, it'll 
return 1, otherwise, it'll return 0. If it returns 1. */
