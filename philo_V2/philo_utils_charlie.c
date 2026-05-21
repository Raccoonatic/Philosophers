/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils_charlie.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-san- <lde-san-@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 16:23:07 by lde-san-          #+#    #+#             */
/*   Updated: 2026/05/21 13:03:41 by lde-san-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int		ph_philo_alloc(t_table *sim, t_philo **ph, int guide);
int		ph_sim_end(t_table *sim, pthread_t **thr, int thr_n, int exit_cd);
void	ph_action_report(t_philo *p, char *action);
void	ph_thinkering(t_philo *philo, bool print_action);
void	ph_meditate(t_philo *philo);

int	ph_philo_alloc(t_table *sim, t_philo **ph, int guide)
{
	*ph = ph_calloc(1, sizeof(t_philo));
	if (!(*ph))
	{
		*ph = NULL;
		return (1);
	}
	if (ph_safe_mtx_init(ph, &(*ph)->meal_lock))
		return (1);
	if (ph_safe_mtx_init(ph, &(*ph)->thrive_lock))
		return (pthread_mutex_destroy(&(*ph)->thrive_lock), 1);
	(*ph)->thriving = true;
	(*ph)->id = guide + 1;
	(*ph)->meal_count = 0;
	(*ph)->last_meal = 0;
	(*ph)->ordr = EVN;
	if ((*ph)->id % 2)
		(*ph)->ordr = ODD;
	(*ph)->table = sim;
	(*ph)->left_fork = &(sim->forks[(guide + 1) % sim->n]);
	(*ph)->right_fork = &(sim->forks[guide]);
	return (0);
}

int	ph_sim_end(t_table *sim, pthread_t **thr, int thr_n, int exit_cd)
{
	int	guide;

	if (thr_n != -1)
	{
		sim->omg_she_ded = true;
		pthread_mutex_unlock(&sim->ded);
	}
	if (sim->n == thr_n)
	{
		free(*thr);
		return (exit_cd);
	}
	guide = thr_n + 1;
	while (guide <= sim->n)
	{
		pthread_join((*thr)[guide], NULL);
		guide++;
	}
	free(*thr);
	return (exit_cd);
}

void	ph_action_report(t_philo *p, char *action)
{
	long long	now;

	now = ph_getnow();
	pthread_mutex_lock(&p->table->print);
	pthread_mutex_lock(&p->table->ded);
	if (p->table->omg_she_ded == false)
		printf("%lld %d %s\n", now - p->table->start, p->id, action);
	pthread_mutex_unlock(&p->table->ded);
	pthread_mutex_unlock(&p->table->print);
	return ;
}

void	ph_meditate(t_philo *philo)
{
	if (philo->table->n % 2 == 0 || philo->table->n == 1)
	{
		if (philo->ordr == EVN)
			ph_usleep(30);
	}
	else
	{
		if (philo->ordr == ODD)
			ph_thinkering(philo, false);
	}
	return ;
}

void	ph_thinkering(t_philo *philo, bool print_action)
{
	long long	tt_think;

	if (print_action)
		ph_action_report(philo, "is thinking");
	if (philo->table->n % 2 == 0)
		return ;
	tt_think = philo->table->tte * 2 - philo->table->tts;
	if (tt_think < 0)
		tt_think = 0;
	ph_usleep(tt_think / 2);
	return ;
}
