/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguez <amiguez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 12:53:13 by amiguez           #+#    #+#             */
/*   Updated: 2022/05/28 07:48:59 by amiguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "../libft/libft.h"
# include <sys/time.h>
# include <stdio.h>

typedef struct s_philo	t_philo;

typedef struct s_lst_ph
{
	int	id;
	t_philo *data;
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
	u_int64_t		time;
}		t_philo;

//////////// main.c ////////////

//int		main(int argc, char **argv);
void		ft_error(char *str);

//////////// pars.c ////////////

void		ft_pars(int argc, char **argv, t_philo *data);
void		ft_check_values(t_philo data);

////// philo_generator.c ////////

void	ft_generate_philo(t_philo *data);

//////////// debug.c ////////////

void		ft_printf_data(t_philo data);

//////////// time.c /////////////

u_int64_t	ft_get_time(t_lst_ph *ph);

#endif