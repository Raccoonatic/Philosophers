/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils_delta.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-san- <lde-san-@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 21:18:59 by lde-san-          #+#    #+#             */
/*   Updated: 2026/05/21 00:01:35 by lde-san-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int		ph_chilltime(t_philo *philo);
void	ph_be_serious_someone_died(t_philo **ph);
int		ph_safe_mtx_init(t_philo **ph, pthread_mutex_t *lock);


int	ph_chilltime(t_philo *philo)
{
	pthread_mutex_lock(&philo->thrive_lock);
	if (philo->thriving == false)
		return (1);
	pthread_mutex_unlock(&philo->thrive_lock);
	ph_action_report(philo, "is sleeping");
	ph_usleep(philo->table->tts);
	pthread_mutex_lock(&philo->thrive_lock);
	if (philo->thriving == false)
		return (1);
	pthread_mutex_unlock(&philo->thrive_lock);
	ph_thinkering(philo, true);
	return (0);
}

void	ph_be_serious_someone_died(t_philo **ph)
{
	int	guide;

	guide = 0;
	while (ph[guide])
	{
		pthread_mutex_lock(&ph[guide]->thrive_lock);
		ph[guide]->thriving = false;
		pthread_mutex_unlock(&ph[guide]->thrive_lock);
		guide++;
	}
	return ;
}

int	ph_safe_mtx_init(t_philo **ph, pthread_mutex_t *lock)
{
	if (pthread_mutex_init(lock, NULL))
	{
		free(*ph);
		*ph = NULL;
		return (1);
	}
	return (0);
}
