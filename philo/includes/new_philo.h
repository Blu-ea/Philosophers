/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_philo.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguez <amiguez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 12:53:13 by amiguez           #+#    #+#             */
/*   Updated: 2022/09/07 17:32:18 by amiguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NEW_PHILO_H
# define NEW_PHILO_H

# include <sys/time.h>
# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>

# define __NO_ARG 1
# define __WRONG_ARG 2
# define __MALLOC_FORK 3
# define __FORK 4
# define __CHECK1 5
# define __CHECK2 6
# define __CHECK3 7
# define __CHECK4 8
# define __MALLOC_PHILO 9
# define __PTHREAD 10

# define ALIVE 1
# define DEAD 0

typedef struct s_ph	t_ph;

typedef struct s_lst_ph
{
	int				id;
	int				fork_l;
	int				fork_r;
	t_ph			*data;
	int				state;
	int				eat;
	struct timeval	last_eat;
	pthread_t		thread;
}	t_lst_ph;

typedef struct s_ph
{
	int				nb_philo;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				nb_eat;
	t_lst_ph		*philo;
	pthread_mutex_t	*fork;
	struct timeval	start;
	pthread_mutex_t	state_check;
	pthread_mutex_t	eat_check;
	pthread_mutex_t	last_eat_check;
	pthread_mutex_t	print;
	int				i;
}		t_ph;

/***************************/
/**          MAIN         **/
/***************************/

//int	main(int argc, char **argv);
int		launch(t_ph *data);

/***************************/
/**         PARSING       **/
/***************************/

int		parsing(char **argv);
int		ft_is_digit(char *arg);
int		ft_atoi(char *arg);

/***************************/
/**          INIT         **/
/***************************/

int		init(int argc, char **argv, t_ph *data);
int		init_data(int argc, char **argv, t_ph *data);
int		init_mutex(t_ph *data);
int		init_philo(t_ph *data);

/***************************/
/**         ROUTINE       **/
/***************************/

void	*routine(void*);

/***************************/
/**          ERROR        **/
/***************************/

int		ft_error(int id, t_ph *data);
void	error_data(t_ph *data, int i, int id);
void	error_mutex(t_ph *data, int id);
void	error_malloc_philo(t_ph *data, int id);
void	error_pthread(t_ph *data, int id);

/** debug **/
void	print_t_ph(t_ph data);

#endif 