/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguez <amiguez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 12:53:13 by amiguez           #+#    #+#             */
/*   Updated: 2022/05/30 09:13:09 by amiguez          ###   ########.fr       */
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

typedef struct s_philo	t_philo;

typedef struct s_lst_ph
{
	int				id;
	int				fork_left;
	int				fork_right;
	t_philo			*data;
	pthread_t		thread;
	int				state;
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

//int		main(int argc, char **argv);
void		ft_init(t_philo *data);
void		ft_check_dead(t_philo *data);

//////////// pars.c ////////////

void		ft_pars(int argc, char **argv, t_philo *data);
void		ft_check_values(t_philo data);

//////////// debug.c ////////////

void		ft_printf_data(t_philo data);

//////////// time.c /////////////

u_int64_t	ft_get_time(t_lst_ph ph);
void		calc_last_eat(t_lst_ph *ph, t_philo *data);

//////////// thread.c ////////////

void		*ft_thread(void *temp);
void		ft_action_print(t_lst_ph *data, int i, char *str);
void		pthread_eat(t_philo *data, t_lst_ph *ph);
void		pthread_sleep(t_philo *data, t_lst_ph *ph);

//////// error_handler.c ////////

void		ft_error(char *str, t_philo *data);
void		ft_error_thread(char *str, t_philo *data, int i);
void		ft_error_mutex(char *str, t_philo *data, int i);

#endif