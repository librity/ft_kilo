/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kilo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 16:50:03 by lpaulo-m          #+#    #+#             */
/*   Updated: 2020/12/26 01:39:03 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/kilo.h"

int		main(void)
{
	char input;
	char has_error;

	tty_enable_raw_mode();
	while (1)
	{
		input = '\0';
		has_error = read(STDIN_FILENO, &input, 1);
		if (has_error == -1 && errno != EAGAIN)
			die("`read` couldn't read next input character");
		if (iscntrl(input))
			printf("%d\r\n", input);
		else
			printf("%d ('%c')\r\n", input, input);
		if (input == control_('q'))
			break ;
	}
	return (0);
}
