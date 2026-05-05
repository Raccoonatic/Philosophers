/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_simulation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-san- <lde-san-@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 17:34:51 by lde-san-          #+#    #+#             */
/*   Updated: 2026/05/05 21:06:07 by lde-san-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*ph_routine(void *arg);
static void	*ph_monitor(void *arg);
static void	ph_philoop(t_table *t, t_philo **ph, int *full);
int			ph_run_simulation(t_table *sim, t_philo ***ph);

int	ph_run_simulation(t_table *sim, t_philo ***ph)
{
	pthread_t		*thr;
	int				thr_n;

	thr_n = sim->n + 1;
	thr = ph_calloc(thr_n, sizeof(pthread_t));
	if (!thr)
		return (ph_clean(sim, ph, 8, 1));
	pthread_mutex_lock(&sim->ded);
	while (thr_n > 0)
	{
		thr_n--;
		if (thr_n == sim->n)
		{
			if (pthread_create(&thr[thr_n], NULL, &ph_monitor, sim))
				return (ph_clean(sim, ph, 10, ph_sim_end(sim, &thr, thr_n, 1)));
		}
		else if (pthread_create(&thr[thr_n], NULL, &ph_routine, (*ph)[thr_n]))
			return (ph_clean(sim, ph, 10, ph_sim_end(sim, &thr, thr_n, 1)));
	}
	sim->start = ph_getnow();
	ph_lastmealinit(sim, *ph);
	pthread_mutex_unlock(&sim->ded);
	return (ph_clean(sim, ph, 42, ph_sim_end(sim, &thr, -1, 0)));
}

static void	*ph_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	pthread_mutex_lock(&philo->table->ded);
	pthread_mutex_unlock(&philo->table->ded);
	if (ph_dedcheck(philo))
		return (NULL);
	pthread_mutex_lock(&philo->table->ded);
	while (philo->table->omg_she_ded == false)
	{
		pthread_mutex_unlock(&philo->table->ded);
		if (philo->ordr == EVN)
		{
			if (ph_pickup_l_r(philo))
				break ;
		}
		else
			if (ph_pickup_r_l(philo))
				break ;
		pthread_mutex_lock(&philo->table->ded);
	}
	pthread_mutex_unlock(&philo->table->ded);
	return (NULL);
}

static void	*ph_monitor(void *arg)
{
	t_table	*table;
	int		full;

	table = (t_table *)arg;
	pthread_mutex_lock(&table->ded);
	if (table->omg_she_ded == true)
		return (pthread_mutex_unlock(&table->ded), NULL);
	full = 0;
	while (table->omg_she_ded == false && full != table->n)
	{
		pthread_mutex_unlock(&table->ded);
		ph_philoop(table, table->philos, &full);
		pthread_mutex_lock(&table->ded);
	}
	if (full == table->n)
		table->omg_she_ded = true;
	pthread_mutex_unlock(&table->ded);
	return (NULL);
}

static void	ph_philoop(t_table *t, t_philo **ph, int *full)
{
	int	i;

	i = 0;
	*full = 0;
	while (ph[i])
	{
		pthread_mutex_lock(&ph[i]->meal_lock);
		if (t->turns != -1 && ph[i]->meal_count >= t->turns)
			(*full)++;
		if (ph_getnow() - ph[i]->last_meal > t->ttd)
		{
			pthread_mutex_unlock(&ph[i]->meal_lock);
			pthread_mutex_lock(&t->print);
			pthread_mutex_lock(&t->ded);
			t->omg_she_ded = true;
			printf("%lld %d %s\n", ph_getnow() - t->start, ph[i]->id, "died");
			pthread_mutex_unlock(&t->ded);
			pthread_mutex_unlock(&t->print);
			return ;
		}
		pthread_mutex_unlock(&ph[i]->meal_lock);
		i++;
	}
	return ;
}
