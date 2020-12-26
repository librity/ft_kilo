/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kilo.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 13:24:53 by lpaulo-m          #+#    #+#             */
/*   Updated: 2020/12/26 01:26:04 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KILO_H
# define KILO_H

# include <ctype.h>
# include <errno.h>
# include <stdio.h>
# include <stdlib.h>
# include <termios.h>
# include <unistd.h>

struct termios s_original_tty_attributes;
struct termios s_raw_tty_attributes;

void	die(const char *error_message);

void	tty_disable_raw_mode(void);
void	tty_enable_raw_mode(void);

char	control_(char character);

#endif
