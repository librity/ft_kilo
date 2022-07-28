/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tty_config.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 23:00:03 by lpaulo-m          #+#    #+#             */
/*   Updated: 2022/07/28 13:06:41 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/kilo.h"

void	tty_disable_raw_mode(void)
{
	char	has_error;

	has_error = tcsetattr(
			STDIN_FILENO,
			TCSAFLUSH,
			&c()->original_tty_flags
			);
	if (has_error == -1)
		die("`tcsetattr` couldn't restore original tty attributes");
}

void	tty_enable_raw_mode(void)
{
	struct termios	raw_tty_flags;
	char			has_error;

	has_error = tcgetattr(STDIN_FILENO, &c()->original_tty_flags);
	if (has_error == -1)
		die("`tcgetattr` couldn't fetch original tty attributes");
	atexit(tty_disable_raw_mode);
	raw_tty_flags = c()->original_tty_flags;
	raw_tty_flags.c_iflag &= ~(BRKINT | ICRNL | INPCK | ISTRIP | IXON);
	raw_tty_flags.c_oflag &= ~(OPOST);
	raw_tty_flags.c_cflag |= (CS8);
	raw_tty_flags.c_lflag &= ~(ECHO | ICANON | ISIG | IEXTEN);
	raw_tty_flags.c_cc[VMIN] = 0;
	raw_tty_flags.c_cc[VTIME] = 1;
	has_error = tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw_tty_flags);
	if (has_error == -1)
		die("`tcsetattr` couldn't set raw mode tty attributes");
}

int	set_window_size(int *row_count, int *column_count)
{
	struct winsize	window_size;
	char			has_error;

	has_error = ioctl(STDOUT_FILENO, TIOCGWINSZ, &window_size);
	if (has_error == -1 || window_size.ws_col == 0)
		return (-1);
	*row_count = window_size.ws_row;
	*column_count = window_size.ws_col;
	return (0);
}
