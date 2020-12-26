/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kilo.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaulo-m <lpaulo-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 13:24:53 by lpaulo-m          #+#    #+#             */
/*   Updated: 2020/12/26 15:09:15 by lpaulo-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KILO_H
# define KILO_H

# define CONTROL_Q 17

# include <ctype.h>
# include <errno.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/ioctl.h>
# include <termios.h>
# include <unistd.h>

struct	s_editor_config {
	struct termios	original_tty_flags;
	int				tty_rows;
	int				tty_columns;
};
struct s_editor_config g_config;

void	die(const char *error_message);

void	tty_disable_raw_mode(void);
void	tty_enable_raw_mode(void);
int		set_window_size(int *row_count, int *column_count);

void	clear_screen(void);
void	reset_cursor(void);
void	clear_tty(void);

char	control_(char character);
void	editor_refresh_screen(void);

void	initialize_editor(void);
char	editor_read_key(void);
void	editor_process_keypresses(void);

#endif
