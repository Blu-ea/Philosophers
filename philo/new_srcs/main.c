/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amiguez <amiguez@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 14:39:56 by amiguez           #+#    #+#             */
/*   Updated: 2022/09/06 19:51:54 by amiguez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/new_philo.h"

int	main(int argc, char **argv)
{
	t_ph	data;

	if (argc != 5 && argc != 6)
		return (ft_error(__NO_ARG, &data));
	if (parsing(argv) == EXIT_FAILURE)
		return (ft_error(__WRONG_ARG, &data));
	if (init(argc, argv, &data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	launch(&data);
	return (0);
}

void	launch(t_ph *data)
{
}
