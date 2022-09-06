/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_philo.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguez <amiguez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 12:53:13 by amiguez           #+#    #+#             */
/*   Updated: 2022/09/06 16:53:10 by amiguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <sys/time.h>
# include <stdio.h>
# include <pthread.h>

# define DEAD 0
# define ALIVE 1

# define __PASS 0
# define __NO_ARG 1
# define __WRONG_ARG 2
# define __PC_ERROR 3
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
}		t_ph;

int main()