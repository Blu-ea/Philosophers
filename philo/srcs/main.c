/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguez <amiguez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 19:01:50 by amiguez           #+#    #+#             */
/*   Updated: 2022/05/28 07:42:16 by amiguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int argc, char **argv)
{
	t_philo		data;

	gettimeofday(&data.start, NULL);
	ft_pars(argc, argv, &data);
	ft_printf_data(data);

	data.lst_philo = malloc(sizeof(t_lst_ph) * 1);
	data.lst_philo->data = &data;
	while (1)
	{
		printf("time = %llu\n", ft_get_time(data.lst_philo[0]));
		sleep(1);
	}
}

void	ft_error(char *str)
{
	ft_printf("%s\n", str);
	exit(1);
}


void	ft_philo(t_philo data)
{
	
}