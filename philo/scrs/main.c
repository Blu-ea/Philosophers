/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguez <amiguez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 19:01:50 by amiguez           #+#    #+#             */
/*   Updated: 2022/05/25 18:29:17 by amiguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int argc, char **argv)
{
	t_philo		data;

	ft_pars(argc, argv, &data);
}

void	ft_error(char *str)
{
	ft_printf("%s\n", str);
	exit(1);
}
