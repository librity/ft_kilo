/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kilo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 16:50:03 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/02/06 16:57:04 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/kilo.h"

int	main(void)
{
	tty_enable_raw_mode();
	initialize_editor();
	while (1)
	{
		editor_refresh_screen();
		editor_process_keypresses();
	}
	return (0);
}
