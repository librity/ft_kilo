/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 01:25:42 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/07/28 13:00:22 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/kilo.h"

t_kilo	*c(void)
{
	static t_kilo	__control_instance;

	return (&__control_instance);
}
