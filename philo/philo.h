/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 15:23:05 by marvin            #+#    #+#             */
/*   Updated: 2024/11/29 22:22:57 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# ifndef PHILOMAX
#  define PHILOMAX 500
# endif

# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <stdio.h>
# include <pthread.h>

typedef struct s_program	t_program;

typedef struct s_philo
{
	pthread_t		thread;
	time_t			start_time;
	time_t			last_eat_time;
	int				id;
	int				count_eaten;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	lock_meal_count;
	t_program		*program;
}	t_philo;

typedef struct s_program
{
	int				dead;
	int				num_of_philo;
	time_t			time_to_die;
	time_t			time_to_eat;
	time_t			time_to_sleep;
	int				num_of_times_to_eat;
	pthread_t		*forks;
	pthread_mutex_t	lock_dead;
	pthread_mutex_t	lock_meal;
	pthread_mutex_t	lock_write;
	t_philo			*philo;
}	t_program;

int		ft_atoi(const char *str);
void	program_init(pthread_mutex_t *forks, t_program *program, \
t_philo *philo, int total_philos);
int		eating(t_philo *philo);
size_t	sleeping(t_philo *philo);
int		thinking(t_philo *philo);
void	args_input(t_program *program, char **av);
time_t	current_time_of_day(void);
void	thread_init(t_philo *philo, t_program *prog);
void	philo_init(t_program *prog, t_philo *philo_arr, \
char **av, pthread_mutex_t *forks);
void	*action(void *args);
int		check_if_died(t_program *program);
void	*monitor(void *args);
int		flag_death_check(t_philo *philo);
int		validate_digits(char **argv);
void	print_message(t_philo *philo, const char *message);
void	destroy_all(t_program *program, pthread_mutex_t *forks);
int		pick_up_fork(t_philo *philo);

#endif