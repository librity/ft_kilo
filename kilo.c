/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kilo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 16:50:03 by lpaulo-m          #+#    #+#             */
/*   Updated: 2020/12/25 23:34:43 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "kilo.h"

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
