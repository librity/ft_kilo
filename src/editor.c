/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 01:25:28 by lpaulo-m          #+#    #+#             */
/*   Updated: 2020/12/26 15:00:44 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/kilo.h"

void	initialize_editor(void)
{
	char has_error;

	has_error = set_window_size(&g_config.tty_rows, &g_config.tty_columns);
	if (has_error == -1)
		die("`set_window_size` couldn't get terminal information from `ioctl`");
}

char	editor_read_key(void)
{
	char input;
	char has_error;

	has_error = read(STDIN_FILENO, &input, 1);
	while (has_error != 1)
	{
		if (has_error == -1 && errno != EAGAIN)
			die("`read` couldn't read next input character");
		has_error = read(STDIN_FILENO, &input, 1);
	}
	return (input);
}

void	editor_process_keypresses(void)
{
	char current_key;

	current_key = editor_read_key();
	switch (current_key)
	{
		case CONTROL_Q:
		clear_tty();
		exit(0);
		break ;
	}
}
