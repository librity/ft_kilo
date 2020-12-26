/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kilo.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 13:24:53 by lpaulo-m          #+#    #+#             */
/*   Updated: 2020/12/25 23:35:24 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KILO_H
# define KILO_H

# include <ctype.h>
# include <stdio.h>
# include <stdlib.h>
# include <termios.h>
# include <unistd.h>

struct termios s_original_tty_attributes;

void	tty_disable_raw_mode(void);
void	tty_enable_raw_mode(void);

#endif
