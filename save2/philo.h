/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguez <amiguez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 12:53:13 by amiguez           #+#    #+#             */
/*   Updated: 2022/06/01 16:05:30 by amiguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "../libft/includes/libft.h"
# include <sys/time.h>
# include <stdio.h>
# include <pthread.h>

# define DEAD 0
# define ALIVE 1
# define THINKING 2
# define EATING 3
# define SLEEPING 4

# define WRONG_ARGS 1
# define MALLOC_ERROR 2
# define MALLOC_ERROR_2 3
# define THREAD_ERROR 4
# define MUTEX_ERROR 5
# define MUTEX_ERROR_2 6

typedef struct s_philo	t_philo;

typedef struct s_lst_ph
{
	int				id;
	int				fork_left;
	int				fork_right;
	t_philo			*data;
	pthread_t		thread;
	int				state;
	int				alive;
	int				eat;
	struct timeval	last_eat;
}	t_lst_ph;

typedef struct s_philo
{
	int				nb_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nb_must_eat;
	struct timeval	start;
	struct timeval	current;
	t_lst_ph		*lst_philo;
	pthread_mutex_t	*mutex;
	u_int64_t		time;
}		t_philo;

//////////// main.c ////////////

// int		main(int argc, char **argv);
int			ft_init_philo(t_philo *data);
int			ft_init_threads(t_philo *data);
void		ft_leave(t_philo *data);
void		ft_kill_all(t_philo *data);

//////////// pars.c ////////////

int			ft_pars(int argc, char **argv, t_philo *data);
int			ft_check_values(t_philo data, char **argv);
int			ft_is_all_digit(char *arg);

///////// simulation.c //////////

void		*ft_simul(void *philo);
void		ft_eat(t_lst_ph *philo, t_philo *data);
void		ft_sleep(t_lst_ph *philo, t_philo *data);
void		ft_print_act(t_philo *data, t_lst_ph *ph, char *str);
int			check_dead(t_philo *data);
int			ft_test_dead(t_philo *data);

//////// error_handler.c ////////

int			ft_error(int err, t_philo *data, int place);
void		ft_error_mutex(t_philo *data, int place);
void		ft_error_thread(t_philo *data, int place);

//////////// time.c ////////////

u_int32_t	ft_get_time(t_philo data);
void		ft_usleep(useconds_t time);
void		calc_last_eat(t_lst_ph *ph, t_philo *data);

void		ft_printf_data(t_philo data);

#endif