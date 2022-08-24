/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   die.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 04:41:31 by flcarval          #+#    #+#             */
/*   Updated: 2022/08/17 16:42:40 by flcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

static void	die_loop(t_philo *philo);

void	*die(void *philo)
{
	die_loop((t_philo *)philo);
	pthread_mutex_lock(&((t_philo *)philo)->m_philo);
	pthread_mutex_lock(&((t_philo *)philo)->data->m_data);
	if (((t_philo *)philo)->lunches >= ((t_philo *)philo)->data->args.lunches \
		&& ((t_philo *)philo)->data->args.lunches)
	{
		pthread_mutex_unlock(&((t_philo *)philo)->m_philo);
		pthread_mutex_unlock(&((t_philo *)philo)->data->m_data);
		return (NULL);
	}
	pthread_mutex_unlock(&((t_philo *)philo)->m_philo);
	pthread_mutex_unlock(&((t_philo *)philo)->data->m_data);
	pthread_mutex_lock(&((t_philo *)philo)->data->m_dead);
	if (!((t_philo *)philo)->data->dead)
	{
		pthread_mutex_unlock(&((t_philo *)philo)->data->m_dead);
		log_man(L_DIE, ((t_philo *)philo)->id, ((t_philo *)philo)->data);
		exit(EXIT_SUCCESS);
	}
	else
		pthread_mutex_unlock(&((t_philo *)philo)->data->m_dead);
	return (NULL);
}

static void	die_loop(t_philo *philo)
{
	t_msts	ts;
	t_msts	dif;

	ts = get_timestamp_ms();
	dif = get_timestamp_ms() - ts;
	while (dif < philo->data->args.tt_die)
	{
		pthread_mutex_lock(&philo->m_prev_lunch);
		if (philo->prev_lunch)
			ts = philo->prev_lunch;
		pthread_mutex_unlock(&philo->m_prev_lunch);
		dif = get_timestamp_ms() - ts;
	}
}
