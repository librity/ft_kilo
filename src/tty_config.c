/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tty_config.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 23:00:03 by lpaulo-m          #+#    #+#             */
/*   Updated: 2020/12/26 01:36:37 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/kilo.h"

void	tty_disable_raw_mode(void)
{
	char has_error;

	has_error = tcsetattr(STDIN_FILENO, TCSAFLUSH, &s_original_tty_attributes);
	if (has_error == -1)
		die("`tcsetattr` couldn't restore original tty attributes");
}

void	tty_enable_raw_mode(void)
{
	char has_error;

	has_error = tcgetattr(STDIN_FILENO, &s_original_tty_attributes);
	if (has_error == -1)
		die("`tcgetattr` couldn't fetch original tty attributes");
	atexit(tty_disable_raw_mode);
	s_raw_tty_attributes = s_original_tty_attributes;
	s_raw_tty_attributes.c_iflag &= ~(BRKINT | ICRNL | INPCK | ISTRIP | IXON);
	s_raw_tty_attributes.c_oflag &= ~(OPOST);
	s_raw_tty_attributes.c_cflag |= (CS8);
	s_raw_tty_attributes.c_lflag &= ~(ECHO | ICANON | ISIG | IEXTEN);
	s_raw_tty_attributes.c_cc[VMIN] = 0;
	s_raw_tty_attributes.c_cc[VTIME] = 1;
	has_error = tcsetattr(STDIN_FILENO, TCSAFLUSH, &s_raw_tty_attributes);
	if (has_error == -1)
		die("`tcsetattr` couldn't set raw mode tty attributes");
}
