/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_simulation_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-san- <lde-san-@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 20:58:05 by lde-san-          #+#    #+#             */
/*   Updated: 2026/05/20 00:24:11 by lde-san-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int			ph_dedcheck(t_philo *philo);
int			ph_pickup_r_l(t_philo *philo);
int			ph_pickup_l_r(t_philo *philo);
static void	ph_update_meal_data(t_philo *philo);
void		ph_lastmealinit(t_table *sim, t_philo **ph);

int	ph_pickup_l_r(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	ph_action_report(philo, "has taken a fork");
	if (philo->table->n == 1)
	{
		ph_usleep(philo->table->ttd + 5);
		pthread_mutex_unlock(philo->left_fork);
		return (pthread_mutex_lock(&philo->table->ded), 1);
	}
	pthread_mutex_lock(philo->right_fork);
	ph_action_report(philo, "has taken a fork");
	pthread_mutex_lock(&philo->table->ded);
	if (philo->table->omg_she_ded == true)
	{
		pthread_mutex_unlock(philo->left_fork);
		return (pthread_mutex_unlock(philo->right_fork), 1);
	}
	pthread_mutex_unlock(&philo->table->ded);
	ph_update_meal_data(philo);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	ph_action_report(philo, "is sleeping");
	ph_usleep(philo->table->tts);
	ph_thinkering(philo, true);
	return (0);
}

int	ph_pickup_r_l(t_philo *philo)
{
	pthread_mutex_lock(philo->right_fork);
	ph_action_report(philo, "has taken a fork");
	pthread_mutex_lock(philo->left_fork);
	ph_action_report(philo, "has taken a fork");
	pthread_mutex_lock(&philo->table->ded);
	if (philo->table->omg_she_ded == true)
	{
		pthread_mutex_unlock(philo->right_fork);
		return (pthread_mutex_unlock(philo->left_fork), 1);
	}
	pthread_mutex_unlock(&philo->table->ded);
	ph_update_meal_data(philo);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
	ph_action_report(philo, "is sleeping");
	ph_usleep(philo->table->tts);
	ph_thinkering(philo, true);
	return (0);
}

static void	ph_update_meal_data(t_philo *philo)
{
	pthread_mutex_lock(&philo->meal_lock);
	philo->last_meal = ph_getnow();
	(philo->meal_count)++;
	ph_action_report(philo, "is eating");
	pthread_mutex_unlock(&philo->meal_lock);
	ph_usleep(philo->table->tte);
	return ;
}

int	ph_dedcheck(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->ded);
	if (philo->table->omg_she_ded == true)
	{
		pthread_mutex_unlock(&philo->table->ded);
		return (1);
	}
	pthread_mutex_unlock(&philo->table->ded);
	ph_meditate(philo);
//	if (philo->ordr == EVN)
//		ph_usleep(philo->table->tte / 2);
	return (0);
}

void	ph_lastmealinit(t_table *sim, t_philo **ph)
{
	int	guide;

	guide = 0;
	while (guide < sim->n)
	{
		ph[guide]->last_meal = sim->start;
		guide++;
//		printf("%lld %d is thinking\n", ph_getnow() - sim->start, guide);
	}
	return ;
}
