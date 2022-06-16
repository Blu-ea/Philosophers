/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguez <amiguez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 12:53:13 by amiguez           #+#    #+#             */
/*   Updated: 2022/06/16 08:35:30 by amiguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "../libft/includes/libft.h"
# include <sys/time.h>
# include <stdio.h>
# include <pthread.h>
# include <semaphore.h>

# define DEAD 0
# define ALIVE 1

# define WRONG_ARGS 1
# define WRONG_ARGS_2 2
# define ERROR_SEM 3
# define ERROR_MALLOC 4
# define ERROR_THREAD 5

# define SEMAFORK "/sem_fork"

typedef struct s_ph	t_ph;

typedef struct s_lst_ph
{
	int				id;
	t_ph			*data;
	int				alive;
	int				eat;
	pthread_t		thread;
	struct timeval	last_eat;
}	t_lst_ph;

typedef struct s_ph
{
	int				nb_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nb_must_eat;
	struct timeval	start;
	struct timeval	current;
	t_lst_ph		*lst_philo;
	sem_t			*sem_fork;
}		t_ph;

//==================//
//      main.c      //

// int		main(int argc, char **argv);
int			ft_launch(t_ph *data);
int			ft_init(t_ph *data);
void		kill_all(t_ph *data);
void		ft_exit(t_ph *data);

//      pars.c      //

int			ft_pars(int argc, char **argv, t_ph *data);
int			ft_check_values(char **argv);

//      error.c      //

int			ft_error(int i, t_ph *data, int place);
void		ft_error_thread(int place, t_ph *data);

//      time.c       //

int			check_dead(t_ph *data);
void		calc_last_eat(t_ph *data, int i);
u_int64_t	get_time(t_ph *data);
void		ft_usleep(u_int64_t time);

//    simulation.c   //

void		*ft_philo(void *arg);
void		ft_eat(t_ph *data, t_lst_ph *ph);
void		ft_sleep(t_ph *data, t_lst_ph *ph);
void		print_act(t_ph *data, int i, char *str, int pass);

#endif