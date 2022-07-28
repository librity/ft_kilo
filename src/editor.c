/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 01:25:28 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/07/28 13:06:08 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/kilo.h"

void	initialize_editor(void)
{
	char	has_error;

	has_error = set_window_size(&c()->tty_rows, &c()->tty_columns);
	if (has_error == -1)
		die("`set_window_size` couldn't get terminal information from `ioctl`");
}

char	editor_read_key(void)
{
	char	input;
	char	has_error;

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
	char	current_key;

	current_key = editor_read_key();
	if (current_key == CONTROL_Q)
	{
		clear_tty();
		exit(0);
		return ;
	}
}
