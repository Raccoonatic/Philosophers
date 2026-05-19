/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-san- <lde-san-@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 17:50:03 by lde-san-          #+#    #+#             */
/*   Updated: 2026/05/20 00:24:08 by lde-san-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <limits.h>
# include <stdint.h>
# include <pthread.h>
# include <stdbool.h>
# include <sys/time.h>

# define RSET	"\033[0m"
# define B_WI	"\033[1;37m"
# define LIME	"\033[1;38;2;0;255;0m"
# define BABY	"\033[38;2;0;255;247m"
# define BLOD	"\033[1;38;2;255;0;0m"
# define ORNG	"\033[38;2;255;153;51m"
# define PINK	"\033[1;38;2;255;0;251m"
# define PURP	"\033[1;38;2;174;5;252m"
# define GD		"\033[1;38;2;235;232;52m"
# define MINT	"\033[1;38;2;55;250;133m"
# define NEOR	"\033[3m\033[38;2;255;153;51m"

typedef enum e_odeven
{
	ODD,
	EVN
}	t_odeven;

typedef struct s_philo	t_philo;

typedef struct s_table
{
	int				n;
	int				turns;
	long long		ttd;
	long long		tte;
	long long		tts;
	long long		start;
	bool			omg_she_ded;
	pthread_mutex_t	ded;
	pthread_mutex_t	print;
	pthread_mutex_t	*forks;
	t_philo			**philos;
}	t_table;

struct s_philo
{
	int				id;
	long			meal_count;
	long long		last_meal;
	pthread_mutex_t	meal_lock;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	t_odeven		ordr;
	t_table			*table;
};

//   -- -- #    ph_simulation.c
int			ph_run_simulation(t_table *sim, t_philo ***ph);

//   -- -- #    philo_simulation_utils.c
int			ph_pickup_r_l(t_philo *philo);
int			ph_pickup_l_r(t_philo *philo);
int			ph_dedcheck(t_philo *philo);
void		ph_lastmealinit(t_table *sim, t_philo **ph);

//   -- -- #    philo_utils_alpha.c
long long	ph_getnow(void);
void		ph_usleep(long sleep);
int			ph_atoll(const char *str, long long *storage);

//   -- -- #    philo_utils_beta.c
size_t		ph_strlen(const char *str);
int			ph_printerr(int err_cd, int exit_cd);
void		*ph_calloc(size_t nmemb, size_t size);
int			ph_clean(t_table *sim, t_philo ***philos, int err_cd, int exit_cd);

//   -- -- #    philo_utils_charlie.c
int			ph_philo_alloc(t_table *sim, t_philo **ph, int guide);
int			ph_sim_end(t_table *sim, pthread_t **thr, int thr_n, int exit_cd);
void		ph_action_report(t_philo *p, char *action);
void		ph_thinkering(t_philo *philo, bool print_action);
void        ph_meditate(t_philo *philo);
#endif
