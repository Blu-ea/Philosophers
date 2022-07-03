/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguez <amiguez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 12:53:13 by amiguez           #+#    #+#             */
/*   Updated: 2022/07/03 06:03:54 by amiguez          ###   ########.fr       */
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

# define WRONG_ARGS 1
# define WRONG_ARGS_2 2
# define MALLOC_ERROR 3
# define MALLOC_ERROR_2 4
# define ERROR_PRINT 5
# define MUTEX_ERROR 6
# define THREAD_ERROR 7

typedef struct s_ph	t_ph;

typedef struct s_lst_ph
{
	int				id;
	int				fork_left;
	int				fork_right;
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
	pthread_mutex_t	*mutex;
	pthread_mutex_t	print;
}		t_ph;

//==================//
//      main.c      //

// int		main(int argc, char **argv);
int			ft_init(t_ph *data);
int			ft_create_philo(t_ph *data);
void		kill_all(t_ph *data);
int			ft_exit(t_ph *data);

//      pars.c      //

int			ft_pars(int argc, char **argv, t_ph *data);
int			ft_check_values(char **argv);

//      error.c      //

int			ft_error(int i, t_ph *data);
int			ft_error_mutex(int i, t_ph *data);
int			ft_error_thread(int i, t_ph *data);

//      time.c      //

int			check_dead(t_ph *data);
void		calc_last_eat(t_ph *data, int i);
u_int64_t	get_time(t_ph *data);
void		ft_usleep(u_int64_t time);

//     thread.c      //

void		*ft_thread(void *arg);
void		ft_eat(t_lst_ph *ph, t_ph *data);
void		ft_sleep(t_lst_ph *ph, t_ph *data);
void		print_act(t_ph *data, int i, char *str, int pass);

#endif