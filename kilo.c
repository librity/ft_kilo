/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kilo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis.geniole <luis.geniole@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 16:50:03 by luis.geniol       #+#    #+#             */
/*   Updated: 2020/11/10 23:30:42 by luis.geniol      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>

struct termios s_original_tty_attributes;

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

int	main(void)
{
	char input;

	tty_enable_raw_mode();
	while (read(STDIN_FILENO, &input, 1) == 1 && input != 'q')
	{
		if (iscntrl(input))
		{
			printf("%d\n", input);
		}
		else
		{
			printf("%d ('%c')\n", input, input);
		}
	}
	return (0);
}
