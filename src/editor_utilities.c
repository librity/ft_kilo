/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_utilities.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 01:25:42 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/02/06 16:48:29 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/kilo.h"

char	control_(char character)
{
	return (character & 0x1f);
}

void	editor_draw_rows(void)
{
	int	current_row;

	current_row = 0;
	while (current_row < g_config.tty_rows)
	{
		write(STDOUT_FILENO, "~\r\n", 3);
		current_row++;
	}
}

void	editor_refresh_screen(void)
{
	clear_tty();
	editor_draw_rows();
	reset_cursor();
}
