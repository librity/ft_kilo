/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tty_config.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/25 23:00:03 by lpaulo-m          #+#    #+#             */
/*   Updated: 2020/12/25 23:36:34 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "kilo.h"

void	tty_disable_raw_mode(void)
{
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &s_original_tty_attributes);
}

void	tty_enable_raw_mode(void)
{
	struct termios s_raw_tty_attributes;

	tcgetattr(STDIN_FILENO, &s_original_tty_attributes);
	atexit(tty_disable_raw_mode);
	s_raw_tty_attributes = s_original_tty_attributes;
	s_raw_tty_attributes.c_lflag &= ~(ECHO | ICANON);
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &s_raw_tty_attributes);
}
