/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-san- <lde-san-@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 23:26:26 by lde-san-          #+#    #+#             */
/*   Updated: 2026/05/05 21:04:43 by lde-san-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ph_philoinit(t_table *sim, t_philo ***philos);
static int	ph_tableinit(t_table *sim, char *wordy[]);
static int	ph_forkinit(t_table *sim);

int	main(int arc, char *wordy[])
{
	t_table	sim;
	t_philo	**philos;

	if (arc < 5 || arc > 6)
		return (ph_printerr(1, 1));
	if (ph_tableinit(&sim, wordy))
		return (1);
	if (ph_philoinit(&sim, &philos))
		return (1);
	sim.philos = philos;
	return (ph_run_simulation(&sim, &philos));
}

static int	ph_philoinit(t_table *sim, t_philo ***philos)
{
	int	guide;

	*philos = ph_calloc(sim->n + 1, sizeof(t_philo *));
	if (!(*philos))
		return (ph_clean(sim, NULL, 8, 1));
	guide = 0;
	while (guide < sim->n)
		(*philos)[guide++] = NULL;
	while (guide > 0)
	{
		--guide;
		if (ph_philo_alloc(sim, &(*philos)[guide], guide))
			return (ph_clean(sim, philos, 9, 1));
	}
	return (0);
}

static int	ph_tableinit(t_table *sim, char *wordy[])
{
	long long	storage;

	if (ph_atoll(wordy[1], &storage))
		return (ph_printerr(2, 1));
	sim->n = (int)storage;
	if (ph_atoll(wordy[2], &sim->ttd))
		return (ph_printerr(3, 1));
	if (ph_atoll(wordy[3], &sim->tte))
		return (ph_printerr(4, 1));
	if (ph_atoll(wordy[4], &sim->tts))
		return (ph_printerr(5, 1));
	if (!wordy[5])
		storage = -1;
	else if (ph_atoll(wordy[5], &storage))
		return (ph_printerr(6, 1));
	sim->turns = (int)storage;
	sim->philos = NULL;
	sim->omg_she_ded = false;
	if (pthread_mutex_init(&sim->ded, NULL))
		return (ph_printerr(7, 1));
	if (pthread_mutex_init(&sim->print, NULL))
		return (pthread_mutex_destroy(&sim->ded), ph_printerr(7, 1));
	return (ph_forkinit(sim));
}

static int	ph_forkinit(t_table *sim)
{
	int	guide;

	guide = 0;
	sim->forks = ph_calloc(sim->n, sizeof(pthread_mutex_t));
	if (!sim->forks)
	{
		pthread_mutex_destroy(&sim->ded);
		pthread_mutex_destroy(&sim->print);
		return (ph_printerr(8, 1));
	}
	while (guide < sim->n)
	{
		if (pthread_mutex_init(&sim->forks[guide], NULL))
		{
			pthread_mutex_destroy(&sim->ded);
			pthread_mutex_destroy(&sim->print);
			while (guide > 0)
				pthread_mutex_destroy(&sim->forks[--guide]);
			free(sim->forks);
			return (ph_printerr(7, 1));
		}
		guide++;
	}
	return (0);
}
