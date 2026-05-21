/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils_bravo.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-san- <lde-san-@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 23:31:02 by lde-san-          #+#    #+#             */
/*   Updated: 2026/05/21 00:12:45 by lde-san-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static char	*ph_msg_bank(int msg_cd);
size_t		ph_strlen(const char *str);
int			ph_printerr(int err_cd, int exit_cd);
void		*ph_calloc(size_t nmemb, size_t size);
int			ph_clean(t_table *sim, t_philo ***philos, int err_cd, int exit_cd);

size_t	ph_strlen(const char *str)
{
	size_t	guide;

	guide = 0;
	while (str[guide])
		guide++;
	return (guide);
}

int	ph_printerr(int err_cd, int exit_cd)
{
	char	*u;

	u = MINT"Usage:"BABY" ./philo "LIME"n_philo ttd tte tts"GD" [meals]\n"RSET;
	if (exit_cd == 1)
		write(2, ph_msg_bank(err_cd), ph_strlen(ph_msg_bank(err_cd)));
	if (err_cd == 1)
		write(2, u, ph_strlen(u));
	return (exit_cd);
}

static char	*ph_msg_bank(int msg_cd)
{
	if (msg_cd == 1)
		return (BLOD"Sim Failed"RSET": "NEOR"Incorrect Argument Count\n"RSET);
	if (msg_cd == 2)
		return (BLOD"Sim Failed"RSET": "NEOR"Invalid Arg "PINK"n_philo\n"RSET);
	if (msg_cd == 3)
		return (BLOD"Sim Failed"RSET": "NEOR"Invalid Arg "PINK"ttd\n"RSET);
	if (msg_cd == 4)
		return (BLOD"Sim Failed"RSET": "NEOR"Invalid Arg "PINK"tte\n"RSET);
	if (msg_cd == 5)
		return (BLOD"Sim Failed"RSET": "NEOR"Invalid Arg "PINK"tts\n"RSET);
	if (msg_cd == 6)
		return (BLOD"Sim Failed"RSET": "NEOR"Invalid Arg "PINK"[meals]\n"RSET);
	if (msg_cd == 7)
		return (BLOD"Sim Failed"RSET": "PURP"mutex_init "ORNG"Failed\n"RSET);
	if (msg_cd == 8)
		return (BLOD"Sim Failed"RSET": "PURP"malloc "ORNG"Failed\n"RSET);
	if (msg_cd == 9)
		return (BLOD"Sim Failed"RSET": "PURP"philo_alloc "ORNG"Failed\n"RSET);
	if (msg_cd == 10)
		return (BLOD"Sim Failed"RSET": "PURP"thread_create "ORNG"Failed\n"RSET);
	return (BLOD"Sim Failed"RSET": "NEOR"Unexpected Error\n"RSET);
}

void	*ph_calloc(size_t nmemb, size_t size)
{
	void	*allocated;
	size_t	mem_total_size;

	if (nmemb != 0 && size > (SIZE_MAX / nmemb))
		return (NULL);
	mem_total_size = nmemb * size;
	allocated = malloc(mem_total_size);
	if (!allocated)
		return (NULL);
	memset(allocated, '\0', mem_total_size);
	return (allocated);
}
/*It allocates a number of nmemb spaces of size "size" in memory as long as
the system architecture has enough space for it. Then it initializes the memory
area by filling it with null characters "\0". */

int	ph_clean(t_table *sim, t_philo ***philos, int err_cd, int exit_cd)
{
	int	guide;

	pthread_mutex_destroy(&sim->ded);
	pthread_mutex_destroy(&sim->print);
	guide = 0;
	while (guide < sim->n)
		pthread_mutex_destroy(&sim->forks[guide++]);
	free(sim->forks);
	if (philos)
	{
		guide = 0;
		while (guide < sim->n)
		{
			if ((*philos)[guide])
			{
				pthread_mutex_destroy(&(*philos)[guide]->meal_lock);
				pthread_mutex_destroy(&(*philos)[guide]->thrive_lock);
				free((*philos)[guide]);
			}
			guide++;
		}
		free(*philos);
	}
	return (ph_printerr(err_cd, exit_cd));
}
