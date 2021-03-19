/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrosario <mrosario@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 12:32:03 by mrosario          #+#    #+#             */
/*   Updated: 2021/03/19 12:37:14 by mrosario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testeditor.h"

int		disable_raw_mode(t_testeditor *testeditor)
{
	if (tcsetattr(STDIN_FILENO, TCSAFLUSH, &testeditor->orig_term) == -1)
	{
		perror("tcsetattr");
		exit(EXIT_FAILURE);
	}
	
	return (0);
}

void	exit_failure(const char *s, t_testeditor *testeditor)
{
	perror(s);
	disable_raw_mode(testeditor);
	exit(EXIT_FAILURE);
}


void	enable_raw_mode(t_testeditor *testeditor)
{
	
	if (tcgetattr(STDIN_FILENO, &testeditor->term) == -1)
		exit_failure("tcgetattr", testeditor);
	testeditor->orig_term = testeditor->term;
	testeditor->term.c_iflag &= ~(BRKINT | ICRNL | INPCK | ISTRIP | IXON);
	testeditor->term.c_oflag &= ~(OPOST);
	testeditor->term.c_cflag |= CS8;
	testeditor->term.c_lflag &= ~(ECHO | ICANON | IEXTEN | ISIG);
	testeditor->term.c_cc[VMIN] = 0;
	testeditor->term.c_cc[VTIME] = 1;
	if (tcsetattr(STDIN_FILENO, TCSAFLUSH, &testeditor->term) == -1)
		exit_failure("tcsetattr", testeditor);
}