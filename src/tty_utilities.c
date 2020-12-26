/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tty_utilities.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 01:25:42 by lpaulo-m          #+#    #+#             */
/*   Updated: 2020/12/26 14:45:33 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/kilo.h"

void	wipe_screen(void)
{
	write(STDOUT_FILENO, "\x1b[2J", 4);
}

void	reset_cursor(void)
{
	write(STDOUT_FILENO, "\x1b[1;1H", 6);
}

void	clear_tty(void)
{
	wipe_screen();
	reset_cursor();
}
