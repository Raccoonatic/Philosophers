/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils_delta.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-san- <lde-san-@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 21:18:59 by lde-san-          #+#    #+#             */
/*   Updated: 2026/05/20 21:32:15 by lde-san-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ph_chilltime(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->ded);
	if (philo->table->omg_she_ded == true)
		return (pthread_mutex_unlock(philo->right_fork), 1);
	pthread_mutex_unlock(&philo->table->ded);
	ph_action_report(philo, "is sleeping");
	ph_usleep(philo->table->tts);
	pthread_mutex_lock(&philo->table->ded);
	if (philo->table->omg_she_ded == true)
		return (pthread_mutex_unlock(philo->right_fork), 1);
	pthread_mutex_unlock(&philo->table->ded);
	ph_thinkering(philo, true);
	return (0);
}
